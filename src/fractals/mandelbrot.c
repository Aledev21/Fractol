#include "../includes/fractol.h"

void mandelbrot(t_data *data, int x, int y)
{
    double cx = data->min_re + (double)x / WIDTH * (data->max_re - data->min_re);
    double cy = data->min_im + (double)y / HEIGHT * (data->max_im - data->min_im);
    double zx = 0;
    double zy = 0;
    int iter = 0;

    while (zx*zx + zy*zy < 4 && iter < data->max_iter)
    {
        double tmp = zx*zx - zy*zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        iter++;
    }
    
    put_pixel(data, x, y, get_color(iter, data->max_iter));
}