# --------------------------------------------------------------------------
#
# NILDO Compiler Makefile
#

ifndef TOP
 TOP = .
 INCLUDED = no
endif

include $(TOP)/config.mak

ifeq (-$(CC)-$(GCC_MAJOR)-$(findstring $(GCC_MINOR),56789)-,-gcc-4--)
 CFLAGS += -D_FORTIFY_SOURCE=0
endif

LIBNILDO = libnld.a
LIBNILDO1 = libnld1.a
LINK_LIBNILDO =
LIBS =
CFLAGS += -I$(TOP)
CFLAGS += $(CPPFLAGS)
VPATH = $(TOPSRC)

ifdef CONFIG_WIN32
 ifneq ($(CONFIG_static),yes)
  LIBNILDO = libnld$(DLLSUF)
  LIBNILDODEF = libnld.def
 endif
 CFGWIN = -win
 NATIVE_TARGET = $(ARCH)-win$(if $(findstring arm,$(ARCH)),ce,32)
else
 LIBS=-lm
 ifneq ($(CONFIG_ldl),no)
  LIBS+=-ldl
 endif
 # make libnld as static or dynamic library?
 ifeq ($(CONFIG_static),no)
  LIBNILDO=libnld$(DLLSUF)
  export LD_LIBRARY_PATH := $(CURDIR)/$(TOP)
  ifneq ($(CONFIG_rpath),no)
   LINK_LIBNILDO += -Wl,-rpath,"$(libdir)"
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

# run local version of nld with local libraries and includes
NILDOFLAGS-unx = -B$(TOP) -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP)
NILDOFLAGS-win = -B$(TOPSRC)/win32 -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP) -L$(TOP)
NILDOFLAGS = $(NILDOFLAGS$(CFGWIN))
NILDO = $(TOP)/nld$(EXESUF) $(NILDOFLAGS)
ifdef CONFIG_OSX
 NILDOFLAGS += -D_ANSI_SOURCE
endif

CFLAGS_P = $(CFLAGS) -pg -static -DCONFIG_NILDO_STATIC -DNILDO_PROFILE
LIBS_P = $(LIBS)
LDFLAGS_P = $(LDFLAGS)

CONFIG_$(ARCH) = yes
NATIVE_DEFINES_$(CONFIG_i386) += -DNILDO_TARGET_I386
NATIVE_DEFINES_$(CONFIG_x86_64) += -DNILDO_TARGET_X86_64
NATIVE_DEFINES_$(CONFIG_WIN32) += -DNILDO_TARGET_PE
NATIVE_DEFINES_$(CONFIG_OSX) += -DNILDO_TARGET_MACHO
NATIVE_DEFINES_$(CONFIG_uClibc) += -DNILDO_UCLIBC
NATIVE_DEFINES_$(CONFIG_musl) += -DNILDO_MUSL
NATIVE_DEFINES_$(CONFIG_libgcc) += -DCONFIG_USE_LIBGCC
NATIVE_DEFINES_$(CONFIG_selinux) += -DHAVE_SELINUX
NATIVE_DEFINES_$(CONFIG_arm) += -DNILDO_TARGET_ARM
NATIVE_DEFINES_$(CONFIG_arm_eabihf) += -DNILDO_ARM_EABI -DNILDO_ARM_HARDFLOAT
NATIVE_DEFINES_$(CONFIG_arm_eabi) += -DNILDO_ARM_EABI
NATIVE_DEFINES_$(CONFIG_arm_vfp) += -DNILDO_ARM_VFP
NATIVE_DEFINES_$(CONFIG_arm64) += -DNILDO_TARGET_ARM64
NATIVE_DEFINES += $(NATIVE_DEFINES_yes)

ifeq ($(INCLUDED),no)
# --------------------------------------------------------------------------
# running top Makefile

PROGS = nld$(EXESUF)
NILDOLIBS = $(LIBNILDO1) $(LIBNILDO) $(LIBNILDODEF)
NILDODOCS = nld.1 nld-doc.html nld-doc.info

all: $(PROGS) $(NILDOLIBS) $(NILDODOCS)

# cross compiler targets to build
NILDO_X = i386 x86_64 i386-win32 x86_64-win32 x86_64-osx arm arm64 arm-wince c67
# NILDO_X += arm-fpa arm-fpa-ld arm-vfp arm-eabi

# cross libnld1.a targets to build
LIBNILDO1_X = i386 x86_64 i386-win32 x86_64-win32 x86_64-osx arm arm64 arm-wince

PROGS_CROSS = $(foreach X,$(NILDO_X),$X-nld$(EXESUF))
LIBNILDO1_CROSS = $(foreach X,$(LIBNILDO1_X),$X-libnld1.a)

# build cross compilers & libs
cross: $(LIBNILDO1_CROSS) $(PROGS_CROSS)

# build specific cross compiler & lib
cross-%: %-nld$(EXESUF) %-libnld1.a ;

install: ; @$(MAKE) --no-print-directory install$(CFGWIN)
install-strip: ; @$(MAKE) --no-print-directory install$(CFGWIN) CONFIG_strip=yes
uninstall: ; @$(MAKE) --no-print-directory uninstall$(CFGWIN)

ifdef CONFIG_cross
all : cross
endif

# --------------------------------------------

T = $(or $(CROSS_TARGET),$(NATIVE_TARGET),unknown)
X = $(if $(CROSS_TARGET),$(CROSS_TARGET)-)

DEF-i386        = -DNILDO_TARGET_I386
DEF-x86_64      = -DNILDO_TARGET_X86_64
DEF-i386-win32  = -DNILDO_TARGET_PE -DNILDO_TARGET_I386
DEF-x86_64-win32= -DNILDO_TARGET_PE -DNILDO_TARGET_X86_64
DEF-x86_64-osx  = -DNILDO_TARGET_MACHO -DNILDO_TARGET_X86_64
DEF-arm-wince   = -DNILDO_TARGET_PE -DNILDO_TARGET_ARM -DNILDO_ARM_EABI -DNILDO_ARM_VFP -DNILDO_ARM_HARDFLOAT
DEF-arm64       = -DNILDO_TARGET_ARM64
DEF-c67         = -DNILDO_TARGET_C67 -w # disable warnigs
DEF-arm-fpa     = -DNILDO_TARGET_ARM
DEF-arm-fpa-ld  = -DNILDO_TARGET_ARM -DLDOUBLE_SIZE=12
DEF-arm-vfp     = -DNILDO_TARGET_ARM -DNILDO_ARM_VFP
DEF-arm-eabi    = -DNILDO_TARGET_ARM -DNILDO_ARM_VFP -DNILDO_ARM_EABI
DEF-arm-eabihf  = -DNILDO_TARGET_ARM -DNILDO_ARM_VFP -DNILDO_ARM_EABI -DNILDO_ARM_HARDFLOAT
DEF-arm         = $(DEF-arm-eabihf)
DEF-$(NATIVE_TARGET) = $(NATIVE_DEFINES)

DEFINES += $(DEF-$T) $(DEF-all)
DEFINES += $(if $(ROOT-$T),-DCONFIG_SYSROOT="\"$(ROOT-$T)\"")
DEFINES += $(if $(CRT-$T),-DCONFIG_NILDO_CRTPREFIX="\"$(CRT-$T)\"")
DEFINES += $(if $(LIB-$T),-DCONFIG_NILDO_LIBPATHS="\"$(LIB-$T)\"")
DEFINES += $(if $(INC-$T),-DCONFIG_NILDO_SYSINCLUDEPATHS="\"$(INC-$T)\"")
DEFINES += $(DEF-$(or $(findstring win,$T),unx))

ifneq ($(X),)
ifeq ($(CONFIG_WIN32),yes)
DEF-win += -DNILDO_LIBNILDO1="\"$(X)libnld1.a\""
DEF-unx += -DNILDO_LIBNILDO1="\"lib/$(X)libnld1.a\""
else
DEF-all += -DNILDO_LIBNILDO1="\"$(X)libnld1.a\""
DEF-win += -DCONFIG_NILDODIR="\"$(nlddir)/win32\""
endif
endif

# include custom configuration (see make help)
-include config-extra.mak

CORE_FILES = nld.c nldtools.c libnld.c nldpp.c nldgen.c nldelf.c nldasm.c nldrun.c
CORE_FILES += nld.h config.h libnld.h nldtok.h
i386_FILES = $(CORE_FILES) i386-gen.c i386-link.c i386-asm.c i386-asm.h i386-tok.h
i386-win32_FILES = $(i386_FILES) nldpe.c
x86_64_FILES = $(CORE_FILES) x86_64-gen.c x86_64-link.c i386-asm.c x86_64-asm.h
x86_64-win32_FILES = $(x86_64_FILES) nldpe.c
x86_64-osx_FILES = $(x86_64_FILES)
arm_FILES = $(CORE_FILES) arm-gen.c arm-link.c arm-asm.c
arm-wince_FILES = $(arm_FILES) nldpe.c
arm64_FILES = $(CORE_FILES) arm64-gen.c arm64-link.c
c67_FILES = $(CORE_FILES) c67-gen.c c67-link.c nldcoff.c

# libnld sources
LIBNILDO_SRC = $(filter-out nld.c nldtools.c,$(filter %.c,$($T_FILES)))

ifeq ($(ONE_SOURCE),yes)
LIBNILDO_OBJ = $(X)libnld.o
LIBNILDO_INC = $($T_FILES)
NILDO_FILES = $(X)nld.o
nld.o : DEFINES += -DONE_SOURCE=0
else
LIBNILDO_OBJ = $(patsubst %.c,$(X)%.o,$(LIBNILDO_SRC))
LIBNILDO_INC = $(filter %.h %-gen.c %-link.c,$($T_FILES))
NILDO_FILES = $(X)nld.o $(LIBNILDO_OBJ)
$(NILDO_FILES) : DEFINES += -DONE_SOURCE=0
endif

# target specific object rule
$(X)%.o : %.c $(LIBNILDO_INC)
	$(CC) -o $@ -c $< $(DEFINES) $(CFLAGS)

# additional dependencies
$(X)nld.o : nldtools.c

# Host NILDO Compiler
nld$(EXESUF): nld.o $(LIBNILDO)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS) $(LINK_LIBNILDO)

# Cross Tiny C Compilers
%-nld$(EXESUF): FORCE
	@$(MAKE) --no-print-directory $@ CROSS_TARGET=$* ONE_SOURCE=$(or $(ONE_SOURCE),yes)

$(CROSS_TARGET)-nld$(EXESUF): $(NILDO_FILES)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS)

# profiling version
nld_p$(EXESUF): $($T_FILES)
	$(CC) -o $@ $< $(DEFINES) $(CFLAGS_P) $(LIBS_P) $(LDFLAGS_P)

# static libnld library
libnld.a: $(LIBNILDO_OBJ)
	$(AR) rcs $@ $^

# dynamic libnld library
libnld.so: $(LIBNILDO_OBJ)
	$(CC) -shared -Wl,-soname,$@ -o $@ $^ $(LDFLAGS)

libnld.so: CFLAGS+=-fPIC
libnld.so: LDFLAGS+=-fPIC

# windows dynamic libnld library
libnld.dll : $(LIBNILDO_OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)
libnld.dll : DEFINES += -DLIBNILDO_AS_DLL

# import file for windows libnld.dll
libnld.def : libnld.dll nld$(EXESUF)
	$(XNILDO) -impdef $< -o $@
XNILDO ?= ./nld$(EXESUF)

# Nildo runtime libraries
libnld1.a : nld$(EXESUF) FORCE
	@$(MAKE) -C lib DEFINES='$(DEF-$T)'

# Cross libnld1.a
%-libnld1.a : %-nld$(EXESUF) FORCE
	@$(MAKE) -C lib DEFINES='$(DEF-$*)' CROSS_TARGET=$*

.PRECIOUS: %-libnld1.a
FORCE:

# --------------------------------------------------------------------------
# documentation and man page
nld-doc.html: nld-doc.texi
	makeinfo --no-split --html --number-sections -o $@ $< || true

nld.1: nld-doc.texi
	$(TOPSRC)/texi2pod.pl $< nld.pod \
	&& pod2man --section=1 --center="NILDO Compiler" --release="$(VERSION)" nld.pod >tmp.1 \
	&& mv tmp.1 $@ || rm -f tmp.1

nld-doc.info: nld-doc.texi
	makeinfo $< || true

# --------------------------------------------------------------------------
# install

INSTALL = install -m644
INSTALLBIN = install -m755 $(STRIP_$(CONFIG_strip))
STRIP_yes = -s

LIBNILDO1_W = $(filter %-win32-libnld1.a %-wince-libnld1.a,$(LIBNILDO1_CROSS))
LIBNILDO1_U = $(filter-out $(LIBNILDO1_W),$(LIBNILDO1_CROSS))
IB = $(if $1,mkdir -p $2 && $(INSTALLBIN) $1 $2)
IBw = $(call IB,$(wildcard $1),$2)
IF = $(if $1,mkdir -p $2 && $(INSTALL) $1 $2)
IFw = $(call IF,$(wildcard $1),$2)
IR = mkdir -p $2 && cp -r $1/. $2

# install progs & libs
install-unx:
	$(call IBw,$(PROGS) $(PROGS_CROSS),"$(bindir)")
	$(call IFw,$(LIBNILDO1) $(LIBNILDO1_U),"$(nlddir)")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/nldlib.h,"$(nlddir)/include")
	$(call $(if $(findstring .so,$(LIBNILDO)),IBw,IFw),$(LIBNILDO),"$(libdir)")
	$(call IF,$(TOPSRC)/libnld.h,"$(includedir)")
	$(call IFw,nld.1,"$(mandir)/man1")
	$(call IFw,nld-doc.info,"$(infodir)")
	$(call IFw,nld-doc.html,"$(docdir)")
ifneq "$(wildcard $(LIBNILDO1_W))" ""
	$(call IFw,$(TOPSRC)/win32/lib/*.def $(LIBNILDO1_W),"$(nlddir)/win32/lib")
	$(call IR,$(TOPSRC)/win32/include,"$(nlddir)/win32/include")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/nldlib.h,"$(nlddir)/win32/include")
endif

# uninstall
uninstall-unx:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS),"$(bindir)/$P")
	@rm -fv "$(libdir)/libnld.a" "$(libdir)/libnld.so" "$(includedir)/libnld.h"
	@rm -fv "$(mandir)/man1/nld.1" "$(infodir)/nld-doc.info"
	@rm -fv "$(docdir)/nld-doc.html"
	rm -r "$(nlddir)"

# install progs & libs on windows
install-win:
	$(call IBw,$(PROGS) $(PROGS_CROSS) $(subst libnld.a,,$(LIBNILDO)),"$(bindir)")
	$(call IF,$(TOPSRC)/win32/lib/*.def,"$(nlddir)/lib")
	$(call IFw,libnld1.a $(LIBNILDO1_W),"$(nlddir)/lib")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/nldlib.h,"$(nlddir)/include")
	$(call IR,$(TOPSRC)/win32/include,"$(nlddir)/include")
	$(call IR,$(TOPSRC)/win32/examples,"$(nlddir)/examples")
	$(call IF,$(TOPSRC)/tests/libnld_test.c,"$(nlddir)/examples")
	$(call IFw,$(TOPSRC)/libnld.h $(subst .dll,.def,$(LIBNILDO)),"$(libdir)")
	$(call IFw,$(TOPSRC)/win32/nld-win32.txt nld-doc.html,"$(docdir)")
ifneq "$(wildcard $(LIBNILDO1_U))" ""
	$(call IFw,$(LIBNILDO1_U),"$(nlddir)/lib")
	$(call IF,$(TOPSRC)/include/*.h $(TOPSRC)/nldlib.h,"$(nlddir)/lib/include")
endif

# the msys-git shell works to configure && make except it does not have install
ifeq "$(and $(CONFIG_WIN32),$(shell which install >/dev/null 2>&1 || echo no))" "no"
install-win : INSTALL = cp
install-win : INSTALLBIN = cp
endif

# uninstall on windows
uninstall-win:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS) libnld.dll,"$(bindir)/$P")
	@rm -fv $(foreach F,nld-doc.html nld-win32.txt,"$(docdir)/$F")
	@rm -fv $(foreach F,libnld.h libnld.def libnld.a,"$(libdir)/$F")
	rm -r "$(nlddir)"

# --------------------------------------------------------------------------
# other stuff

TAGFILES = *.[ch] include/*.h lib/*.[chS]
tags : ; ctags $(TAGFILES)
# cannot have both tags and TAGS on windows
ETAGS : ; etags $(TAGFILES)

# create release tarball from *current* git branch (including nld-doc.html
# and converting two files to CRLF)
NILDO-VERSION = nld-$(VERSION)
tar:    nld-doc.html
	mkdir $(NILDO-VERSION)
	( cd $(NILDO-VERSION) && git --git-dir ../.git checkout -f )
	cp nld-doc.html $(NILDO-VERSION)
	for f in nld-win32.txt build-nld.bat ; do \
	    cat win32/$$f | sed 's,\(.*\),\1\r,g' > $(NILDO-VERSION)/win32/$$f ; \
	done
	tar cjf $(NILDO-VERSION).tar.bz2 $(NILDO-VERSION)
	rm -rf $(NILDO-VERSION)
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
	rm -f nld$(EXESUF) nld_p$(EXESUF) *-nld$(EXESUF) nld.pod
	rm -f  *~ *.o *.a *.so* *.out *.log lib*.def *.exe *.dll a.out tags TAGS
	@$(MAKE) -C lib $@
	@$(MAKE) -C tests $@

distclean: clean
	rm -f config.h config.mak config.texi nld.1 nld-doc.info nld-doc.html

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
	@echo "   $(NILDO_X)"
	@echo ""
	@echo "Custom configuration:"
	@echo "   The makefile includes a file 'config-extra.mak' if it is present."
	@echo "   This file may contain some custom configuration.  For example:"
	@echo ""
	@echo "      NATIVE_DEFINES += -D..."
	@echo ""
	@echo "   Or for example to configure the search paths for a cross-compiler"
	@echo "   that expects the linux files in <nlddir>/i386-linux:"
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
