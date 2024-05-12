/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:11:00 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 15:32:04 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Selection sort
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		temporary;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
			{
				temporary = tab[i];
				tab[i] = tab[j];
				tab[j] = temporary;
			}
		}
	}
}

/**
 * Bubble sort.
*/
//void	ft_sort_int_tab(int *tab, int size)
//{
//	int		i;
//	int		temporary;

//	while (size > 1)
//	{
//		i = -1;
//		while (++i + 1 < size)
//		{
//			if (tab[i] > tab[i + 1])
//			{
//				temporary = tab[i];
//				tab[i] = tab[i + 1];
//				tab[i + 1] = temporary;
//			}
//		}
//		size--;
//	}
//}
