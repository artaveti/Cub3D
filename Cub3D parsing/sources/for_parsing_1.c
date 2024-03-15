#include "cub3d.h"

void free_map(t_game *Game)
{
    int i;

    i = 0;
    if (!Game->map)
        return ;
    if (Game->map != NULL)
    {
        while (i < Game->height)
        {
            free(Game->map[i]);
            i++;
        }
        free(Game->map);
    }
}

void get_map_size(int fd, t_game *Game)
{
    int max_width = 0;
    int line_len = 0;
    char *line = NULL;

    while ((line = get_next_line(fd)) != NULL)
    {
        Game->height++;  
        line_len = ft_strlen(line);
        if (line_len > max_width)
        {
            max_width = line_len;
            Game->width = max_width; 
        }
        free(line);
    }
}

void allocate_map_memory(t_game *Game)
{
    Game->map = (char **)ft_calloc(Game->height, sizeof(char *));
    if (Game->map == NULL) 
    {
        ft_put_error("Error: Memory allocation failed");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
}

void check_map_size(t_game *Game)
{
   if (Game->height < 3 || Game->width < 2)
     {
            ft_put_error("Error: Invalid map size\n");
            //system("leaks cub3D");
            exit(EXIT_FAILURE);
     }
}

void ft_get_map(char *argv, t_game *Game)
{
    int fd;
    int map_start;
    char *line;

    line = NULL;
    map_start = 0;
    init_attributes(Game);
    check_file_exists(argv, &fd);
    pars_attributes(Game, fd, &map_start);
    get_map_size(fd, Game);
    close(fd); 
    allocate_map_memory(Game);
    fd = open(argv, O_RDONLY);
    check_file_exists(argv, &fd);
    while ((line = get_next_line(fd)) && map_start > 1)
    {
        free(line); // Skipping attribute lines
        map_start--;
    }
    copy_map_lines(fd, Game);
    close(fd);
}

