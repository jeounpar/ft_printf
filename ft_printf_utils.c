/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:30:30 by jeounpar          #+#    #+#             */
/*   Updated: 2021/12/21 16:05:27 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "libft/libft.h"

int string_format(va_list ap)
{
	char	*str;
	char	*rst;
	int		len;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		rst = "(null)";
	else
		rst = ft_strdup(str);
	len += ft_putstr_fd(rst, 1);
	free(rst);
	return (len);
}

int	char_format(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (1);
}

int int_format(va_list ap)
{
	int		n;
	int		len;
	char	*str;
	
	len = 0;
	n = va_arg(ap, int);
	str = ft_itoa(n);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}