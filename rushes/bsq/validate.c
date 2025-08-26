#include "bsq.h"

void	parse_meta(t_var *data)
{
	char	*meta;
	int		i;

	if (data->rows < 2)
		return (error_exit(data, "map error"));
	meta = data->map[0];
	if (ft_atoi(meta) != data->rows - 1)
		return (error_exit(data, "map error"));
	i = 0;
	while (meta[i] && (meta[i] >= '0' && meta[i] <= '9'))
		i++;
	if (ft_strlen(meta + i) != 3)
		return (error_exit(data, "map error"));
	data->empty_c = meta[i];
	data->obstacle_c = meta[i + 1];
	data->full_c = meta[i + 2];
	if (data->empty_c == data->obstacle_c || data->empty_c == data->full_c
		|| data->obstacle_c == data->full_c)
		return (error_exit(data, "map error"));

}

void	validate_data(t_var *data)
{
	parse_meta(data);

}