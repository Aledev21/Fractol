/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:31 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:34:54 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int get_color(int iter, int max_iter)
{
    if (iter == max_iter)
        return 0x000000; // Preto para pontos dentro do conjunto
    
    // Exemplo: gradiente de azul para branco
    double t = (double)iter / max_iter;
    int r = 9 * (1-t) * t*t*t * 255;
    int g = 15 * (1-t)*(1-t) * t*t * 255;
    int b = 8.5 * (1-t)*(1-t)*(1-t) * t * 255;
    
    return (r << 16) | (g << 8) | b;
}