/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:36:30 by odudniak          #+#    #+#             */
/*   Updated: 2025/08/01 13:36:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <math.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		25, ft_sqrt(25), sqrt(25));
// 	printf("val= %i;\tft=%i;\n",
// 		-42, ft_sqrt(-42));
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		5, ft_sqrt(5), sqrt(5));
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		121, ft_sqrt(121), sqrt(121));
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		INT_MIN, ft_sqrt(INT_MIN), sqrt(INT_MIN));
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		INT_MAX, ft_sqrt(INT_MAX), sqrt(INT_MAX));
// 	printf("val= %i;\tft=%i;\torig= %f\n",
// 		2147395600, ft_sqrt(2147395600), sqrt(2147395600));
// 	return (0);
// }