/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:47:46 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/21 22:23:38 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void put_pixel(t_data *data, int x, int y, int color)
{
    char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void render(t_data *data)
{
    ft_memset(data->addr, 0, WIDTH * HEIGHT * (data->bpp / 8));
    
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (data->type == MANDELBROT)
                mandelbrot(data, x, y);
            else if (data->type == JULIA)
                julia(data, x, y);
            else if (data->type == BURNING_SHIP)
                burningship(data, x, y);
        }
    }
    
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}