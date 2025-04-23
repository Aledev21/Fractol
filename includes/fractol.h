#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "Libft/libft.h"
#include <string.h>
# include <stdio.h>



# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_UP     126
# define KEY_DOWN   125
# define KEY_ESC    53

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ESC 53
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define ZOOM_FACTOR 1.2

typedef enum e_fractal_type {
    MANDELBROT,
    JULIA,
    BURNING_SHIP
} t_fractal_type;

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    t_fractal_type type;
    double  zoom;
    double  move_x;
    double  move_y;
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    int     max_iter;
    double  julia_re;
    double  julia_im;
} t_data;

int     ft_isfloat(char *str);
double  ft_atof(char *str);
void    init_defaults(t_data *data);
void    print_help(void);
void    exit_error(char *msg);
void    init_mlx(t_data *data);
void    render(t_data *data);
int     get_color(int iter, int max_iter);
void    put_pixel(t_data *data, int x, int y, int color);
int     handle_key(int key, t_data *data);
int     handle_mouse(int button, int x, int y, t_data *data);
int     close_window(t_data *data);
void    mandelbrot(t_data *data, int x, int y);
void    julia(t_data *data, int x, int y);
void    burningship(t_data *data, int x, int y);
void    update_fractal_limits(t_data *data);
void    screen_to_world(t_data *data, int x, int y, double *world_x, double *world_y);
void    free_all(t_data *data);


#endif