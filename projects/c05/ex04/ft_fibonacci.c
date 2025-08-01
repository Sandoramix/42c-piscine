/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:35:28 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:35:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("value= %i;\tresult= %i\n",-1, ft_fibonacci(-1));
// 	printf("value= %i;\tresult= %i\n", 0, ft_fibonacci(0));
// 	printf("value= %i;\tresult= %i\n", 1, ft_fibonacci(1));
// 	printf("value= %i;\tresult= %i\n", 5, ft_fibonacci(5));
// 	printf("value= %i;\tresult= %i\n", 10, ft_fibonacci(10));
// 	return (0);
// }