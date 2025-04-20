#include "../includes/fractol.h"

void mandelbrot(t_data *data, int x, int y)
{
    double cx = (x - WIDTH/2.0) * (4.0/WIDTH) / data->zoom + data->move_x;
    double cy = (y - HEIGHT/2.0) * (4.0/HEIGHT) / data->zoom + data->move_y;
    
    double zx = 0;
    double zy = 0;
    int iter = 0;
    
    while (zx*zx + zy*zy < 4 && iter < data->max_iter)
    {
        double tmp = zx*zx - zy*zy + cx;
        zy = 2*zx*zy + cy;
        zx = tmp;
        iter++;
    }
    
    put_pixel(data, x, y, get_color(iter));
}