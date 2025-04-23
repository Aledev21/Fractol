/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:47:36 by alessandro        #+#    #+#             */
/*   Updated: 2025/04/23 02:34:06 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int validate_julia_args(char *arg1, char *arg2)
{
    if (!ft_isfloat(arg1) || !ft_isfloat(arg2))
    {
        printf("Error: Julia requires 2 decimal numbers\n");
        return (0);
    }
    return (1);
}

void init_fractal(t_data *data, int argc, char **argv)
{
    init_defaults(data);

    if (argc < 2)
    {
        print_help();
        exit_error("No fractal specified");
    }

    if (strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
    {
        data->type = MANDELBROT;
    }
    else if (strcmp(argv[1], "julia") == 0)
    {
        data->type = JULIA;
        if (argc == 4 && validate_julia_args(argv[2], argv[3]))
        {
            data->julia_re = ft_atof(argv[2]);
            data->julia_im = ft_atof(argv[3]);
        }
        else if (argc != 2)
        {
            print_help();
            exit_error("Invalid Julia parameters");
        }
    }
    else if (strcmp(argv[1], "burningship") == 0 && argc == 2)
    {
        data->type = BURNING_SHIP;
    }
    else
    {
        print_help();
        exit_error("Invalid fractal name");
    }
}

int main(int argc, char **argv)
{
    t_data data;
    
    // Inicializa a estrutura com zeros
    ft_memset(&data, 0, sizeof(t_data));
    
    init_fractal(&data, argc, argv);
    
    init_mlx_safe(&data);
    if (data.mlx == NULL) 
    {
        free_all(&data);
        exit(EXIT_FAILURE);
    }
    
    render(&data);
    mlx_loop(data.mlx);
    
    // Nunca deve chegar aqui se o loop estiver funcionando corretamente
    free_all(&data);
    return (0);
}