#include "lib_for_cub3D.h"

int ft_for_check_color_one(size_t length, char *color)
{
	if (color[length - 1] == ',')
    {
        free(color);
        return 0;
    }
    return 1;
}

int ft_for_check_color_two(int counter, char *color)
{
	if (counter != 3)
    {
        free(color);
        return 0;
    }
    free(color);
    return 1;
}

int check_color_f(char *line) 
{
    char *token;
    char *color;
    size_t length;
    int counter;

    counter = 0;
    color = ft_strdup(line);
    //printf("LINE:(%s)\n", line);
    length = ft_strlen(color);
    //system("leaks cub3D");
    token = my_strtok_f(color, ",");
    if(ft_for_check_color_one(length, color) == 0)
    	return 0;
    while (token != NULL)
    {
        if (invalid_color(token))
        {
            free(color);
            return 0;
        }
        token = my_strtok_f(NULL, ",");
        counter++;
    }
    return ft_for_check_color_two(counter, color);
}

int check_color_c(char *line) 
{
    char *token;
    char *color;
    size_t length;
    int counter;

    counter = 0;
    color = ft_strdup(line);
    //printf("LINE:(%s)\n", line);
    length = ft_strlen(color);
    //system("leaks cub3D");
    token = my_strtok_c(color, ",");
    if(ft_for_check_color_one(length, color) == 0)
    	return 0;
    while (token != NULL)
    {
        if (invalid_color(token))
        {
            free(color);
            return 0;
        }
        token = my_strtok_c(NULL, ",");
        counter++;
    }
    return ft_for_check_color_two(counter, color);
}

void check_attr_identif(t_game *Game)
{
    (void)Game;
    if (!check_color_f(Game->attr.f))
    {
        ft_put_error("Invalid color");
        //system("leaks cub3D");
        // free_map(Game);
        // free_attributes(Game);
        exit(1);
    }
    else if (!check_color_c(Game->attr.c))
    {
        ft_put_error("Invalid color");
        //system("leaks cub3D");
        // free_map(Game);
        // free_attributes(Game);
        exit(1);
    }

    // Check other attribute paths like 'no', 'so', 'ea', 'we'
    // If they are not valid or don't end with '.xpm', exit(1)

    return ;
}
