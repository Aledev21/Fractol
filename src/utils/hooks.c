/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:54:38 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 20:54:41 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(EXIT_SUCCESS);
    return (0);
}

void setup_hooks(t_data *data)
{
    mlx_hook(data->win, 2, 1L<<0, handle_key, data);
    mlx_hook(data->win, 4, 1L<<2, handle_mouse, data);
    mlx_hook(data->win, 17, 0, close_window, data);
}