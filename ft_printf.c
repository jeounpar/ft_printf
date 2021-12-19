/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:08:56 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/18 22:08:56 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "libft/libft.h"

void	find_format(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
}

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	int		cnt;

	va_start(ap, str);
	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			cnt++;
			ft_putchar_fd(str[i], 1);
		}
		else
		{
			find_format(str[i + 1], ap);
			i++;
		}
		i++;
	}
	va_end(ap);
	return 1;
}