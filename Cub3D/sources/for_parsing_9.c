#include "lib_for_cub3D.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

void check_map_sym(t_game *Game)
{
    int i;
    int j;

    i = 0;
    while (i < Game->height)
    {
        j = 0;
        while (j < Game->width)
        {
            if (Game->map[i][j] != '0' && Game->map[i][j] != '1'
				&& !is_space(Game->map[i][j])
				&& !is_pl_pos(Game->map[i][j]))
            {
                ft_put_error("Error: Invalid map symbol");
                //system("leaks cub3D");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
    return ;
}

void check_player_count(int player_count)
{
    if (player_count != 1)
    {
        if (player_count == 0)
            ft_put_error("Error: Player position not found");
        else
            ft_put_error("Error: Multiple player positions found");
        //system("leaks cub3D");
        exit(EXIT_FAILURE);
    }
    return ;
}

void fix_player_pos(t_game *Game)
{
    int i;
    int j;
    int player_count;

    i = 0;
    player_count = 0;
    while (i < Game->height)
    {
        j = 0;
        while (j < Game->width)
        {
            if (is_pl_pos(Game->map[i][j]))
            {
                Game->attr.direction_angle[0] = Game->map[i][j];
                player_count++;
                Game->player.x = i;
                Game->player.y = j;
            }
            j++;
        }
        i++;
    }
    check_player_count(player_count);
    return ;
}

int inv_sym(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (!is_space(line[i]) && !is_valid_symbol(line[i]))
        {
            printf("Error: Invalid symbol found: %c\n", line[i]);
            //system("leaks cub3D");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return (0);
}
