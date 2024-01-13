/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:13:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/01/13 16:31:54 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>



void	ft_print_c(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (c1 != '7')
		write(1, ", ", 2);
}

/**
 * @brief
 * '0' + 1 = '1' and so on...
 *
 */
void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '9')
	{
		c2 = c1 + 1;
		while (c2 <= '9')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				ft_print_c(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Refactor: all in 1 function
 *
 */
/* void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '9')
	{
		c2 = c1;
		while (++c2 <= '9')
		{
			c3 = c2;
			while (++c3 <= '9')
			{
				write(1, &c1, 1);
				write(1, &c2, 1);
				write(1, &c3, 1);
				if (c1 != '7')
					write(1, ", ", 2);
			}
		}
		c1++;
	}
} */


/* int	main(void)
{
	ft_print_comb();
	return (0);
} */
