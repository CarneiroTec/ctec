# --------------------------------------------------------------------------
#
# CTEC Compiler Makefile
#

ifndef TOP
 TOP = .
 INCLUDED = no
endif

include $(TOP)/config.mak

ifeq (-$(CC)-$(GCC_MAJOR)-$(findstring $(GCC_MINOR),56789)-,-gcc-4--)
 CFLAGS += -D_FORTIFY_SOURCE=0
endif

CFLAGS += $(CPPFLAGS)
VPATH = $(TOPSRC)

ifdef CONFIG_WIN32
 ifneq ($(CONFIG_static),yes)
  LIBCTEC = libctec$(DLLSUF)
  LIBCTECDEF = libctec.def
 endif
 CFGWIN = -win
 NATIVE_TARGET = $(ARCH)-win$(if $(findstring arm,$(ARCH)),ce,32)
else
 LIBS=-lm
 ifneq ($(CONFIG_ldl),no)
  LIBS+=-ldl
 endif
 # make libctec as static or dynamic library?
 ifeq ($(CONFIG_static),no)
  LIBCTEC=libctec$(DLLSUF)
  export LD_LIBRARY_PATH := $(CURDIR)/$(TOP)
  ifneq ($(CONFIG_rpath),no)
   LINK_LIBCTEC += -Wl,-rpath,"$(libdir)"
  endif
 endif
 CFGWIN =-unx
 NATIVE_TARGET = $(ARCH)
 ifdef CONFIG_OSX
  NATIVE_TARGET = $(ARCH)-osx
  LDFLAGS += -flat_namespace -undefined warning
  export MACOSX_DEPLOYMENT_TARGET := 10.2
 endif
endif

# run local version of ctec with local libraries and includes
CTECFLAGS-unx = -B$(TOP) -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP)
CTECFLAGS-win = -B$(TOPSRC)/win32 -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP) -L$(TOP)
CTECFLAGS = $(CTECFLAGS$(CFGWIN))
CTEC = $(TOP)/ctec$(EXESUF) $(CTECFLAGS)
ifdef CONFIG_OSX
 CTECFLAGS += -D_ANSI_SOURCE
endif

CFLAGS_P = $(CFLAGS) -pg -static -DCONFIG_CTEC_STATIC -DCTEC_PROFILE
LIBS_P = $(LIBS)
LDFLAGS_P = $(LDFLAGS)

CONFIG_$(ARCH) = yes
NATIVE_DEFINES_$(CONFIG_i386) += -DCTEC_TARGET_I386
NATIVE_DEFINES_$(CONFIG_x86_64) += -DCTEC_TARGET_X86_64
NATIVE_DEFINES_$(CONFIG_WIN32) += -DCTEC_TARGET_PE
NATIVE_DEFINES_$(CONFIG_OSX) += -DCTEC_TARGET_MACHO
NATIVE_DEFINES_$(CONFIG_uClibc) += -DCTEC_UCLIBC
NATIVE_DEFINES_$(CONFIG_musl) += -DCTEC_MUSL
NATIVE_DEFINES_$(CONFIG_libgcc) += -DCONFIG_USE_LIBGCC
NATIVE_DEFINES_$(CONFIG_selinux) += -DHAVE_SELINUX
NATIVE_DEFINES_$(CONFIG_arm) += -DCTEC_TARGET_ARM
NATIVE_DEFINES_$(CONFIG_arm_eabihf) += -DCTEC_ARM_EABI -DCTEC_ARM_HARDFLOAT
NATIVE_DEFINES_$(CONFIG_arm_eabi) += -DCTEC_ARM_EABI
NATIVE_DEFINES_$(CONFIG_arm_vfp) += -DCTEC_ARM_VFP
NATIVE_DEFINES_$(CONFIG_arm64) += -DCTEC_TARGET_ARM64
NATIVE_DEFINES += $(NATIVE_DEFINES_yes)

ifeq ($(INCLUDED),no)
# --------------------------------------------------------------------------
# running top Makefile

PROGS = ctec$(EXESUF)
CTECLIBS = $(LIBCTEC1) $(LIBCTEC) $(LIBCTECDEF)
CTECDOCS = 

all: $(PROGS) $(CTECLIBS) $(CTECDOCS)

# cross compiler targets to build
CTEC_X = i386 x86_64 i386-win32 x86_64-win32 x86_64-osx arm arm64 arm-wince c67
# CTEC_X += arm-fpa arm-fpa-ld arm-vfp arm-eabi

# cross libctec1.a targets to build
LIBCTEC1_X = i386 x86_64 i386-win32 x86_64-win32 x86_64-osx arm arm64 arm-wince

PROGS_CROSS = $(foreach X,$(CTEC_X),$X-ctec$(EXESUF))
LIBCTEC1_CROSS = $(foreach X,$(LIBCTEC1_X),$X-libctec1.a)

# build cross compilers & libs
cross: $(LIBCTEC1_CROSS) $(PROGS_CROSS)

# build specific cross compiler & lib
cross-%: %-ctec$(EXESUF) %-libctec1.a ;

install: ; @$(MAKE) --no-print-directory install$(CFGWIN)
install-strip: ; @$(MAKE) --no-print-directory install$(CFGWIN) CONFIG_strip=yes
uninstall: ; @$(MAKE) --no-print-directory uninstall$(CFGWIN)

ifdef CONFIG_cross
all : cross
endif

# --------------------------------------------

T = $(or $(CROSS_TARGET),$(NATIVE_TARGET),unknown)
X = $(if $(CROSS_TARGET),$(CROSS_TARGET)-)

DEF-i386        = -DCTEC_TARGET_I386
DEF-x86_64      = -DCTEC_TARGET_X86_64
DEF-i386-win32  = -DCTEC_TARGET_PE -DCTEC_TARGET_I386
DEF-x86_64-win32= -DCTEC_TARGET_PE -DCTEC_TARGET_X86_64
DEF-x86_64-osx  = -DCTEC_TARGET_MACHO -DCTEC_TARGET_X86_64
DEF-arm-wince   = -DCTEC_TARGET_PE -DCTEC_TARGET_ARM -DCTEC_ARM_EABI -DCTEC_ARM_VFP -DCTEC_ARM_HARDFLOAT
DEF-arm64       = -DCTEC_TARGET_ARM64
DEF-c67         = -DCTEC_TARGET_C67 -w # disable warnigs
DEF-arm-fpa     = -DCTEC_TARGET_ARM
DEF-arm-fpa-ld  = -DCTEC_TARGET_ARM -DLDOUBLE_SIZE=12
DEF-arm-vfp     = -DCTEC_TARGET_ARM -DCTEC_ARM_VFP
DEF-arm-eabi    = -DCTEC_TARGET_ARM -DCTEC_ARM_VFP -DCTEC_ARM_EABI
DEF-arm-eabihf  = -DCTEC_TARGET_ARM -DCTEC_ARM_VFP -DCTEC_ARM_EABI -DCTEC_ARM_HARDFLOAT
DEF-arm         = $(DEF-arm-eabihf)
DEF-$(NATIVE_TARGET) = $(NATIVE_DEFINES)

DEFINES += $(DEF-$T) $(DEF-all)
DEFINES += $(if $(ROOT-$T),-DCONFIG_SYSROOT="\"$(ROOT-$T)\"")
DEFINES += $(if $(CRT-$T),-DCONFIG_CTEC_CRTPREFIX="\"$(CRT-$T)\"")
DEFINES += $(if $(LIB-$T),-DCONFIG_CTEC_LIBPATHS="\"$(LIB-$T)\"")
DEFINES += $(if $(INC-$T),-DCONFIG_CTEC_SYSINCLUDEPATHS="\"$(INC-$T)\"")
DEFINES += $(DEF-$(or $(findstring win,$T),unx))

ifneq ($(X),)
ifeq ($(CONFIG_WIN32),yes)
DEF-win += -DCTEC_LIBCTEC1="\"$(X)libctec1.a\""
DEF-unx += -DCTEC_LIBCTEC1="\"lib/$(X)libctec1.a\""
else
DEF-all += -DCTEC_LIBCTEC1="\"$(X)libctec1.a\""
DEF-win += -DCONFIG_CTECDIR="\"$(ctecdir)/win32\""
endif
endif

# include custom configuration (see make help)
-include config-extra.mak

CORE_FILES = ctec.c ctectools.c libctec.c ctecpp.c ctecgen.c ctecelf.c ctecasm.c ctecrun.c
CORE_FILES += ctec.h config.h libctec.h ctectok.h
i386_FILES = $(CORE_FILES) i386-gen.c i386-link.c i386-asm.c i386-asm.h i386-tok.h
i386-win32_FILES = $(i386_FILES) ctecpe.c
x86_64_FILES = $(CORE_FILES) x86_64-gen.c x86_64-link.c i386-asm.c x86_64-asm.h
x86_64-win32_FILES = $(x86_64_FILES) ctecpe.c
x86_64-osx_FILES = $(x86_64_FILES)
arm_FILES = $(CORE_FILES) arm-gen.c arm-link.c arm-asm.c
arm-wince_FILES = $(arm_FILES) ctecpe.c
arm64_FILES = $(CORE_FILES) arm64-gen.c arm64-link.c
c67_FILES = $(CORE_FILES) c67-gen.c c67-link.c cteccoff.c

# libctec sources
LIBCTEC_SRC = $(filter-out ctec.c ctectools.c,$(filter %.c,$($T_FILES)))

ifeq ($(ONE_SOURCE),yes)
LIBCTEC_OBJ = $(X)libctec.o
LIBCTEC_INC = $($T_FILES)
CTEC_FILES = $(X)ctec.o
ctec.o : DEFINES += -DONE_SOURCE=0
else
LIBCTEC_OBJ = $(patsubst %.c,$(X)%.o,$(LIBCTEC_SRC))
LIBCTEC_INC = $(filter %.h %-gen.c %-link.c,$($T_FILES))
CTEC_FILES = $(X)ctec.o $(LIBCTEC_OBJ)
$(CTEC_FILES) : DEFINES += -DONE_SOURCE=0
endif

# target specific object rule
$(X)%.o : %.c $(LIBCTEC_INC)
	$(CC) -o $@ -c $< $(DEFINES) $(CFLAGS)

# additional dependencies
$(X)ctec.o : ctectools.c

# Host CTEC Compiler
ctec$(EXESUF): ctec.o $(LIBCTEC)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS) $(LINK_LIBCTEC)

# Cross Tiny C Compilers
%-ctec$(EXESUF): FORCE
	@$(MAKE) --no-print-directory $@ CROSS_TARGET=$* ONE_SOURCE=$(or $(ONE_SOURCE),yes)

$(CROSS_TARGET)-ctec$(EXESUF): $(CTEC_FILES)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS)

# profiling version
ctec_p$(EXESUF): $($T_FILES)
	$(CC) -o $@ $< $(DEFINES) $(CFLAGS_P) $(LIBS_P) $(LDFLAGS_P)

# static libctec library
libctec.a: $(LIBCTEC_OBJ)
	$(AR) rcs $@ $^

# dynamic libctec library
libctec.so: $(LIBCTEC_OBJ)
	$(CC) -shared -Wl,-soname,$@ -o $@ $^ $(LDFLAGS)

libctec.so: CFLAGS+=-fPIC
libctec.so: LDFLAGS+=-fPIC

# windows dynamic libctec library
libctec.dll : $(LIBCTEC_OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)
libctec.dll : DEFINES += -DLIBCTEC_AS_DLL

# import file for windows libctec.dll
libctec.def : libctec.dll ctec$(EXESUF)
	$(XCTEC) -impdef $< -o $@
XCTEC ?= ./ctec$(EXESUF)

# CTec runtime libraries
libctec1.a : ctec$(EXESUF) FORCE
	@$(MAKE) -C lib DEFINES='$(DEF-$T)'

# Cross libctec1.a
%-libctec1.a : %-ctec$(EXESUF) FORCE
	@$(MAKE) -C lib DEFINES='$(DEF-$*)' CROSS_TARGET=$*

.PRECIOUS: %-libctec1.a
FORCE:

# --------------------------------------------------------------------------
# install

INSTALL = install -m644
INSTALLBIN = install -m755 $(STRIP_$(CONFIG_strip))
STRIP_yes = -s

LIBCTEC1_W = $(filter %-win32-libctec1.a %-wince-libctec1.a,$(LIBCTEC1_CROSS))
LIBCTEC1_U = $(filter-out $(LIBCTEC1_W),$(LIBCTEC1_CROSS))
IB = $(if $1,mkdir -p $2 && $(INSTALLBIN) $1 $2)
IBw = $(call IB,$(wildcard $1),$2)
IF = $(if $1,mkdir -p $2 && $(INSTALL) $1 $2)
IFw = $(call IF,$(wildcard $1),$2)
IR = mkdir -p $2 && cp -r $1/. $2

# install progs & libs
install-unx:
	$(call IBw,$(PROGS) $(PROGS_CROSS),"$(bindir)")
	$(call IFw,$(LIBCTEC1) $(LIBCTEC1_U),"$(ctecdir)")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/cteclib.h,"$(ctecdir)/include")
	$(call $(if $(findstring .so,$(LIBCTEC)),IBw,IFw),$(LIBCTEC),"$(libdir)")
	$(call IF,$(TOPSRC)/libctec.h,"$(includedir)")
	$(call IFw,ctec.1,"$(mandir)/man1")
	$(call IFw,ctec-doc.info,"$(infodir)")
	$(call IFw,ctec-doc.html,"$(docdir)")
ifneq "$(wildcard $(LIBCTEC1_W))" ""
	$(call IFw,$(TOPSRC)/win32/lib/*.def $(LIBCTEC1_W),"$(ctecdir)/win32/lib")
	$(call IR,$(TOPSRC)/win32/include,"$(ctecdir)/win32/include")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/cteclib.h,"$(ctecdir)/win32/include")
endif

# uninstall
uninstall-unx:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS),"$(bindir)/$P")
	@rm -fv "$(libdir)/libctec.a" "$(libdir)/libctec.so" "$(includedir)/libctec.h"
	@rm -fv "$(mandir)/man1/ctec.1" "$(infodir)/ctec-doc.info"
	@rm -fv "$(docdir)/ctec-doc.html"
	rm -r "$(ctecdir)"

# install progs & libs on windows
install-win:
	$(call IBw,$(PROGS) $(PROGS_CROSS) $(subst libctec.a,,$(LIBCTEC)),"$(bindir)")
	$(call IF,$(TOPSRC)/win32/lib/*.def,"$(ctecdir)/lib")
	$(call IFw,libctec1.a $(LIBCTEC1_W),"$(ctecdir)/lib")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/cteclib.h,"$(ctecdir)/include")
	$(call IR,$(TOPSRC)/win32/include,"$(ctecdir)/include")
	$(call IR,$(TOPSRC)/win32/examples,"$(ctecdir)/examples")
	$(call IF,$(TOPSRC)/tests/libctec_test.c,"$(ctecdir)/examples")
	$(call IFw,$(TOPSRC)/libctec.h $(subst .dll,.def,$(LIBCTEC)),"$(libdir)")
	$(call IFw,$(TOPSRC)/win32/ctec-win32.txt ctec-doc.html,"$(docdir)")
ifneq "$(wildcard $(LIBCTEC1_U))" ""
	$(call IFw,$(LIBCTEC1_U),"$(ctecdir)/lib")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/cteclib.h,"$(ctecdir)/lib/include")
endif

# the msys-git shell works to configure && make except it does not have install
ifeq "$(and $(CONFIG_WIN32),$(shell which install >/dev/null 2>&1 || echo no))" "no"
install-win : INSTALL = cp
install-win : INSTALLBIN = cp
endif

# uninstall on windows
uninstall-win:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS) libctec.dll,"$(bindir)/$P")
	@rm -fv $(foreach F,ctec-doc.html ctec-win32.txt,"$(docdir)/$F")
	@rm -fv $(foreach F,libctec.h libctec.def libctec.a,"$(libdir)/$F")
	rm -r "$(ctecdir)"

# --------------------------------------------------------------------------
# other stuff

TAGFILES = *.[ch] include/*.h lib/*.[chS]
tags : ; ctags $(TAGFILES)
# cannot have both tags and TAGS on windows
ETAGS : ; etags $(TAGFILES)

# create release tarball from *current* git branch (including ctec-doc.html
# and converting two files to CRLF)
CTEC-VERSION = ctec-$(VERSION)
tar:    ctec-doc.html
	mkdir $(CTEC-VERSION)
	( cd $(CTEC-VERSION) && git --git-dir ../.git checkout -f )
	cp ctec-doc.html $(CTEC-VERSION)
	for f in ctec-win32.txt build-ctec.bat ; do \
	    cat win32/$$f | sed 's,\(.*\),\1\r,g' > $(CTEC-VERSION)/win32/$$f ; \
	done
	tar cjf $(CTEC-VERSION).tar.bz2 $(CTEC-VERSION)
	rm -rf $(CTEC-VERSION)
	git reset

config.mak:
	$(if $(wildcard $@),,@echo "Please run ./configure." && exit 1)

# run all tests
test:
	$(MAKE) -C tests
# run test(s) from tests2 subdir (see make help)
tests2.%:
	$(MAKE) -C tests/tests2 $@

clean:
	-rm -f ctec$(EXESUF) ctec_p$(EXESUF) *-ctec$(EXESUF)
	-rm -f  *~ *.o *.a *.so* *.out *.log lib*.def *.exe *.dll a.out tags TAGS
	@$(MAKE) -C lib $@
	@$(MAKE) -C tests $@

distclean: clean
	rm -f config.h config.mak config.texi

.PHONY: all clean test tar tags ETAGS distclean install uninstall FORCE

help:
	@echo "make"
	@echo "   build native compiler (from separate objects)"
	@echo ""
	@echo "make cross"
	@echo "   build cross compilers (from one source)"
	@echo ""
	@echo "make ONE_SOURCE=yes / no"
	@echo "   force building from one source / separate objects"
	@echo ""
	@echo "make cross-TARGET"
	@echo "   build one specific cross compiler for 'TARGET', as in"
	@echo "   $(CTEC_X)"
	@echo ""
	@echo "Custom configuration:"
	@echo "   The makefile includes a file 'config-extra.mak' if it is present."
	@echo "   This file may contain some custom configuration.  For example:"
	@echo ""
	@echo "      NATIVE_DEFINES += -D..."
	@echo ""
	@echo "   Or for example to configure the search paths for a cross-compiler"
	@echo "   that expects the linux files in <ctecdir>/i386-linux:"
	@echo ""
	@echo "      ROOT-i386 = {B}/i386-linux"
	@echo "      CRT-i386  = {B}/i386-linux/usr/lib"
	@echo "      LIB-i386  = {B}/i386-linux/lib:{B}/i386-linux/usr/lib"
	@echo "      INC-i386  = {B}/lib/include:{B}/i386-linux/usr/include"
	@echo "      DEF-i386  += -D__linux__"
	@echo ""
	@echo "make test"
	@echo "   run all tests"
	@echo ""
	@echo "make tests2.all / make tests2.37 / make tests2.37+"
	@echo "   run all/single test(s) from tests2, optionally update .expect"
	@echo ""
	@echo "Other supported make targets:"
	@echo "   install install-strip tags ETAGS tar clean distclean help"
	@echo ""

# --------------------------------------------------------------------------
endif # ($(INCLUDED),no)
