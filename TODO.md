# AutoTrace TODO

Feature requests and improvements for future versions.

## High Priority

### Modern Image Format Support

*   Add WebP input support
*   Add AVIF input support
*   Add JPEG XL input support
*   Update ImageMagick integration to leverage all supported formats

### Performance Improvements

*   Multi-threaded processing for large images
*   SIMD optimizations for bitmap operations
*   Memory usage optimization for large files
*   Implement progressive processing for memory efficiency

### SVG Output Improvements

*   Add SVG path simplification options
*   Support SVG groups for color layers
*   Add SVG metadata and title elements
*   Implement viewBox optimization
*   Support CSS styling in SVG output

## Medium Priority

### Batch Processing

*   Implement batch mode for processing multiple files
*   Add directory scanning and recursive processing
*   Support output filename templates
*   Add progress reporting for batch operations

### Color Handling

*   Improve color quantization algorithms
*   Add support for transparent backgrounds in output
*   Implement automatic background detection and removal
*   Add color palette extraction and export
*   Support for layer separation by color

### Configuration and Usability

*   Add configuration file support (JSON or YAML)
*   Implement preset saving and loading
*   Add command-line completion scripts for bash/zsh/fish
*   Improve error messages and warnings
*   Add verbose logging mode with detailed diagnostics

### Output Format Enhancements

*   Add GeoJSON output for mapping applications
*   Improve PDF output with proper embedding
*   Add DXF layer support
*   Implement EMF+ format support
*   Add support for multiple pages/artboards in output

## Low Priority

### Developer Experience

*   Add comprehensive unit test suite
*   Implement integration tests
*   Set up continuous integration (GitHub Actions)
*   Add fuzzing tests for input handlers
*   Create API documentation with examples

### Language Bindings

*   Python bindings via SWIG or pybind11
*   Node.js/JavaScript bindings
*   Ruby bindings
*   Rust FFI bindings

### User Interface

*   GTK4 or Qt-based GUI frontend
*   Web-based interface using WASM
*   Live preview mode during tracing
*   Interactive parameter adjustment
*   Before/after comparison view

### Distribution and Deployment

*   Create Docker container
*   Add Snap package
*   Create Flatpak package
*   Provide AppImage builds
*   Windows installer with NSIS
*   macOS .app bundle with Homebrew formula

### Documentation

*   Expand user manual with examples
*   Create video tutorials
*   Add cookbook for common use cases
*   Document all output format specifications
*   Create developer contributing guide

## Research and Experimental

### Advanced Algorithms

*   Research modern vectorization algorithms
*   Investigate machine learning for edge detection
*   Explore GPU acceleration with OpenCL or CUDA
*   Study potrace algorithm improvements
*   Investigate hybrid raster-vector outputs

### New Features

*   Support for text recognition and vectorization
*   Implement gradient mesh support
*   Add pattern and texture recognition
*   Support for animation frame tracing
*   Implement 3D depth map to vector conversion

## Build System Improvements

*   Migrate from Autotools to CMake or Meson
*   Add option for static linking
*   Implement plugin architecture for input/output handlers
*   Support for cross-compilation
*   Add sanitizer builds (AddressSanitizer, UndefinedBehaviorSanitizer)

## Quality Improvements

*   Fix all compiler warnings with -Wall -Wextra
*   Run static analysis tools (cppcheck, clang-tidy)
*   Address memory leaks found by valgrind
*   Profile and optimize hot paths
*   Reduce binary size

## Compatibility

*   Support for reading Photoshop PSD files
*   Support for GIMP XCF files
*   Add TIFF multi-page support
*   Support for PDF rasterization as input
*   Support for RAW camera formats via libraw

## Notes

For implementation details and discussions, see the issue tracker at https://github.com/pjobson/AutoTrace/issues

To contribute, please read CONTRIBUTING.md and follow the coding standards in the project.
