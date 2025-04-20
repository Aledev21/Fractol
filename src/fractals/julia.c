/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:07:02 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 20:29:59 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void julia(t_data *data, int x, int y)
{
    double zx = (x - WIDTH/2.0) * (4.0/WIDTH) / data->zoom + data->move_x;
    double zy = (y - HEIGHT/2.0) * (4.0/HEIGHT) / data->zoom + data->move_y;
    int iter = 0;
    
    while (zx*zx + zy*zy < 4 && iter < data->max_iter)
    {
        double tmp = zx*zx - zy*zy + data->julia_re;
        zy = 2*zx*zy + data->julia_im;
        zx = tmp;
        iter++;
    }
    
    put_pixel(data, x, y, get_color(iter));
}