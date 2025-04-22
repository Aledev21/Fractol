/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:47:36 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/19 22:44:25 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int validate_julia_args(char *arg1, char *arg2)
{
    if (!ft_isfloat(arg1) || !ft_isfloat(arg2)) {
        printf("Error: Julia requires 2 decimal numbers\n");
        return (0);
    }
    return (1);
}

void init_fractal(t_data *data, int argc, char **argv)
{
    init_defaults(data);
    
    if (argc < 2) {
        print_help();
        exit_error("No fractal specified");
    }

    if (strcmp(argv[1], "mandelbrot") == 0 && argc == 2) {
        data->type = MANDELBROT;
    }
    else if (strcmp(argv[1], "julia") == 0) {
        data->type = JULIA;
        if (argc == 4 && validate_julia_args(argv[2], argv[3])) {
            data->julia_re = ft_atof(argv[2]);
            data->julia_im = ft_atof(argv[3]);
        }
        else if (argc != 2) {
            print_help();
            exit_error("Invalid Julia parameters");
        }
    }
    else if (strcmp(argv[1], "burningship") == 0 && argc == 2) {
        data->type = BURNING_SHIP;
    }
    else {
        print_help();
        exit_error("Invalid fractal name");
    }
}

int main(int argc, char **argv)
{
    t_data data;

    init_fractal(&data, argc, argv);
    init_mlx(&data);
    
	mlx_hook(data.win, 2, 1L<<0, handle_key, &data);
    mlx_mouse_hook(data.win, handle_mouse, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    
    render(&data);
    mlx_loop(data.mlx);
    
    return (0);
}