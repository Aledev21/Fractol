/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:47:46 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:06:01 by alessandro       ###   ########.fr       */
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
            switch (data->type)
            {
                case MANDELBROT:
                    mandelbrot(data, x, y);
                    break;
                case JULIA:
                    julia(data, x, y);
                    break;
                case BURNING_SHIP:
                    burningship(data, x, y);
                    break;
                default:
                    break;
            }
        }
    }
    
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    
    mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "Fractol - 42");
    mlx_string_put(data->mlx, data->win, 10, 30, 0xFFFFFF, "Zoom: ");
    mlx_string_put(data->mlx, data->win, 60, 30, 0xFFFFFF, ft_itoa((int)data->zoom));
    mlx_string_put(data->mlx, data->win, 10, 50, 0xFFFFFF, "Iter: ");
    mlx_string_put(data->mlx, data->win, 60, 50, 0xFFFFFF, ft_itoa(data->max_iter));
}