/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:00:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/05/12 15:33:22 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		temporary;

	i = -1;
	while (++i < size / 2)
	{
		temporary = tab[i];
		tab[i] = tab[(size - 1) - i];
		tab[(size - 1) - i] = temporary;
	}
}
