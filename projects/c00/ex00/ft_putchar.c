/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:21:42 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 11:07:38 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Library needed for the `write` function
#include <unistd.h>

/**
This function will display the given character `c` to console.
write is a function that takes 3 parameters in order to be called.
First parameter is `fd` or `file descriptor`, a number which represents
where the final output should be displayed. There are 3 special ones:
	- `0` is for console input (the program waits for your input)
		-  Alias: `STDIN_FILENO`
	- `1` is for the console standard output (every "normal" output you see).
		- Alias: `STDOUT_FILENO`
	- `2` is for the console error output (every output you see when an error
		happens).
		- Alias: `STDERR_FILENO`
P.s. all the aliases are available when you include <unistd.h> header file.
Second parameter is a pointer to a char (you'll learn about it better later)
so basically it asks for the variable's position inside the pc memory.
It can be retrieved by using `&` character before the variable's name.

Last parameter represents the number of characters to display.
For this function it'll be `1` but it can be higher when "strings" are used.
 */
void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

// MAIN (or program's function) FOR TESTS.
// Do not turn it in.
// int	main(void)
// {
// 	ft_putchar('b');
// 	return (0);
// }
