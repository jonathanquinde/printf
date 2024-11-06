/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:02:15 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/05 19:02:15 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int put_nbr_base(size_t num, char *base, size_t len)
{
    int  sum;

    sum = 0;
    if (num >= len)
    {
        sum += put_nbr_base(num / len, base, len);
    } 
    sum += write (1, &base[num % len], 1);
    return (sum);
}

int put_pointer_adress(void *ptr)
{
    int sum;

    if (ptr == NULL)
        return (write(1, "(nil)", 5));
    sum = 0;
    sum += write(1, "0x", 2);
    sum += put_nbr_base((size_t) ptr, "0123456789abcdef", 16);
    return (sum);
}
