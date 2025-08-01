/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:47:40 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:38:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("value = %i;\tres = %i;\n", 31, ft_find_next_prime(31));
// 	printf("value = %i;\tres = %i;\n", -42, ft_find_next_prime(-42));
// 	printf("value = %i;\tres = %i;\n", 5, ft_find_next_prime(5));
// 	printf("value = %i;\tres = %i;\n", 1, ft_find_next_prime(1));
// 	printf("value = %i;\tres = %i;\n", INT_MIN, ft_find_next_prime(INT_MIN));
// 	printf("value = %i;\tres = %i;\n", INT_MAX, ft_find_next_prime(INT_MAX));
// 	printf("value = %i;\tres = %i;\n",
// 		2147395600, ft_find_next_prime(2147395600));
// 	return (0);
// }