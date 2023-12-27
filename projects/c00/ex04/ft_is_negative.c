/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:41:57 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/27 00:57:44 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Here we'll learn about conditions.
 * A condition or `if` keyword in C determines whether a piece of code should
 * run or not.
 * A condition uses primarily "logical operator" (google it) which returns two
 * values, `1` (or `true`) when the condition is valid, `0` (or `false`)
 * otherwise.
 * Primary logical operators are:
 * - equal (==)
 * - less than (<) 		; or equal (<=)
 * - greater than (>) 	; or equal (>=)
 */
void	ft_is_negative(int n)
{
	char	negative;
	char	positive;

	negative = 'N';
	positive = 'P';
	if (n < 0)
	{
		write(1, &negative, 1);
	}
	else
	{
		write(1, &positive, 1);
	}
}

// Here is a cleaner solution
// If a keyword like `if` or `while` contains a single operation/line of code
// The brackets can be avoided.
// void	ft_is_negative(int n)
// {
// 	if (n < 0)
// 		write(1, "N", 1);
// 	else
// 		write(1, "P", 1);
// }

// TEST
// int	main(void)
// {
// 	ft_is_negative(42);
// 	ft_is_negative(-42);
// }
