man_MANS = autotrace.1
EXTRA_DIST=$(man_MANS) \
	lib/io/input-magick.h \
	lib/io/input-magick.c \
	lib/io/input-png.c \
	lib/io/input-png.h \
	lib/io/output-pstoedit.c \
	lib/io/output-pstoedit.h \
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

if HAVE_LIBPSTOEDIT
output_pstoedit_src=lib/io/output-pstoedit.h lib/io/output-pstoedit.c
else
output_pstoedit_src=
endif
output_src=\
	lib/io/output-eps.c  lib/io/output-eps.h \
	lib/io/output-er.c   lib/io/output-er.h   \
	lib/io/output-fig.c  lib/io/output-fig.h  \
	lib/io/output-sk.c   lib/io/output-sk.h   \
	lib/io/output-svg.c  lib/io/output-svg.h  \
	lib/io/output-p2e.c  lib/io/output-p2e.h  \
	lib/io/output-emf.c  lib/io/output-emf.h  \
	lib/io/output-dxf.c  lib/io/output-dxf.h  \
	lib/io/output-epd.c  lib/io/output-epd.h  \
	lib/io/output-pdf.c  lib/io/output-pdf.h  \
	lib/io/output-mif.c  lib/io/output-mif.h  \
	lib/io/output-cgm.c  lib/io/output-cgm.h  \
	lib/io/output-dr2d.c lib/io/output-dr2d.h \
	$(output_pstoedit_src)

libautotrace_la_SOURCES = \
	$(input_src) $(output_src) \
	fit.c \
	bitmap.c \
	spline.c \
	curve.c \
	epsilon-equal.c \
	vector.c \
	color.c \
	autotrace.c \
	lib/io/output.c \
	lib/io/input.c \
	pxl-outline.c \
	median.c \
	thin-image.c \
	logreport.c \
	filename.c \
	lib/xstd/xstd.c \
	epsilon-equal.h \
	thin-image.h \
	quantize.h \
	image-header.h \
	fit.h \
	bitmap.h \
	spline.h \
	curve.h \
	vector.h \
	color.h \
	pxl-outline.h \
	despeckle.c \
	despeckle.h \
	exception.c \
	strgicmp.c \
	image-proc.c \
	image-proc.h

autotraceinclude_HEADERS=types.h \
	autotrace.h \
	lib/io/input.h \
	lib/io/output.h \
	exception.h

libautotrace_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

#
# noinst_HEADERS: headers shared between lib and bin.
# File not installed and not shared should be in
# libautotrace_a_SOURCES.
noinst_HEADERS=filename.h \
	lib/xstd/xstd.h \
	logreport.h \
	message.h

autotrace_SOURCES=atou.c \
	atou.h \
	main.c \
	cmdline.h \
	getopt.c \
	getopt.h \
	getopt1.c \
	strgicmp.h

INCLUDES = $(MAGICK_CFLAGS) $(LIBPSTOEDIT_CFLAGS)
autotrace_LDADD=libautotrace.la \
	$(MAGICK_LDFLAGS) \
	$(LIBPNG_LDFLAGS) \
	$(LIBPSTOEDIT_LIBS) \
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
