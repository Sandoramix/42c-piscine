/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:11:40 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 15:34:05 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/** It's not as easy as it seems.
 * There's no need to waste time over this exercise as there are more useful
 * concepts on the next ones.
*/
//void	ft_print_combn(int n)
//{
//	(void)n;
//}

/**
# Create a function that displays all unique combinations 
of n distinct digits in ascending order, without repetition. 

## Note

The value of n will be such that: 0 < n < 10.

### Explanation

The subject limits the `n` value to be a maximum of 10, so because of this
we can use an array of 10 characters, which will be used to store and print
the combinations.

`arr[10]` is used to store the combinations, and `i` is used to iterate
through the array.
The elements of the array are initialized to '0' to '9'
with the first `while` loop.

The second `while` has the core logic of the program, which is
to print the combinations in ascending order, without repetition.

*/
void	ft_print_combn(int n)
{
	const int	max = 10;
	char		arr[10];
	int			i;

	if (n < 1 || n > 9)
		return ;
	i = -1;
	while (++i < n)
		arr[i] = '0' + i;
	while (1)
	{
		write(1, arr, n);
		if (arr[0] == '0' + (max - n))
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while (i >= 0 && arr[i] == '9' - (n - 1 - i))
			i--;
		arr[i]++;
		while (++i < n)
			arr[i] = arr[i - 1] + 1;
	}
}

int	main(void)
{
	ft_print_combn(3);
}
