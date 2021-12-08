/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:28:32 by jeounpar          #+#    #+#             */
/*   Updated: 2021/11/16 19:51:37 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	get_result(char *str, int i, int result, int neg)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	return (result * neg);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		neg;
	int		cnt;
	int		i;
	int		result;

	str = (char *)nptr;
	neg = 1;
	cnt = 0;
	result = 0;
	i = 0;
	while (my_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		cnt++;
		if (cnt > 1)
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (get_result(str, i, result, neg));
}
