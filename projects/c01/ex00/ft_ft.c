/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:07:28 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 14:26:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
## Now we get into spicy a argument, POINTERS.
If you didn't know already,
C is a low level programming language (compared to modern ones, not Assembly)
And basically it allows you to work almost directly with your pc's memory (RAM).

So before talking about *pointers*

### How does variable declaration work?
All the programs over your pc are executed on their own processes.
Every process has it's own informations in RAM
and one part of it is about how and where the declared variables are stored.
There is:
- Heap: you have to handle manually the memory allocations
in order to use a variable (you won't need it for a while).
- Stack: all the declarations you've done until now are handled by stack,
which allocates the needed memory automatically (e.g. `int n1`)
and deallocates it at the end of a scope/function where it've been created.

### Variable allocation
Whether it's on the stack or heap, every variable's value is saved in RAM,
and that value is stored in a block of memory of N bytes (e.g. int is 4 bytes).
- Every byte has it's own `ADDRESS` in RAM
(represented by a hexadecimal number like `0x00000042`)
- By declaring a variable type, C automatically interprets the block
as a `whole`, so an `int` variable will take 4 bytes (`from 0x...42 to 0x...44`)

### What is a pointer variable?
A pointer variable does not directly allocate memory, instead it's value is
the `address` of an allocated data.
As we've already seen a `string` is a pointer to char (`char *` / `char []`)
and because all the characters are consecutive bytes in memory
we can access each one as an element of array (`str[i]` or `*(str + i)`)
If we have a pointer to `int` (`int *`) it might refer to a single int,
or an array of int, it's up to you to know which case you are in.

#### Declaration and assignation of a pointer variable
- A pointer is declared by having one (or more) `*` after the variable type:
	```C
	int	n = 1;
	// Declaration + assignation.
	int	*direct = &n;
	// Declaration separated from assignation.
	int	*separated;
	separated = &n;
	```
- Once the `address` is set, we can change the value like this:
	```C
	int	n = 1;
	int	*n_p = &n;
	*n_p = 42;
	```
## Why all of this?
This is useful when you need to change a variable inside a function `a`
from a function `b`.
Also when you'll work with `heap` memory, the only way to use it
is with pointers


So... we need to change the value of the memory
that our pointer `nbr` is pointing, to `42`
(by assuming that whoever calls this function, passes the correct address)
*/
void	ft_ft(int *nbr)
{
	*nbr = 42;
}

//#include <stdio.h>
//int	main(void)
//{
//	int	a;

//	a = -42;
//	printf("A before the ft_ft() call: %d\n", a);
//	ft_ft(&a);
//	printf("A after the ft_ft() call: %d\n", a);
//	return (0);
//}
