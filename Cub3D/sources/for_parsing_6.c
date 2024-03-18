#include "lib_for_cub3D.h"

char	*ft_strjoin_n(char *s1, char *s2)
{
    char *joined = ft_strjoin(s1, "\n");
    char *result = ft_strjoin(joined, s2);
    //free(joined);
    return result;
}

void join_attribute_path(char **attribute, char *line, int *count)
{
    char *new_path;
    
    new_path = ft_strjoin_n(*attribute, line);
    *attribute = new_path;
    (*count)++;
}

void assign_path(t_game *Game, char *type, char *path)
{
    if (ft_strncmp(type, "NO", ft_strlen(type)) == 0)
        join_attribute_path(&Game->attr.no, path, &Game->attr.count.no_count);
    else if (ft_strncmp(type, "SO", ft_strlen(type)) == 0)
        join_attribute_path(&Game->attr.so, path, &Game->attr.count.so_count);
    else if (ft_strncmp(type, "WE", ft_strlen(type)) == 0)
        join_attribute_path(&Game->attr.we, path, &Game->attr.count.we_count);
    else if (ft_strncmp(type, "EA", ft_strlen(type)) == 0)
        join_attribute_path(&Game->attr.ea, path, &Game->attr.count.ea_count);
    else if (ft_strncmp(type, "F", ft_strlen(type)) == 0) 
    {
        free(Game->attr.f);
        Game->attr.f = NULL;
        Game->attr.f = ft_strdup(path);
        Game->attr.count.f_count++;
    } 
    else if (ft_strncmp(type, "C", ft_strlen(type)) == 0)
    {
        free(Game->attr.c);
        Game->attr.c = NULL;
        Game->attr.c = ft_strdup(path);
        Game->attr.count.c_count++;
    }
}

void ft_for_is_attribute_check_word_count(int word_count, int num)
{
	if (num == 1)
	{
		if (word_count > 1)
    	{
        	ft_put_error("Error: Invalid attribute: too many arguments for attr");
        	//system("leaks cub3D");
        	exit(EXIT_FAILURE);
    	}
    	return ;
	}
	if (word_count == 1)
	{
		ft_put_error("Error: Attribute identifier missing");
        //system("leaks cub3D");
        exit(1);
	}
	return ;
}

int is_attribute(t_game *Game, char *line)
{
    char *delim;
    char *token;
    char *type;
    int word_count;
    
    delim = " \t\n\v\f\r";
    token = my_strtok(line, delim);
    type = NULL;
    word_count = 0;
    while (token)
    {
        if (word_count == 0)
        {
            if (is_attr(token)) //line starts from attr 
                type = token;
            else
                return 0; //stop attribute parsing, map found
        }
        if (word_count == 1)
            assign_path(Game, type, token);
        ft_for_is_attribute_check_word_count(word_count, 1);
        token = my_strtok(NULL, delim);
        word_count++;
    }
    ft_for_is_attribute_check_word_count(word_count, 2);
    return 1;
}

