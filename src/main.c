#include "mlx.h"
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_fractal
{
    void *mlx;
    void *win;
    double real_min;
    double real_max;
    double imag_min;
    double imag_max;
    double zoom_factor;
} t_fractal;

int julia(double real, double imag)
{
    int max_iterations = 1000;
    double c_re = -0.7, c_im = 0.27015;
    int iteration = 0;
    double temp_real;

    while (real * real + imag * imag <= 4 && iteration < max_iterations)
    {
        temp_real = real * real - imag * imag + c_re;
        imag = 2 * real * imag + c_im;
        real = temp_real;
        iteration++;
    }

    return iteration;
}

int iteration_to_color(int iteration)
{
    if (iteration == 1000)
        return 0x000000;
    return (iteration * 255 / 1000) << 16;
}

void generate_fractal(t_fractal *fractal)
{
    int x, y;
    double real, imag;
    int color;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            real = fractal->real_min + (fractal->real_max - fractal->real_min) * x / (WIDTH - 1);
            imag = fractal->imag_min + (fractal->imag_max - fractal->imag_min) * y / (HEIGHT - 1);

            int iteration = julia(real, imag);

            color = iteration_to_color(iteration);

            mlx_pixel_put(fractal->mlx, fractal->win, x, y, color);
        }
    }
}

int mouse_hook(int button, int x, int y, void *param)
{
    (void)x;
    (void)y;

    t_fractal *fractal = (t_fractal *)param;
    double factor = 0.1;

    if (button == 4)
    {
        fractal->real_min += (fractal->real_max - fractal->real_min) * factor;
        fractal->real_max -= (fractal->real_max - fractal->real_min) * factor;
        fractal->imag_min += (fractal->imag_max - fractal->imag_min) * factor;
        fractal->imag_max -= (fractal->imag_max - fractal->imag_min) * factor;
    }
    else if (button == 5)
    {
        fractal->real_min -= (fractal->real_max - fractal->real_min) * factor;
        fractal->real_max += (fractal->real_max - fractal->real_min) * factor;
        fractal->imag_min -= (fractal->imag_max - fractal->imag_min) * factor;
        fractal->imag_max += (fractal->imag_max - fractal->imag_min) * factor;
    }

    mlx_clear_window(fractal->mlx, fractal->win);
    generate_fractal(fractal);
    return 0;
}

int main()
{
    t_fractal fractal;

    fractal.mlx = mlx_init();
    fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "Fractal");

    fractal.real_min = -2.0;
    fractal.real_max = 2.0;
    fractal.imag_min = -2.0;
    fractal.imag_max = 2.0;

    fractal.zoom_factor = 2.0;

    generate_fractal(&fractal);

    mlx_mouse_hook(fractal.win, mouse_hook, &fractal);

    mlx_loop(fractal.mlx);

    return 0;
}
