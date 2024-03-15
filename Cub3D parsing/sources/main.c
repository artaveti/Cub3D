#include "cub3d.h"

// check, sometimes show "Error: map is not closed"
// 111
// 1N1
// 111

// it's show "MAP IS VALID"
// 111
// 1N1
// 111(space)

// 11111111111110
// 1N000000011
// 11111111111

// 11111111111110
// 1N000000011(space)(space)
// 11111111111

// 111111111111111N  //Error:Player position not found
// 101010001
// 11111111111111
// 11111111  

// 1111111111111111W  //W
// 1010100N11
// 11111111111111
// 11111111  

// 1111111111111111
// 1010100N11
// 11111111111111
// 11111111E  //E


//ft_put_error("Error: Map is not closed\n");
//ft_put_error("Error: map is not closed");

int main(int argc, char **argv) 
{
   t_game Game;

    ft_check_argc_and_name(argc, argv);
    ft_get_map(argv[1], &Game);
    check_attr_count(&Game);
    check_attr_identif(&Game);
    ft_check_map(&Game);
    
// print_attributes(&Game);
// ft_print_map(&Game);
// printf("MAP IS VALID\n");
// printf("Player position: %d %d\n", Game.player.x, Game.player.y);
// printf("height:(%d)\nwidth:(%d)\n", Game.height, Game.width);
// printf("NO:(%s)\n", Game.attr.no);
// printf("SO:(%s)\n", Game.attr.so);
// printf("EA:(%s)\n", Game.attr.ea);
// printf("WE:(%s)\n", Game.attr.we);
// printf("F:(%s)\n", Game.attr.f);
// printf("C:(%s)\n", Game.attr.c);
// printf("MAP_X:(%d)\n", Game.map_x);
// printf("MAP_X:(%d)\n", Game.map_y);

//system("leaks cub3D");
    free_map(&Game);
    free_attributes(&Game);
    exit(EXIT_SUCCESS);
}

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*space;

	if (count == 0 || size == 0)
	{
		space = malloc(count * size);
		if (!space)
			return (0);
		return (space);
	}
	if (count > SIZE_MAX / size)
		return (0);
	space = malloc(count * size);
	if (!space)
		return (0);
	else
		ft_memset(space, '\0', count * size);
	return (space);
}

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mas;

	mas = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		mas[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
