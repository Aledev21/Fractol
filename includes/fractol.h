#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct  s_env
{
    void    *mlx;
    void    *win;
    void    *img;
    int     bpp;
    int     size_line;
    int     endian;
    int     width;
    int     height;
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
}               t_env;


#endif
