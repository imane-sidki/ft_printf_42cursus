/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:37:36 by isidki            #+#    #+#             */
/*   Updated: 2022/11/19 11:52:17 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_arg(va_list v, char c)
{
	int	i;

	i = 0;
	if (c == '%')
		i += ft_putchar(c);
	else if(c == 'c')
		i += ft_putchar(va_arg(v,int));
	else if (c == 's')
		i += ft_putstr(va_arg(v,char *));
	else if (c == 'i' || c == 'd')
		i += ft_putnbr(va_arg(v,int));
	else if (c == 'x')
		i += ft_signed_hex(va_arg(v,unsigned int));
	else if (c == 'X')
		i += ft_signed_hex(va_arg(v,unsigned int));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_signed_hex(va_arg(v,unsigned long int));
	}
	else if (c == 'u')
		i += ft_unsigned_decimal(va_arg(v,unsigned int));
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	vlst;
	int		i;
	int		re;

	va_start(vlst, s);
	i = 0;
	re = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i])
				re += check_arg(vlst, s[i]);
		}
		else
			re += ft_putchar(s[i]);
		if (s[i])
			i++;
	}
	return (re);
}
// #include <stdio.h>
// int main()
// {
// 	char *s;

// 	s = "asdasdasdas";
// 	int a = ft_printf("%c %s\n",97,"str");
// 	printf("%d\n",a);
// }
