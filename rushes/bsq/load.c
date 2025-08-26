#include "bsq.h"

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

int	count_total_lines(char *raw_input)
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
		return (-1);
	return (rows);
}

char	*copy_until_newline(const char *s, int *i)
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

void	convert_raw_input_to_map(t_var *data)
{
	int		i;
	int		map_i;

	if (!data->raw_input)
		return (error_exit(data, "map error"));
	data->rows = count_total_lines(data->raw_input);
	if (data->rows <= 1)
		return (error_exit(data, "map error"));
	data->map = malloc((data->rows + 1) * sizeof(char *));
	if (!data->map)
		return (error_exit(data, "map error"));
	data->map[data->rows] = NULL;
	i = -1;
	while (data->raw_input[++i])
	{
		data->map[map_i] = copy_until_newline(data->raw_input, &i);
		if (!data->map[map_i])
			return (error_exit(data, "map error"));
		map_i++;
	}
}
