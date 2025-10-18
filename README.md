# AutoTrace - Modern Fork

AutoTrace is a utility for converting bitmap images into vector graphics.

This is a fork of the original AutoTrace 0.31.1 from [autotrace.sourceforge.net](https://autotrace.sourceforge.net/), updated for modern systems.

## What's New in This Fork

This fork includes updates to work with modern library versions:

* Fixed compatibility with modern libpng (opaque structure support)
* Updated help output with organized sections and modern formatting
* Minor documentation improvements

## Features

* Trace outline and centerline of bitmap images
* Color reduction and despeckling
* Multiple input formats: PNG, TGA, PBM, PNM, PGM, PPM, BMP
* Multiple output formats: EPS, AI, SVG, PDF, DXF, and more

## Requirements

### Required

* C compiler (GCC recommended)
* Standard build tools (make, autoconf, automake, libtool)

### Optional

* libpng - for PNG format support (recommended)
* ImageMagick - for additional input formats

## Building from Source

### Quick Start

    ./configure
    make
    sudo make install

### Detailed Build Steps

1. Configure the build system:

        ./configure

   Common options:

        ./configure --prefix=/usr/local
        ./configure --help    # see all options

2. Compile the program:

        make

3. Install (optional):

        sudo make install

   Or install to custom location:

        ./configure --prefix=$HOME/.local
        make
        make install

### Cleaning Build Artifacts

To remove compiled files:

    make clean

To remove all generated files (returns to fresh checkout):

    make distclean

## Usage

### Basic Usage

Convert a bitmap image to vector graphics:

    autotrace input.png -output-file output.svg

Specify output format:

    autotrace input.png -output-format eps -output-file output.eps

### Common Options

View all options:

    autotrace --help

Key options include:

* `--background-color <hex>` - Ignore background color (e.g., FFFFFF)
* `--color-count <number>` - Reduce to N colors (1-256)
* `--output-format <format>` - Output format (svg, eps, pdf, dxf, etc.)
* `--output-file <filename>` - Output filename
* `--centerline` - Trace centerline instead of outline
* `--despeckle-level <0-20>` - Remove noise from image

### Examples

Convert PNG to SVG with white background removal:

    autotrace logo.png --background-color FFFFFF -output-file logo.svg

Trace centerline with despeckling:

    autotrace scan.png --centerline --despeckle-level 5 -output-file scan.eps

## Library Usage

AutoTrace provides libautotrace for programmatic use.

Sample program:

    #include <autotrace/autotrace.h>

    int main()
    {
      char * fname = "input.png";
      at_fitting_opts_type * opts = at_fitting_opts_new();
      at_input_read_func rfunc = at_input_get_handler(fname);
      at_bitmap_type * bitmap;
      at_splines_type * splines;
      at_output_write_func wfunc = at_output_get_handler_by_suffix("eps");

      bitmap = at_bitmap_read(rfunc, fname, NULL, NULL, NULL);
      splines = at_splines_new(bitmap, opts, NULL, NULL);
      at_splines_write(wfunc, stdout, "", NULL, splines, NULL, NULL);
      return 0;
    }

Compile with:

    gcc sample.c `autotrace-config --libs` `autotrace-config --cflags`

## License

This program is licensed under the GNU General Public License.

The input and output functions can also be used under the GNU Lesser General Public License (LGPL).

## Original Project

* Original website: [http://autotrace.sourceforge.net](http://autotrace.sourceforge.net)
* Original author: Martin Weber
* Version: 0.31.1

## Contributing

Contributions are welcome. See the TODO and HACKING files for areas needing work.
