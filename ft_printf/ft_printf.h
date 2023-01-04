/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:42:13 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/09/28 22:37:38 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *symbols, ...);
int				ft_putchar_pf(int c);
int				ft_putstr_pf(char *s);
void			ft_putnbr_pf(int n);
int				ft_putptr(unsigned long n);
size_t			ft_strlen_pf(const char *s);
unsigned long	ft_printnbr(int nbr);
int				ft_print_hexa(int n, int case_x);
char			*ft_itoa_hexa(unsigned int n, char case_x);
char			*ft_itoa_pf(size_t n);
unsigned long	ft_print_unsigned(unsigned int nbr);
void			ft_putnbr_unsigned(unsigned int n);

#endif
