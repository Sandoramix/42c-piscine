#ifndef BSQ_H
# define BSQ_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

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

void	bsq(int fd);
void	convert_raw_input_to_map(t_var *data);
char	*copy_until_newline(const char *s, int *i);
int		count_total_lines(char *raw_input);
void	error_exit(t_var *data, char *msg);
void	free_map(char **map);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2, bool free_s1);
int		ft_strlen(const char *s);
void	parse_meta(t_var *data);
void	print_map(t_var *data);
char	*read_input(int fd);
void	validate_data(t_var *data);

#endif