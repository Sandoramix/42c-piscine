/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:47:03 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 14:59:48 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Writing a string to STDOUT is "simple", but you can also make it "efficient".
 * Instead of doing a while loop and writing a single character per time,
 * you could do a single write of the string by passing the total str's length
 * as third parameter.
 * the condition of the `while` loop is to stop
 * when the index of `\0` is reached.
 *
 * Also it is a good practice to `NULL` guard the pointers,
 * where `NULL` or `(void *)0` is a special address used usually to indicate
 * the ending of an array (attention: it's not `char` of `\0`, but an address).
 * the condition to use is `str` or `str != NULL` (the same).
 * If there's an `&&` operator, the condition will stop at the first false one.
 * So if `str` == `NULL` then it will.
*/
void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str && str[length])
		length++;
	if (length != 0)
		write(1, str, length);
}
