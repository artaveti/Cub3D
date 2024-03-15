#include "cub3d.h"

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
                ft_put_error("Error: Invalid map symbol\n");
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
        ft_put_error("Error: ");
        if (player_count == 0)
            ft_put_error("Player position not found\n");
        else
            ft_put_error("Multiple player positions found\n");
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
            //printf("I:[%d] J:[%d]\n", i, j);
            if (is_pl_pos(Game->map[i][j]))
            {
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
            printf("Error: Invalid symbol found: %c\n in line [%s]\n", line[i], line);
            //system("leaks cub3D");
            exit(1);
          //  return 1; // Invalid symbol found
        }
        i++;
    }
    return 0; // No invalid symbols found
}

