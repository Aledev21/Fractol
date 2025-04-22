/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:50 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/22 00:36:18 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int handle_key(int key, t_data *data) {
    if (key == 53) // ESC
        close_window(data);
    else if (key == 123) // seta esquerda
        data->move_x -= 10.0 / data->zoom;
    else if (key == 124) // seta direita
        data->move_x += 10.0 / data->zoom;
    else if (key == 126) // seta cima
        data->move_y -= 10.0 / data->zoom;
    else if (key == 125) // seta baixo
        data->move_y += 10.0 / data->zoom;

    update_fractal_limits(data);  // <== ESSENCIAL
    render(data);
    return 0;
}
