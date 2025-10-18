# Changelog

All notable changes to this project will be documented in this file.

This fork maintains the version history from the original AutoTrace project. For the complete historical changelog from AutoTrace 0.31.1 and earlier, see orig_docs/ChangeLog.

## 0.32.0-fork - 2025-10-18

*   Updated project URLs from http://autotrace.sourceforge.net to https://github.com/pjobson/AutoTrace
*   Modernized help output with reorganized sections for better usability
*   Moved original documentation to orig_docs/ directory
*   Updated README.md with modern build instructions and fork information
*   Fixed libpng compatibility issues with modern libpng versions by replacing direct structure access with proper API functions (png_get_error_ptr, png_get_bit_depth, png_get_color_type, etc.)
*   Updated input-png.c to use opaque png_struct handling
*   Fixed typo: changed "hexadezimal" to "hexidecimal" throughout codebase
*   Removed SWF (Shockwave Flash) output support
*   Deleted output-swf.c and output-swf.h
*   Removed libming dependencies from build system
*   Cleaned up configure.in, Makefile.am, and related files
*   Removed Windows-specific build files including Visual Studio project files (.vcproj, .dsp, .dsw, .sln)
*   Removed libming Visual Studio projects
*   Deleted Windows-specific documentation (README.MING)
*   Removed shape_cubic.c.diff (libming-related)
*   Created .gitignore for version control
*   Added modern README.md documenting the fork and build process

## 0.31.1 - 2002-11-09

Original AutoTrace release by Masatake YAMATO and contributors.

*   Version bump to 0.31.1
*   Fixed 64-bit and 128-bit compatibility issues
*   Fixed centerline tracing bugs
*   Various bug fixes in output formats (DR2D, DXF, CGM, EMF, PDF)
*   Library version LT_CURRENT=3

For detailed historical changes, see orig_docs/ChangeLog.

## Project Information

**Original Project:** AutoTrace

**Original Website:** https://autotrace.sourceforge.net/

**Fork Repository:** https://github.com/pjobson/AutoTrace

**Original Authors:** Martin Weber, Masatake YAMATO, and contributors

**Fork Maintainer:** Paul Jobson

This fork aims to modernize AutoTrace for contemporary systems while maintaining compatibility with the original functionality.
