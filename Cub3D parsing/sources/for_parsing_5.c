#include "cub3d.h"

void check_attr_count(t_game *Game)
{
  if (Game->attr.count.f_count != 1 || Game->attr.count.c_count != 1 )
    {
        ft_put_error("Error: ivalid count F || C \n");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
    if (!(Game->attr.count.no_count >= 1
     && Game->attr.count.so_count  >= 1 && Game->attr.count.we_count  >= 1 &&
            Game->attr.count.ea_count  >= 1))
            {
                ft_put_error("Error: ivalid count NO || SO || WE || EA \n");
                //system("leaks cub3D");
                exit(EXIT_FAILURE);
            }
    
//    return (Game->attr.count.no_count >= 1
//      && Game->attr.count.so_count  >= 1 && Game->attr.count.we_count  >= 1 &&
//             Game->attr.count.ea_count  >= 1);
}

int is_attr(char *line)
{
  if (ft_strlen(line) < 2 && (line[0] != 'F' && line[0] != 'C')) 
        return 0;
    if ((ft_strncmp(line, "NO", ft_strlen(line)) == 0 )||
        ft_strncmp(line, "SO", ft_strlen(line)) == 0 ||
        ft_strncmp(line, "WE", ft_strlen(line)) == 0 ||
        ft_strncmp(line, "EA", ft_strlen(line)) == 0 ||
        ft_strncmp(line, "F", ft_strlen(line)) == 0 ||
        ft_strncmp(line, "C", ft_strlen(line)) == 0)
                return 1;
    return 0;
}

void init_attributes(t_game *Game)
{
    Game->attr_line = 0;
    Game->height = 1;
    Game->width = 0;
    Game->attr.count.no_count = 0;
    Game->attr.count.so_count = 0;
    Game->attr.count.we_count = 0;
    Game->attr.count.ea_count = 0;
    Game->attr.count.f_count = 0;
    Game->attr.count.c_count = 0;
    Game->attr.attr_count = 0;
    Game->attr.so = NULL;
    Game->attr.we = NULL;
    Game->attr.no = NULL;
    Game->attr.ea = NULL;
    Game->attr.f = NULL;
    Game->attr.c = NULL;
}

void pars_attributes(t_game *Game, int fd, int *map_start)
{
    char *line;

    while ((line = get_next_line(fd)))
    {   
        if (is_attribute(Game, line))
        {
            free(line);
            (*map_start)++;
        } 
        else
        {
            free(line);
            break;
        }
    }
    if (!line)
        {
            free(line);
            ft_put_error("Error: Map is empty\n");
            //system("leaks cub3D");
            exit(EXIT_FAILURE);
        }
}

void free_attributes(t_game *Game)
{
    free(Game->attr.so);
    free(Game->attr.we);
    free(Game->attr.no);
    free(Game->attr.ea);
    free(Game->attr.f);
    free(Game->attr.c);
}

