/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phtruong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:52:20 by phtruong          #+#    #+#             */
/*   Updated: 2019/02/16 15:18:24 by phtruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Converts the initial portion of the string pointed to by str to int.
** Equivalent to (int)strol(str, (char **)NULL, 10).
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int	sign;
	int	count;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	n = 0;
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str++ - '0';
		count++;
		if (count > 19)
			return ((sign > 0) ? -1 : 0);
	}
	return (n * sign);
}
