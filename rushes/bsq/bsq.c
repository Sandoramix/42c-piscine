#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

/**

The aim of this project is to find the biggest square on a map, avoiding the obstacles.
The first line of the map contains information on how to read the map:
- The number of lines on the map
- The "empty" character
- The "obstacle" character
- The "full" character

The map is made up of "empty" characters, linesand "obstacle" characters.
The aim of the program is to replace "empty" characters by "full" characters in order to represent the buggest square possible.
In case that more than one solution exists, we'll choose to represent the square that's closes to the top of the map, then the one that's most to the left.


Definition of a valid map:
- All lines have the same length
- There's at least one line of at least one box.
- At each end of line there's a line break.
- The characters on the map can only be those introduced in the first line.
- In case of invalid map you program sgould display "map error"  output followed by a line break. Your program will then move to then next map.

- 1-N file parameters; each solution/error separated by newline
- 0 parameters: listen on stdin
- need a Makefile
- can use only: exit, open, close, write, read, malloc and free
*/

// MAP GENERATOR CODE
/*
#!/usr/bin/perl

use warnings;
use strict;

die "program x y density\n" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rany($y) * 2) < $density) {
			print "o";
		}
		else {
			print ".";
		}
	}
	print "\n";
}
*/

typedef struct s_var
{
	char	*raw_input;

	int		rows;
	int		cols;
	char	**map;

	char	empty_c;
	char	obstacle_c;
	char	full_c;
}	t_var;

void	free_map(char **map)
{
	int		i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

//-----------------------------------------------------------------------------
// UTILS
//-----------------------------------------------------------------------------

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, bool free_s1)
{
	const int	s1_len = ft_strlen(s1);
	const int	s2_len = ft_strlen(s2);
	char		*res;
	int			res_i;
	int			i;

	res = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	res_i = 0;
	while (s1 && s1[i])
		res[res_i++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[res_i++] = s2[i++];
	res[res_i] = 0;
	if (free_s1)
		free(s1);
	return (res);
}

//-----------------------------------------------------------------------------

void	error_exit(t_var *data, char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_map(data->map);
	free(data->raw_input);
	exit(1);
}

//-----------------------------------------------------------------------------
// DATA READING

char	*read_input(int fd)
{
	char	buffer[1];
	char	*res;
	int		bytes_read;

	bytes_read = 1;
	res = NULL;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read < 0)
			return (free(res), NULL);
		res = ft_strjoin(res, buffer, true);
	}
	return (res);
}

int	count_raw_input_lines(char *raw_input)
{
	int		rows;
	int		i;
	int		last_new_line_idx;

	if (!raw_input)
		return (0);
	i = -1;
	last_new_line_idx = -1;
	while (raw_input[++i])
	{
		if (raw_input[i] == '\n')
		{
			rows++;
			last_new_line_idx = i;
		}
	}
	if (last_new_line_idx == -1 || i - 1 > last_new_line_idx)
		rows++;
	return (rows);
}

char	*duplicate_until_newline(const char *s, int *i)
{
	char	*res;
	int		res_i;
	int		j;

	j = *i;
	while (s[j] && s[j] != '\n')
		j++;
	res = malloc((j - *i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res_i = 0;
	while (*i < j)
		res[res_i++] = s[(*i)++];
	res[res_i] = 0;
	return (res);
}

bool	convert_raw_input_to_map(t_var *data)
{
	int		i;
	int		map_i;

	if (!data->raw_input)
		return (false);
	data->rows = count_raw_input_lines(data->raw_input);
	if (data->rows == 0)
		return (false);
	data->map = malloc((data->rows + 1) * sizeof(char *));
	if (!data->map)
		return (error_exit(data, "map error"), false);
	data->map[data->rows] = NULL;
	i = -1;
	while (data->raw_input[++i])
	{
		data->map[map_i] = duplicate_until_newline(data->raw_input, &i);
		if (!data->map[map_i])
			return (error_exit(data, "map error"), false);
		map_i++;
	}
	return (true);
}

//-----------------------------------------------------------------------------

void	print_map(t_var *data)
{
	int		i;

	i = -1;
	while (data->map[++i])
		write(1, data->map[i], ft_strlen(data->map[i]));
}

void	bsq(int fd)
{
	t_var	data;

	data.raw_input = read_input(fd);
	if (!data.raw_input)
		return (error_exit(&data, "map error"));
	printf("raw_input: %s\n", data.raw_input);
	if (!convert_raw_input_to_map(&data))
		return (error_exit(&data, "map error"));
	print_map(&data);
}

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	if (ac == 1)
	{
		bsq(0);
		return (0);
	}
	i = 0;
	while (av[++i])
		bsq(open(av[i], O_RDONLY));
	return (0);
}
