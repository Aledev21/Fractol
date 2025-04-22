/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:47:46 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/22 00:40:29 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void put_pixel(t_data *data, int x, int y, int color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    char *dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void render(t_data *data)
{
    ft_memset(data->addr, 0, data->line_len * HEIGHT);

    void (*fractal_fn)(t_data *, int, int) = mandelbrot;
    if (data->type == JULIA)
        fractal_fn = julia;
    else if (data->type == BURNING_SHIP)
        fractal_fn = burningship;

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            fractal_fn(data, x, y);

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
