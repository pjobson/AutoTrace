/* input-magick.c: import files via ImageMagick

   Copyright (C) 1999, 2000, 2001 Martin Weber.
   Copyright (C) 2025 Paul Jobson (updated for ImageMagick 6+/7+)

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA. */

/* This code works with ImageMagick 6+ and 7+ using the MagickWand API */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* Def: HAVE_CONFIG_H */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MagickWand/MagickWand.h>
#include "input-magick.h"
#include "../bitmap/bitmap.h"

at_bitmap_type input_magick_reader(at_string filename,
				   at_input_opts_type * opts,
				   at_msg_func msg_func,
				   at_address msg_data)
{
  MagickWand *wand = NULL;
  MagickBooleanType status;
  size_t width, height;
  size_t x, y;
  unsigned int np;
  size_t point;
  at_bitmap_type bitmap;
  unsigned char *pixels = NULL;
  ImageType image_type;
  char *description;

  /* Initialize MagickWand environment */
  MagickWandGenesis();

  /* Create a wand */
  wand = NewMagickWand();

  /* Read the image */
  status = MagickReadImage(wand, filename);
  if (status == MagickFalse) {
    if (msg_func) {
      description = MagickGetException(wand, NULL);
      msg_func(description, AT_MSG_FATAL, msg_data);
      MagickRelinquishMemory(description);
    }
    goto cleanup;
  }

  /* Get image dimensions */
  width = MagickGetImageWidth(wand);
  height = MagickGetImageHeight(wand);

  /* Determine if image is grayscale or color */
  image_type = MagickGetImageType(wand);
  if (image_type == BilevelType || image_type == GrayscaleType) {
    np = 1;
  } else {
    np = 3;
  }

  /* Initialize bitmap */
  bitmap = at_bitmap_init(NULL, width, height, np);

  /* Allocate temporary pixel buffer */
  pixels = (unsigned char *)malloc(width * height * 3);
  if (!pixels) {
    if (msg_func) {
      msg_func("Failed to allocate pixel buffer", AT_MSG_FATAL, msg_data);
    }
    goto cleanup;
  }

  /* Export image pixels in RGB format */
  status = MagickExportImagePixels(wand, 0, 0, width, height, "RGB", CharPixel, pixels);
  if (status == MagickFalse) {
    if (msg_func) {
      description = MagickGetException(wand, NULL);
      msg_func(description, AT_MSG_FATAL, msg_data);
      MagickRelinquishMemory(description);
    }
    free(pixels);
    goto cleanup;
  }

  /* Copy pixels to bitmap */
  point = 0;
  for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
      size_t pixel_index = (y * width + x) * 3;

      /* Red channel (or gray value) */
      AT_BITMAP_BITS(bitmap)[point++] = pixels[pixel_index];

      /* Green and blue channels for color images */
      if (np == 3) {
        AT_BITMAP_BITS(bitmap)[point++] = pixels[pixel_index + 1];
        AT_BITMAP_BITS(bitmap)[point++] = pixels[pixel_index + 2];
      }
    }
  }

  free(pixels);

cleanup:
  /* Clean up */
  if (wand) {
    DestroyMagickWand(wand);
  }
  MagickWandTerminus();

  return bitmap;
}
