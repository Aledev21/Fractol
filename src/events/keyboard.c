/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:50 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/23 03:09:53 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int handle_key(int key, t_data *data) {
    if (key == 65307)  // ESC - geralmente correto para X11
        close_window(data);
    else if (key == 65362)  // seta cima
        data->move_y -= 10.0 / data->zoom;
    else if (key == 65364)  // seta baixo
        data->move_y += 10.0 / data->zoom;

    update_fractal_limits(data);
    render(data);
    return 0;
}
