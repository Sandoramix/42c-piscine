
#include "bsq.h"

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
- In case of invalid map you program should display "map error"  output followed by a line break. Your program will then move to then next map.

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

void	print_map(t_var *data)
{
	int		i;

	i = -1;
	while (data->map[++i])
	{
		write(1, data->map[i], ft_strlen(data->map[i]));
		write(1, "\n", 1);
	}
}

void	bsq(int fd)
{
	t_var	data;

	data = (t_var){0};
	data.raw_input = read_input(fd);
	convert_raw_input_to_map(&data);
	validate_data(&data);
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
