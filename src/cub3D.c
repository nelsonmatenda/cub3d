/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:14 by gudos-sa          #+#    #+#             */
/*   Updated: 2025/04/07 10:08:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_get_map_e_config(char **file_content, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->map.configs = NULL;
	game->map.content = NULL;
	while (file_content[i] != NULL)
	{
		if (ft_strlen(file_content[i]) && j < 6)
		{
			game->map.configs = ft_append_line(game->map.configs,
					file_content[i]);
			j++;
		}
		else if (j == 6)
		{
			if (game->map.content != NULL || ft_strlen(file_content[i]))
				game->map.content = ft_append_line(game->map.content,
						file_content[i]);
		}
		i++;
	}
}

char	**ft_split_v2(char *str, char c)
{
	int		i;
	int		separate;
	char	*word;
	char	**list_word;

	i = 0;
	separate = 1;
	word = NULL;
	list_word = NULL;
	while (*str != '\0' && (*str == 32 || *str == 9))
		str++;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word = ft_append_character(word, str[i]);
			separate = 0;
		}
		else if (!separate)
		{
			list_word = ft_append_line(list_word, word);
			word = NULL;
			separate = 1;
		}
		i++;
	}
	if (word != NULL)
		list_word = ft_append_line(list_word, word);
	return (list_word);
}

void ft_set_texture(t_game *game, char *key_config, char *path)
{
	if (ft_strncmp(key_config, "NO", 2) == 0 && key_config[2] == '\0')
		game->map.no = ft_strdup(path);
	else if(ft_strncmp(key_config, "SO", 2) == 0 && key_config[2] == '\0')
		game->map.so = ft_strdup(path);
	else if(ft_strncmp(key_config, "WE", 2) == 0 && key_config[2] == '\0')
		game->map.we = ft_strdup(path);
	else if(ft_strncmp(key_config, "EA", 2) == 0 && key_config[2] == '\0')
		game->map.ea = ft_strdup(path);
	else
		ft_error("Invalid key config");
}

void ft_parse_rgb(char *rgb, int *r, int *g, int *b)
{
	char **parts;
	parts = ft_split(rgb, ',');
	int i = 0;
	while (parts[i] != NULL)
	{
		printf("i: %d; value: %s\n", i, parts[i]);
		i++;
	}
	printf("SAIU\n");
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		ft_error("Invalid rgb declaration!");
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	if (*r < 0 || *r > 255)
		ft_error("rgb, r value out of range");
	if (*g < 0 || *g > 255)
		ft_error("rgb, g value out of range");
	if (*b < 0 || *b > 255)
		ft_error("rgb, b value out of range");
}

void ft_set_color(t_game *game, char *key_config, char *rgb)
{
	int r;
	int g;
	int b;

	ft_parse_rgb(rgb, &r, &g, &b);
	if (ft_strncmp(key_config, "F", 1) == 0 && key_config[1] == '\0')
	{
		game->map.f.r = r;
		game->map.f.g = g;
		game->map.f.b = b;
	}
	else if(ft_strncmp(key_config, "C", 1) == 0 && key_config[1] == '\0')
	{
		game->map.c.r = r;
		game->map.c.g = g;
		game->map.c.b = b;
	}
	else
		ft_error("Invalid key config");
}

void ft_parse_config_line(t_game *game)
{
	int i;
	char **parts;

	i = 0;
	while (game->map.configs[i] != NULL)
	{
		parts = ft_split_v2(game->map.configs[i], ' ');
		if (!parts || !parts[0] || !parts[1])
			ft_error("Invalid config line!");
		if (ft_strlen(parts[0]) == 2)
			ft_set_texture(game, parts[0], parts[1]);
		else if(ft_strlen(parts[0]) == 1)
			ft_set_color(game, parts[0], parts[1]);
		else
			ft_error("Invalid key config");
		i++;
	}
	if (i != 6)
		ft_error("Invalid number of configuration lines");
}

void	ft_process_map(char **file_content, t_game *game)
{
	ft_get_map_e_config(file_content, game);
	ft_parse_config_line(game);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**file_content;

	file_content = NULL;
	if (ac != 2)
		return (ft_exit(NULL, MAP_ERR, \
						"Theres no maps: Try > ./cub3d maps/default.cub"), 1);
	ft_read_file(av[1], &file_content);
	ft_process_map(file_content, &game);
	
		printf("no: %s\n", game.map.no);
		printf("so: %s\n", game.map.no);
		printf("we: %s\n", game.map.no);
		printf("ea: %s\n", game.map.no);
		printf("f: %d,%d,%d\n", game.map.c.r, game.map.c.g, game.map.c.b);
		printf("c: %d,%d,%d\n", game.map.c.r, game.map.c.g, game.map.c.b);
	return (0);
}
