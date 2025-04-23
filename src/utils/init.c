/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:53:57 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/23 02:44:43 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_mlx_safe(t_data *data)
{
    
    char *dummy = ft_calloc(16384, sizeof(char));
    if (dummy) free(dummy);
    
    init_mlx(data);
}

int init_mlx(t_data *data)
{
    char *cleaner;
    
    
    if (!(data->mlx = mlx_init()))
    {
        printf("Error: MLX initialization failed\n");
        return (0);
    }

    cleaner = ft_calloc(1, 16384); // Limpa a região problemática
    if (!(data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol")))
    {
        free(cleaner);
        free_all(data);
        printf("Error: Window creation failed\n");
        return (0);
    }
    free(cleaner);

    if (!(data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
    {
        free_all(data);
        printf("Error: Image creation failed\n");
        return (0);
    }

    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    
    mlx_hook(data->win, 2, 1L<<0, handle_key, data);
    mlx_hook(data->win, 4, 1L<<2, handle_mouse, data);
    mlx_hook(data->win, 17, 0, close_window, data);
    
    return (1);
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