/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:50 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:06:48 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int handle_key(int key, t_data *data) {
    if (key == 53)
        close_window(data);
    else if (key == 123)
        data->move_x -= 10 / data->zoom;
    else if (key == 124)
        data->move_x += 10 / data->zoom;
    else if (key == 126)
        data->move_y -= 10 / data->zoom;
    else if (key == 125)
        data->move_y += 10 / data->zoom;
    
    render(data);
    return (0);
}