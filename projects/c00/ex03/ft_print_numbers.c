/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:22:44 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 11:08:03 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Here you can use the same "dirty" strategy of print_alphabet
// and learn nothing out of it, or you can explore more about how `char` works.

/**
 * @brief This function will print to console every digit (from 0 to 9)
 * In order to do so we cannot directly use `write` on an `int` variable
 * Because it will interpret `int` as a `char` by comparing the decimal
 * occurrence on ascii table.
 * So to be able to print a single digit with `write` you'll have to get
 * ascii table's correspondence of it.
 * Knowing that the char '0' is represented as decimal value 48 and the other
 * digits are consecutive of it, the final conversion is simple.
 */
void	ft_print_numbers(void)
{
	int		i;
	char	digit;

	i = 0;
	while (i < 10)
	{
		digit = i + 48;
		write(1, &digit, 1);
		i = i + 1;
	}
}

// Here are some variations that can be made.

/**
 * Here the difference are two:
 * - Instead of writing 48 we use '0' which is the same
 * - Instead of writing `i = i + 1` we use another annotation.
 */
//void	ft_print_numbers(void)
//{
//	int		i;
//	char	digit;
//
//	i = 0;
//	while (i < 10)
//	{
//		digit = i + '0';
//		write(1, &digit, 1);
//		i++;
//	}
//}

/**
 * Another "trick" is to just use chars from the beginning.
 */
//void	ft_print_numbers(void)
//{
//	char	digit;
//
//	digit = '0';
//	while (digit <= '9')
//	{
//		write(1, &digit, 1);
//		digit++;
//	}
//}

/**
 * Or if you're lazy/know already how to do the while loops
 * then you can skip it like this.
*/
//void	ft_print_numbers(void)
//{
//	write(1, "0123456789", 10);
//}

//int	main(void)
//{
//	ft_print_numbers();
//	return (0);
//}
