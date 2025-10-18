man_MANS = autotrace.1
EXTRA_DIST=$(man_MANS) \
	lib/io/input-magick.h \
	lib/io/input-magick.c \
	lib/io/input-png.c \
	lib/io/input-png.h \
	autotrace-config.af \
	autotrace-config.in \
	autotrace.m4 \
	autotrace.pc.in \
	autotrace.spec.in

AUTOMAKE_OPTIONS = foreign no-dependencies

autotraceincludedir=$(includedir)/autotrace
lib_LTLIBRARIES=libautotrace.la
bin_PROGRAMS=autotrace

if HAVE_MAGICK
input_magick_src=lib/io/input-magick.h lib/io/input-magick.c
else
input_magick_src=
endif

if HAVE_LIBPNG
input_png_src=lib/io/input-png.c lib/io/input-png.h
else
input_png_src=
endif

input_src=\
	lib/io/input-pnm.c \
	lib/io/input-pnm.h \
	lib/io/input-bmp.c \
	lib/io/input-bmp.h \
	lib/io/input-tga.c \
	lib/io/input-tga.h \
	$(input_png_src) \
	$(input_magick_src)

output_src=\
	lib/io/output-eps.c  lib/io/output-eps.h \
	lib/io/output-er.c   lib/io/output-er.h   \
	lib/io/output-fig.c  lib/io/output-fig.h  \
	lib/io/output-sk.c   lib/io/output-sk.h   \
	lib/io/output-svg.c  lib/io/output-svg.h  \
	lib/io/output-emf.c  lib/io/output-emf.h  \
	lib/io/output-dxf.c  lib/io/output-dxf.h  \
	lib/io/output-epd.c  lib/io/output-epd.h  \
	lib/io/output-pdf.c  lib/io/output-pdf.h  \
	lib/io/output-mif.c  lib/io/output-mif.h  \
	lib/io/output-cgm.c  lib/io/output-cgm.h  \
	lib/io/output-dr2d.c lib/io/output-dr2d.h

libautotrace_la_SOURCES = \
	$(input_src) $(output_src) \
	lib/fit/fit.c \
	lib/bitmap/bitmap.c \
	lib/spline/spline.c \
	lib/curve/curve.c \
	lib/epsilon-equal/epsilon-equal.c \
	lib/vector/vector.c \
	lib/color/color.c \
	autotrace.c \
	lib/io/output.c \
	lib/io/input.c \
	lib/pxl-outline/pxl-outline.c \
	lib/median.c \
	lib/thin-image/thin-image.c \
	lib/logreport/logreport.c \
	lib/filename/filename.c \
	lib/xstd/xstd.c \
	lib/epsilon-equal/epsilon-equal.h \
	lib/thin-image/thin-image.h \
	lib/quantize.h \
	lib/image-header.h \
	lib/fit/fit.h \
	lib/bitmap/bitmap.h \
	lib/spline/spline.h \
	lib/curve/curve.h \
	lib/vector/vector.h \
	lib/color/color.h \
	lib/pxl-outline/pxl-outline.h \
	lib/despeckle/despeckle.c \
	lib/despeckle/despeckle.h \
	lib/exception/exception.c \
	lib/strgicmp/strgicmp.c \
	lib/image-proc/image-proc.c \
	lib/image-proc/image-proc.h

autotraceinclude_HEADERS=lib/types.h \
	autotrace.h \
	lib/io/input.h \
	lib/io/output.h \
	lib/exception/exception.h

libautotrace_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

#
# noinst_HEADERS: headers shared between lib and bin.
# File not installed and not shared should be in
# libautotrace_a_SOURCES.
noinst_HEADERS=lib/filename/filename.h \
	lib/xstd/xstd.h \
	lib/logreport/logreport.h \
	lib/message.h

autotrace_SOURCES=lib/atou/atou.c \
	lib/atou/atou.h \
	main.c \
	cmdline.h \
	lib/getopt/getopt.c \
	lib/getopt/getopt.h \
	lib/getopt/getopt1.c \
	lib/strgicmp/strgicmp.h

INCLUDES = $(MAGICK_CFLAGS)
autotrace_LDADD=libautotrace.la \
	$(MAGICK_LDFLAGS) \
	$(LIBPNG_LDFLAGS) \
	-lm

m4datadir=$(datadir)/aclocal
m4data_DATA=autotrace.m4

pkgconfigdir=$(libdir)/pkgconfig
pkgconfig_DATA=autotrace.pc

bin_SCRIPTS=autotrace-config
BUILT_SOURCES=autotrace-config
autotrace-config: autotrace-config.in

autotrace-config.in: autotrace-config.af
	autofig $<

dist-hook: autotrace.spec
	cp autotrace.spec $(distdir)

rpm: dist autotrace.spec
	rpm -bb autotrace.spec

clean-local:
	find . -maxdepth 1 -name "*.lo" -exec rm -fv {} \;
	find . -maxdepth 1 -name "*.o" -exec rm -fv {} \;
