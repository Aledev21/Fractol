/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:12:47 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 20:13:14 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void burningship(t_data *data, int x, int y)
{
    double cx = (x - WIDTH/2.0) * (4.0/WIDTH) / data->zoom + data->move_x;
    double cy = (y - HEIGHT/2.0) * (4.0/HEIGHT) / data->zoom + data->move_y;
    
    double zx = 0;
    double zy = 0;
    int iter = 0;
    
    while (zx*zx + zy*zy < 4 && iter < data->max_iter)
    {
        double tmp = zx*zx - zy*zy + cx;
        zy = fabs(2*zx*zy) + cy;
        zx = fabs(tmp);
        iter++;
    }
    
    put_pixel(data, x, y, get_color(iter));
}