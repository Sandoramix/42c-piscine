/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:13:33 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 11:02:21 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

/**
 * Recursive way.
 * <b>long n</b> is used here
 * because the INT_MIN (-2147483648) multiplied by -1 makes the `int` overflow
 * and turns into a `0`
*/
void	ft_putnbr(int nb)
{
	long	n;
	char	c;

	n = nb;
	if (nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(STDOUT_FILENO, &c, 1);
}

/**
 * Iterative way.
 * `ft_abs` is used for not using the `long` variable.
 * It is "safe" because it's used only on the `nb % 10` part which will always
 * be (0 >= x < 10)
*/
//int	ft_abs(int n)
//{
//	if (n < 0)
//		return (n * -1);
//	return (n);
//}

/**
 * Iterative way.
 * A temporary array of chars `res` is made. It's not a C-standard string
 * because i did not include space for the final \0 character.
 * By using `write` and a known length to print, I can print the `res` content
 * without accessing other variables' memory.
*/
//void	ft_putnbr(int nb)
//{
//	char	res[11];
//	int		i;
//	int		negative;

//	if (nb == 0)
//	{
//		write(1, "0", 1);
//		return ;
//	}
//	negative = 0;
//	if (nb < 0)
//		negative = 1;
//	i = 11;
//	while (nb != 0)
//	{
//		i--;
//		res[i] = ft_abs(nb % 10) + '0';
//		nb = nb / 10;
//	}
//	if (negative == 1)
//		res[--i] = '-';
//	write(1, res + i, 11 - (i + 1));
//}

//int	main(void)
//{
//	ft_putnbr(INT_MIN);
//	write(1, "\n", 1);
//	ft_putnbr(INT_MAX);
//	write(1, "\n", 1);
//	ft_putnbr(0);
//	write(1, "\n", 1);
//	return (0);
//}
