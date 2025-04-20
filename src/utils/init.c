/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:53:57 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 20:54:08 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        exit_error("MLX initialization failed");
    
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
    if (!data->win)
        exit_error("Window creation failed");
    
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img)
        exit_error("Image creation failed");
    
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
}

void init_defaults(t_data *data)
{
    data->zoom = 1.0;
    data->move_x = 0.0;
    data->move_y = 0.0;
    data->max_iter = MAX_ITER;
    data->julia_re = -0.7;
    data->julia_im = 0.27015;
}