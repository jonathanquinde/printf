/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:43:03 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/08 12:24:57 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define BASE_HEX_MIN "0123456789abcdef"
# define BASE_HEX_MAY "0123456789ABCDEF"
# define BASE_DEC "0123456789"

int	put_char(char c);
int	put_str(char *str);
int	put_nbr_base(unsigned int num, char *base, size_t len);
int	put_pointer_adress(void *ptr);
int	handle_negative(int num);
#endif