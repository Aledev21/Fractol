/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:07:02 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/21 23:32:44 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void julia(t_data *data, int x, int y)
{
    double zx = data->min_re + (double)x / WIDTH * (data->max_re - data->min_re);
    double zy = data->min_im + (double)y / HEIGHT * (data->max_im - data->min_im);
    int iter = 0;

    while (zx*zx + zy*zy < 4 && iter < data->max_iter)
    {
        double tmp = zx*zx - zy*zy + data->julia_re;
        zy = 2 * zx * zy + data->julia_im;
        zx = tmp;
        iter++;
    }
    
    put_pixel(data, x, y, get_color(iter, data->max_iter));
}