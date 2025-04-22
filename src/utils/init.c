/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:53:57 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:42:10 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    
    mlx_hook(data->win, 2, 1L<<0, handle_key, data);
    mlx_hook(data->win, 4, 1L<<2, handle_mouse, data);
    mlx_hook(data->win, 17, 0, close_window, data);
    
    render(data);
}

void init_defaults(t_data *data)
{
    data->zoom = 1.0;
    data->move_x = -0.5; 
    data->move_y = 0.0;
    data->max_iter = 100;
    data->julia_re = -0.7;
    data->julia_im = 0.27015;
    update_fractal_limits(data);
}