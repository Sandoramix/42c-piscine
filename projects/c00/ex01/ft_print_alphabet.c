/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:05:13 by odudniak          #+#    #+#             */
/*   Updated: 2023/12/27 00:38:27 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief This function will print every character of the alphabet on a single
 * line.
 * There's no paramether needed to call this function so we explicitly have to
 * declare that we ignore anything that have been passed onto it.
 */

/**
 * @brief This is the "dirty" code. Which means it's not bad because it works,
	but it wont help you to improve in problem solving.
 * Yet you can learn a new concept with it, called "string" or a pointer to char.
 */
// void	ft_print_alphabet(void)
// {
// 	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
// }

/**
 * @brief This is the "correct" way to learn the programming concepts.
 * Here you can:
 * - Reuse the concept of printing a single character to console,
 * - Learn about `variables` (declaration, assignation and usage)
 * - Learn about `loops` , specifically `while loop`
 *   - Conditions, used inside loops.
 * @attention a `char` is actually interpreted by computer as a number.
 * So you can do any mathematical operations on it. (Lookup for `ascii` table)
 */
void	ft_print_alphabet(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		write(1, &letter, 1);
		letter = letter + 1;
	}
}

// int	main(void)
// {
// 	ft_print_alphabet();
// 	return (0);
// }
