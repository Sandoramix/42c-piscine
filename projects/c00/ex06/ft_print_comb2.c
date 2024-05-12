/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:58:57 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 11:37:40 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put2digit(int n)
{
	char	d1;
	char	d2;

	d1 = n / 10 + '0';
	d2 = n % 10 + '0';
	write(STDOUT_FILENO, &d1, 1);
	write(STDOUT_FILENO, &d2, 1);
}

void	print_both_numbers(int n1, int n2)
{
	ft_put2digit(n1);
	write(STDOUT_FILENO, " ", 1);
	ft_put2digit(n2);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	while (n1 < 99)
	{
		n2 = n1 + 1;
		if (n1 != 0 || n2 != 1)
			write(STDOUT_FILENO, ", ", 2);
		print_both_numbers(n1, n2);
		n2++;
		while (n2 < 100)
		{
			write(STDOUT_FILENO, ", ", 2);
			print_both_numbers(n1, n2);
			n2++;
		}
		n1++;
	}
}
