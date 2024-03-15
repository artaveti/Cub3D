#include "cub3d.h"

int is_valid_symbol(char c)
{
    char *valid_symbols;
    int num_symbols;
    int i;
    
    valid_symbols = " NSWE10\n\r\f\v\t";
    num_symbols = ft_strlen(valid_symbols);
    i = 0;
    while(i < num_symbols)
	{
		if (c == valid_symbols[i])
			return 1;
		++i;
	}
    return 0;
}

int empty_line(char *line) 
{
    while (*line != '\0')
    {
        if (*line != ' ' && *line != '\t' && *line != '\n')
            return 0; // Not an empty line
        line++;
    }
    return 1; // Empty line
}

int ft_line_contains_map_data(t_game *Game, int i)
{
    int j;

	j = 0;
	while(j < Game->width)
	{           
		if (Game->map[i][j] == '1' || is_pl_pos(Game->map[i][j])
			|| Game->map[i][j] == '0')
        return 1;
		j++;
	}
	return 0;
}

void ft_for_map_in_the_end_check_assign(int *i, int *prev_map_start)
{
	if (*i - *prev_map_start != 1)
    {
		ft_put_error("Error: Map is disconnected\n");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
    *prev_map_start = *i; 
    return ;
}

void map_in_the_end(t_game *Game)
{
    int map_started;
    int prev_map_start;
    int line_contains_map_data;
    int i;
    
    map_started = 0;
    prev_map_start = -1;
    i = 0;
    while(i < Game->height)
	{
		line_contains_map_data = ft_line_contains_map_data(Game, i);
        if (line_contains_map_data && !empty_line(Game->map[i]))
        {
            if (!map_started)
            {
                //printf("MAP STARTED in line %d\n", i);
                map_started = 1;
                prev_map_start = i; 
            }
            else
				ft_for_map_in_the_end_check_assign(&i, &prev_map_start);
    	}
    	i++;
	}
    return ;
}

void ft_for_ft_check_map_check(t_game *Game, int i, int j)
{
	if ((i == 0 || j == 0 || i == Game->height - 1
		|| j == Game->width - 1)
		&& (Game->map[i][j] == '0'
		|| is_pl_pos(Game->map[i][j])))
    {
		ft_put_error("Error: Map is not closed\n");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
    return ;
}

void ft_check_map(t_game *Game)
{
    int i;
    int j;

    i = 0;
    //printf("Checking map\n");
    fix_player_pos(Game);
    map_in_the_end(Game); //check if map is in the end
    while (i < Game->height)
    {
        j = 0;
        while (j < Game->width)
        {
			ft_for_ft_check_map_check(Game, i, j);
            if (Game->map[i][j] == ' ' || Game->map[i][j] == '\0'
            	|| Game->map[i][j] == '\n' || Game->map[i][j] == '\t')
                check_borders(Game, i, j);
            j++;
        }
        i++;
    }
    return ;
}

