/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:32:42 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:34:23 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int main(void)
// {
// 	printf("ft= %i;\torig= %f\n", ft_iterative_power(0, 0), pow(0.0, 0.0));
// 	printf("ft= %i;\n", ft_iterative_power(42, -1));
// 	printf("ft= %i;\torig= %f\n", ft_iterative_power(42, 0), pow(42.0, 0.0));
// 	printf("ft= %i;\torig= %f\n", ft_iterative_power(42, 2), pow(42.0, 2.0));
// 	return (0);
// }