/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:32:26 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:34:42 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int a, char **av)
// {
// 	if (a < 2)
// 		return (1);
// 	printf("%d", ft_iterative_factorial(atoi(av[1])));
// 	return (0);
// }