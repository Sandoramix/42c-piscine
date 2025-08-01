/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:32:17 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:34:32 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int a, char **av)
// {
// 	if (a < 2)
// 		return (1);
// 	printf("%d", ft_recursive_factorial(atoi(av[1])));
// 	return (0);
// }