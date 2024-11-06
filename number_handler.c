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
