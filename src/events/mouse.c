/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:07:18 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:07:19 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int handle_mouse(int button, int x, int y, t_data *data)
{
    double world_x;
    double world_y;
    
    screen_to_world(data, x, y, &world_x, &world_y);

    if (button == MOUSE_UP)
    {
        data->zoom *= ZOOM_FACTOR;
        data->move_x += (world_x - data->move_x) * (1 - 1/ZOOM_FACTOR);
        data->move_y += (world_y - data->move_y) * (1 - 1/ZOOM_FACTOR);
    }
    else if (button == MOUSE_DOWN)
    {
        data->zoom /= ZOOM_FACTOR;
        data->move_x += (world_x - data->move_x) * (1 - ZOOM_FACTOR);
        data->move_y += (world_y - data->move_y) * (1 - ZOOM_FACTOR);
    }
    
    render(data);
    return (0);
}
