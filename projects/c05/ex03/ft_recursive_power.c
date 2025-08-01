/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:33:40 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:34:01 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// #include <math.h>

// int main(void)
// {
// 	printf("ft= %i;\torig= %f\n", ft_recursive_power(0, 0), pow(0.0, 0.0));
// 	printf("ft= %i;\n", ft_recursive_power(42, -1));
// 	printf("ft= %i;\torig= %f\n", ft_recursive_power(42, 0), pow(42.0, 0.0));
// 	printf("ft= %i;\torig= %f\n", ft_recursive_power(42, 2), pow(42.0, 2.0));
// 	return (0);
// }