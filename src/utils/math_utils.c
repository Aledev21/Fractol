/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:54:18 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 21:11:34 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_isfloat(char *str)
{
    int i = 0;
    int has_dot = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    
    while (str[i])
    {
        if (str[i] == '.')
        {
            if (has_dot)
                return (0);
            has_dot = 1;
        }
        else if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

double ft_atof(char *str)
{
    double integer = 0;
    double decimal = 0;
    int sign = 1;
    int i = 0;
    int div = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (ft_isdigit(str[i]))
    {
        integer = integer * 10 + (str[i] - '0');
        i++;
    }
    
    if (str[i] == '.')
    {
        i++;
        while (ft_isdigit(str[i]))
        {
            decimal = decimal * 10 + (str[i] - '0');
            div *= 10;
            i++;
        }
    }
    
    return (sign * (integer + decimal / div));

}

void screen_to_world(t_data *data, int x, int y, double *world_x, double *world_y)
{
    *world_x = (x - WIDTH/2.0) * (4.0/WIDTH) / data->zoom + data->move_x;
    *world_y = (y - HEIGHT/2.0) * (4.0/HEIGHT) / data->zoom + data->move_y;
}