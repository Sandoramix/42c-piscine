/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:37:46 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:38:03 by odudniak         ###   ########.fr       */
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

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("value = %i;\tresult = %i;\n", 31, ft_is_prime(31));
// 	printf("value = %i;\tresult = %i;\n", -42, ft_is_prime(-42));
// 	printf("value = %i;\tresult = %i;\n", 5, ft_is_prime(5));
// 	printf("value = %i;\tresult = %i;\n", 1, ft_is_prime(1));
// 	printf("value = %i;\tresult = %i;\n", INT_MIN, ft_is_prime(INT_MIN));
// 	printf("value = %i;\tresult = %i;\n", INT_MAX, ft_is_prime(INT_MAX));
// 	printf("value = %i;\tresult = %i;\n", 2147395600, ft_is_prime(2147395600));
// 	return (0);
// }