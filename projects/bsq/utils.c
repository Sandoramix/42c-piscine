
#include "bsq.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	if (!str)
		return (0);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

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
