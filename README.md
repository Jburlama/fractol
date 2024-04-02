
# Fract'ol

## Fractol is a project from 42 School written in C, focused on creating visually stunning fractals.

On this project, I learned about graphics programming and gained an understanding of how to draw complex visual patterns like fractals on the screen, as well as how to handle events such as zooming and color customization. Additionally, I gained insights into the mathematical concepts behind fractals.

This project follows the the 42 norm


## Minilibx

The MiniLibX is a minimalist graphics library developed by 42. It provides a set of functions for creating graphical applications in C. Operating primarily by interfacing with the X Window System (X11), which is a standard protocol for managing graphical user interfaces on Unix-like operating systems.

https://github.com/42Paris/minilibx-linux

For this project, the MiniLibX version for Linux (minilibx_linux) was used.
### Usage

 - Run `make` inside the repository, and the Makefile will automatically install the MiniLibX for Linux (minilibx-linux) and generate the binary named `fractol`.

- You can run three different commands to generate different fractals:

```bash
    ./fractol mandelbrot
    ./fractol julia <real> <imag>
    ./fractol fern
```
 -- This will create a Mandelbrot set, Julia set, and a Barnsley fern, respectively.

![Screenshot from 2024-04-02 17-01-22](https://github.com/Jburlama/fractol/assets/132925534/e198f908-c64e-4185-81e9-d4125c0064aa)

## Events

- You can zoom in and out by pressing the '+' and '-' keys. Additionally, you can use the mouse scroll wheel, and the zoom will follow the mouse pointer.

- You can add more red, green, or blue by pressing 'r', 'g', or 'b', respectively.

- By pressing 'i', you can increase the precision, however, the more precise it becomes, the slower the rendering.

- You can press 'Esc' or click the 'x' button on the top right corner to close the window.

- You can move the view by pressing the arrow keys.
