/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:57:45 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/23 02:20:46 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int close_window(t_data *data)
{
    free_all(data);
    exit(EXIT_SUCCESS);
    return (0);
}

void free_all(t_data *data)
{
    if (!data)
        return;
        
    if (data->img && data->mlx)
        mlx_destroy_image(data->mlx, data->img);
    if (data->win && data->mlx)
        mlx_destroy_window(data->mlx, data->win);

    #ifdef __linux__
        if (data->mlx)
        {
            mlx_destroy_display(data->mlx);
            free(data->mlx);
        }
    #endif
    
    // Limpa outros recursos se necessário
    data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
}