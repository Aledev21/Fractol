#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
#include "Libft/libft.h"
# include <stdio.h>
#include <string.h>

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
    // MLX
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    
    // Fractal
    t_fractal_type type;
    double  zoom;
    double  move_x;
    double  move_y;
    int     max_iter;
    
    // Julia specific
    double  julia_re;
    double  julia_im;
} t_data;

// Main
void    init_mlx(t_data *data);
void    init_fractal(t_data *data, int argc, char **argv);



// Render
void    render(t_data *data);
int     get_color(int iter);
void    put_pixel(t_data *data, int x, int y, int color);

// Events
int     handle_key(int key, t_data *data);
int     handle_mouse(int button, int x, int y, t_data *data);
int     close_window(t_data *data);
int     handle_mouse(int button, int x, int y, t_data *data);
void    screen_to_world(t_data *data, int x, int y, double *world_x, double *world_y);

// Fractals
void    mandelbrot(t_data *data, int x, int y);
void    julia(t_data *data, int x, int y); 
void    burningship(t_data *data, int x, int y);

// Utils
void    print_help(void);
int     ft_isfloat(char *str);
double  ft_atof(char *str);
void    exit_error(char *msg);
void    screen_to_world(t_data *data, int x, int y, double *world_x, double *world_y);
void    print_help(void);
void    init_defaults(t_data *data);

#endif