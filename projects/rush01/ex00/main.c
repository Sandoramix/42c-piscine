/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:32:52 by odudniak          #+#    #+#             */
/*   Updated: 2025/07/31 08:50:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int	ft_sqrt(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

void	print_map(int *map, int size)
{
	int	i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (j > 0)
				write(1, " ", 1);
			write(1, &map[i * size + j] + '0', 1);
		}
		write(1, "\n", 1);
	}
}

int	count_map_size(char *input)
{
	int	i;
	int	size;
	int	squared;

	i = -1;
	size = 0;
	while (input[++i] != '\0')
	{
		if (i % 2 != 0)
			continue ;
		if (input[i] < '0' || input[i] > '9')
			return (-1);
		size++;
	}
	squared = ft_sqrt(size);
	if (squared * squared != size)
		return (-1);
	return (size);
}

int	*generate_map_and_infomap(char *input, int size, int **map, int **infomap)
{
	int	i;
	int	m_idx;

	*map = malloc(size * sizeof(int));
	if (!(*map))
		return (NULL);
	*infomap = malloc(size * sizeof(int));
	if (!(*infomap))
		return (free(*map), NULL);
	i = -1;
	m_idx = 0;
	while (input[++i] != '\0')
	{
		if (i % 2 != 0)
			continue ;
		(*infomap)[m_idx] = input[i] - '0';
		(*map)[m_idx] = 0;
		m_idx++;
	}
	return (*map);
}

int	main(int argc, char **argv)
{
	int		map_size;
	int		*plain_map;
	int		*infomap;

	if (argc != 2)
		return (write(2, "Usage: ./rush01 \"input\"\n", 24), 1);
	map_size = count_map_size(argv[1]);
	if (map_size == -1)
		return (write(2, "Invalid input\n", 13), 1);
	if (!generate_map_and_infomap(argv[1], map_size, &plain_map, &infomap))
		return (write(2, "Error: malloc failed\n", 19), 1);
	print_map(plain_map, map_size);
	print_map(infomap, map_size);

	free(plain_map);
	free(infomap);
	return (0);
}

