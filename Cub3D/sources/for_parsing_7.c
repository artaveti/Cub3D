#include "lib_for_cub3D.h"

int is_valid(int row, int col, t_game *Game)
{
    return (row >= 0 && row < Game->height && col >= 0 && col < Game->width);
}

int is_pl_pos(char c)
{
    return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void ft_for_check_borders_check(t_game *Game, int new_ind, int new_jind)
{
	if (is_valid(new_ind, new_jind, Game)
		&& (Game->map[new_ind][new_jind] == '0'
        || is_pl_pos(Game->map[new_ind][new_jind])))
    {
        ft_put_error("Error: Map is not closed");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
    return ;
}

void assign_direct(int **moves)
{
    moves[0][0] = -1; 
    moves[0][1] = 0;   // Up
    moves[1][0] = -1; 
    moves[1][1] = -1;  // Up-Left
    moves[2][0] = -1; 
    moves[2][1] = 1;   // Up-Right
    moves[3][0] = 1;  
    moves[3][1] = 0;   // Down
    moves[4][0] = 1;  
    moves[4][1] = -1;  // Down-Left
    moves[5][0] = 1;  
    moves[5][1] = 1;   // Down-Right
    moves[6][0] = 0;  
    moves[6][1] = -1;  // Left
    moves[7][0] = 0;  
    moves[7][1] = 1;   // Right
}

void free_arr(int **arr)
{
    int i;

    i = 0;
    while (i < 8)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

