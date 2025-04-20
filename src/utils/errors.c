/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:52:01 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 20:53:35 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void exit_error(char *msg)
{
    ft_putstr_fd("Error: ", 2);
    ft_putendl_fd(msg, 2);
    exit(EXIT_FAILURE);
}

void print_help(void)
{
    printf("Usage:\n");
    printf("./fractol mandelbrot\n");
    printf("./fractol julia <real> <imaginary>\n");
    printf("./fractol burningship\n");
    printf("\nExample Julia sets:\n");
    printf("./fractol julia -0.7 0.27015\n");
    printf("./fractol julia -0.7269 0.1889\n");
}