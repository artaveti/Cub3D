#include "lib_for_cub3D.h"

void check_borders(t_game *Game, int ind, int jind)
{
    int **moves;
    int i;
    int new_ind;
    int new_jind;

    i = 0;
    moves = malloc(8 * sizeof(int *));
    while(i < 8) 
    {
        moves[i] = malloc(2 * sizeof(int));
        i++;
    }
    assign_direct(moves);
    i = 0;
    while (i < 8)
    {
        new_ind = ind + moves[i][0];
        new_jind = jind + moves[i][1];
    	ft_for_check_borders_check(Game, new_ind, new_jind);
    	i++;
    }
    free_arr(moves);
	return ;  
}

void ft_print_map(t_game *Game) 
{
    int i;

    i = 0;
    printf("Printing map\n");
    while (i < Game->height)
    {
        printf("I:[%d] (%s)",i, Game->map[i]);
        i++;
    }
    printf("\n");
    printf("Height: %d\n", Game->height);
    printf("Width: %d\n", Game->width);
}

void ft_for_ft_check_map_check(t_game *Game, int i, int j)
{
	if ((i == 0 || j == 0 || i == Game->height - 1
		|| j == Game->width - 1)
		&& (Game->map[i][j] == '0'
		|| is_pl_pos(Game->map[i][j])))
    {
		ft_put_error("Error: Map is not closed");
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

int		check_char(char c, const char *charset)
{
	int		i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}