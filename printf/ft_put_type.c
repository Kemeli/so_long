/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:49:42 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/09/28 22:46:20 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen_pf(s));
	return (ft_strlen_pf(s));
}

void	ft_putnbr_pf(int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar_pf('-');
		num = n * -1;
	}
	if (num > 9)
		ft_putnbr_pf(num / 10);
	ft_putchar_pf(num % 10 + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	num;

	num = n;
	if (num > 9)
		ft_putnbr_pf(num / 10);
	ft_putchar_pf(num % 10 + '0');
}

int	ft_putptr(unsigned long n)
{
	int		len;
	char	*str;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	str = ft_itoa_pf((size_t)n);
	ft_putstr_pf("0x");
	ft_putstr_pf(str);
	len = ft_strlen_pf(str) + 2;
	free(str);
	return (len);
}
