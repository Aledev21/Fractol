#include "fractol.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Usage: ./fractol [fractal_name]\n", 33);
        return (1);
    }
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		
	}
	
}