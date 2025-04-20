/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:31 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:07:29 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int get_color(int iter) {
    if (iter == MAX_ITER)
        return (0x000000);
    
    int r = iter * 5 % 256;
    int g = iter * 10 % 256;
    int b = iter * 20 % 256;
    
    return (r << 16 | g << 8 | b);
}