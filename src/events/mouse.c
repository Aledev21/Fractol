/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:07:18 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:41:43 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void update_fractal_limits(t_data *data)
{
    double aspect_ratio = (double)WIDTH / HEIGHT;
    double range_re = 4.0 / data->zoom;
    double range_im = range_re / aspect_ratio;
    
    data->min_re = data->move_x - range_re / 2;
    data->max_re = data->move_x + range_re / 2;
    data->min_im = data->move_y - range_im / 2;
    data->max_im = data->move_y + range_im / 2;
}

int handle_mouse(int button, int x, int y, t_data *data)
{
    double mouse_re, mouse_im;
    
    mouse_re = data->min_re + (double)x / WIDTH * (data->max_re - data->min_re);
    mouse_im = data->min_im + (double)y / HEIGHT * (data->max_im - data->min_im);

    if (button == MOUSE_UP) 
    {
        data->zoom *= ZOOM_FACTOR;
        data->move_x += (mouse_re - data->move_x) * (1 - 1/ZOOM_FACTOR);
        data->move_y += (mouse_im - data->move_y) * (1 - 1/ZOOM_FACTOR);
    }
    else if (button == MOUSE_DOWN) 
    {
        data->zoom /= ZOOM_FACTOR;
        data->move_x += (mouse_re - data->move_x) * (1 - ZOOM_FACTOR);
        data->move_y += (mouse_im - data->move_y) * (1 - ZOOM_FACTOR);
    }
    
    update_fractal_limits(data);
    render(data);
    return (0);
}
   