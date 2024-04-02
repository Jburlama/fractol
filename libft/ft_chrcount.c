/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jburlama <jburlama@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:58:28 by Jburlama          #+#    #+#             */
/*   Updated: 2024/04/01 16:40:02 by Jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	returns the amount of times c is found in str
*/
int	ft_chrcount(char *str, char c)
{
	int	count;
	int	i;

	if (!str)
		return (0);
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
