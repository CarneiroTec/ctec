#
# NILDO Compiler Makefile - tests
#

TOP = ..
include $(TOP)/Makefile
VPATH = $(TOPSRC)/tests $(TOPSRC) $(TOP)
CFLAGS := $(filter-out -W% -g% -O%,$(CFLAGS)) -I$(TOPSRC) $(LDFLAGS)

# what tests to run
TESTS = \
 hello-exe \
 hello-run \
 libtest \
 test3 \
 memtest \
 dlltest \
 abitest \
 asm-c-connect-test \
 vla_test-run \
 cross-test \
 tests2-dir \
 pp-dir

BTESTS = test1b test3b btest

# test4 -- problem with -static
# asmtest / asmtest2 -- minor differences with gcc
# btest -- works on i386 (including win32)

# bounds-checking is supported only on i386
ifneq ($(ARCH),i386)
 TESTS := $(filter-out $(BTESTS),$(TESTS))
endif
ifdef CONFIG_WIN32
 TESTS := $(filter-out $(BTESTS),$(TESTS))
endif
ifdef CONFIG_OSX # -run only
 TESTS := hello-run libtest tests2-dir pp-dir
endif
ifeq (,$(filter arm64 i386 x86_64,$(ARCH)))
 TESTS := $(filter-out vla_test-run,$(TESTS))
endif
ifeq ($(CONFIG_arm_eabi),yes)
 TESTS := $(filter-out test3,$(TESTS))
endif
ifeq (,$(filter i386 x86_64,$(ARCH)))
 TESTS := $(filter-out dlltest asm-c-connect-test,$(TESTS))
endif
ifndef CONFIG_cross
 TESTS := $(filter-out cross-%,$(TESTS))
endif

ifeq ($(OS),Windows_NT) # for libnld_test to find libnld.dll
 PATH := $(CURDIR)/$(TOP)$(if $(findstring :\,$(PATH)),;,:)$(PATH)
endif

RUN_NILDO = $(NATIVE_DEFINES) -run $(TOPSRC)/nld.c $(NILDOFLAGS)
DISAS = objdump -d
DUMPNILDO = (set -x; $(TOP)/nld -vv; ldd $(TOP)/nld; exit 1)

all test : clean-s $(TESTS)

hello-exe: ../examples/ex1.c
	@echo ------------ $@ ------------
	$(NILDO) $< -o hello$(EXESUF) && ./hello$(EXESUF) || $(DUMPNILDO)

hello-run: ../examples/ex1.c
	@echo ------------ $@ ------------
	$(NILDO) -run $< || $(DUMPNILDO)

libtest: libnld_test$(EXESUF)
	@echo ------------ $@ ------------
	./libnld_test$(EXESUF) $(NILDOFLAGS)

libnld_test$(EXESUF): libnld_test.c $(LIBNILDO)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%-dir:
	@echo ------------ $@ ------------
	$(MAKE) -k -C $*

# test.ref - generate using cc
test.ref: nldtest.c
	$(CC) -o nldtest.gcc $< $(NATIVE_DEFINES) $(CFLAGS) -w -O0 -std=gnu99 -fno-omit-frame-pointer
	./nldtest.gcc > $@

# auto test
test1 test1b: nldtest.c test.ref
	@echo ------------ $@ ------------
	$(NILDO) -run $< > test.out1
	@diff -u test.ref test.out1 && echo "Auto Test OK"

# iterated test2 (compile nld then compile nldtest.c !)
test2 test2b: nldtest.c test.ref
	@echo ------------ $@ ------------
	$(NILDO) $(RUN_NILDO) $(RUN_NILDO) -run $< > test.out2
	@diff -u test.ref test.out2 && echo "Auto Test2 OK"

# iterated test3 (compile nld then compile nld then compile nldtest.c !)
test3 test3b: nldtest.c test.ref
	@echo ------------ $@ ------------
	$(NILDO) $(RUN_NILDO) $(RUN_NILDO) $(RUN_NILDO) -run $< > test.out3
	@diff -u test.ref test.out3 && echo "Auto Test3 OK"

test%b : NILDOFLAGS += -b

# binary output test
test4: nldtest.c test.ref
	@echo ------------ $@ ------------
# object + link output
	$(NILDO) -c -o nldtest3.o $<
	$(NILDO) -o nldtest3 nldtest3.o
	./nldtest3 > test3.out
	@if diff -u test.ref test3.out ; then echo "Object Auto Test OK"; fi
# dynamic output
	$(NILDO) -o nldtest1 $<
	./nldtest1 > test1.out
	@if diff -u test.ref test1.out ; then echo "Dynamic Auto Test OK"; fi
# dynamic output + bound check
	$(NILDO) -b -o nldtest4 $<
	./nldtest4 > test4.out
	@if diff -u test.ref test4.out ; then echo "BCheck Auto Test OK"; fi
# static output
	$(NILDO) -static -o nldtest2 $<
	./nldtest2 > test2.out
	@if diff -u test.ref test2.out ; then echo "Static Auto Test OK"; fi

# use nld to create libnld.so/.dll and the nld(.exe) frontend and run them
dlltest:
	@echo ------------ $@ ------------
	$(NILDO) $(NATIVE_DEFINES) -DLIBNILDO_AS_DLL $(TOPSRC)/libnld.c $(LIBS) -shared -o libnld2$(DLLSUF)
	$(NILDO) $(NATIVE_DEFINES) -DONE_SOURCE=0 $(TOPSRC)/nld.c libnld2$(DLLSUF) $(LIBS) -Wl,-rpath=. -o nld2$(EXESUF)
	./nld2$(EXESUF) $(NILDOFLAGS) $(RUN_NILDO) -run $(TOPSRC)/examples/ex1.c
ifndef CONFIG_WIN32
	@echo ------------ $@ with PIC ------------
	$(CC) $(CFLAGS) -fPIC $(NATIVE_DEFINES) -DLIBNILDO_AS_DLL -c $(TOPSRC)/libnld.c
	$(NILDO) libnld.o $(LIBS) -shared -o libnld2$(DLLSUF)
	$(NILDO) $(NATIVE_DEFINES) -DONE_SOURCE=0 $(TOPSRC)/nld.c libnld2$(DLLSUF) $(LIBS) -Wl,-rpath=. -o nld2$(EXESUF)
	./nld2$(EXESUF) $(NILDOFLAGS) $(RUN_NILDO) -run $(TOPSRC)/examples/ex1.c
endif
	@rm nld2$(EXESUF) libnld2$(DLLSUF)

memtest:
	@echo ------------ $@ ------------
	$(CC) $(CFLAGS) $(NATIVE_DEFINES) -DMEM_DEBUG=2 $(TOPSRC)/nld.c $(LIBS) -o memtest-nld$(EXESUF)
	./memtest-nld$(EXESUF) $(NILDOFLAGS) $(NATIVE_DEFINES) $(TOPSRC)/nld.c $(LIBS)
	./memtest-nld$(EXESUF) $(NILDOFLAGS) $(NATIVE_DEFINES) -run $(TOPSRC)/nld.c $(NILDOFLAGS) $(TOPSRC)/tests/nldtest.c


# memory and bound check auto test
BOUNDS_OK  = 1 4 8 10 14
BOUNDS_FAIL= 2 5 7 9 11 12 13 15

btest: boundtest.c
	@echo ------------ $@ ------------
	@for i in $(BOUNDS_OK); do \
	   echo ; echo --- boundtest $$i ---; \
	   if $(NILDO) -b -run $< $$i ; then \
	       echo succeeded as expected; \
	   else\
	       echo Failed positive test $$i ; exit 1 ; \
	   fi ;\
	done ;\
	for i in $(BOUNDS_FAIL); do \
	   echo ; echo --- boundtest $$i ---; \
	   if $(NILDO) -b -run $< $$i ; then \
	       echo Failed negative test $$i ; exit 1 ;\
	   else\
	       echo failed as expected; \
	   fi ;\
	done ;\
	echo; echo Bound test OK

# speed test
speedtest: ex2 ex3
	@echo ------------ $@ ------------
	time ./ex2 1238 2 3 4 10 13 4
	time $(NILDO) -run $(TOPSRC)/examples/ex2.c 1238 2 3 4 10 13 4
	time ./ex3 35
	time $(NILDO) -run $(TOPSRC)/examples/ex3.c 35

weaktest: nldtest.c test.ref
	$(NILDO) -c $< -o weaktest.nld.o
	$(CC) -c $< -o weaktest.gcc.o $(NATIVE_DEFINES) $(CFLAGS) -w -O0 -std=gnu99 -fno-omit-frame-pointer
	objdump -t weaktest.nld.o | grep ' w ' | sed -e 's/.* \([a-zA-Z0-9_]*\)$$/\1/' | LC_ALL=C sort > weaktest.nld.o.txt
	objdump -t weaktest.gcc.o | grep ' w ' | sed -e 's/.* \([a-zA-Z0-9_]*\)$$/\1/' | LC_ALL=C sort > weaktest.gcc.o.txt
	diff weaktest.gcc.o.txt weaktest.nld.o.txt && echo "Weak Auto Test OK"

ex%: $(TOPSRC)/examples/ex%.c
	$(CC) -o $@ $< $(CFLAGS)

# tiny assembler testing
asmtest.ref: asmtest.S
	$(CC) -Wa,-W -o asmtest.ref.o -c asmtest.S
	objdump -D asmtest.ref.o > asmtest.ref

asmtest asmtest2: asmtest.ref
	@echo ------------ $@ ------------
	$(NILDO) $(MAYBE_RUN_NILDO) -c asmtest.S
	objdump -D asmtest.o > asmtest.out
	@if diff -u --ignore-matching-lines="file format" asmtest.ref asmtest.out ; then echo "ASM Auto Test OK"; fi

# test assembler with nld compiled by itself
asmtest2: MAYBE_RUN_NILDO = $(RUN_NILDO)

# Check that code generated by libnld is binary compatible with
# that generated by CC
abitest-cc$(EXESUF): abitest.c $(LIBNILDO)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -w

abitest-nld$(EXESUF): abitest.c libnld.c
	$(NILDO) -o $@ $^ $(NATIVE_DEFINES) $(LIBS)

ABITESTS := abitest-cc$(EXESUF)
ifneq ($(CONFIG_arm_eabi),yes) # not ARM soft-float
 ABITESTS += abitest-nld$(EXESUF)
endif

abitest: $(ABITESTS)
	@echo ------------ $@ ------------
	./abitest-cc$(EXESUF) $(NILDOFLAGS)
ifneq ($(CONFIG_arm_eabi),yes) # not ARM soft-float
	./abitest-nld$(EXESUF) $(NILDOFLAGS)
endif

vla_test$(EXESUF): vla_test.c
	$(NILDO) -o $@ $^

vla_test-run: vla_test$(EXESUF)
	@echo ------------ $@ ------------
	./vla_test$(EXESUF)

asm-c-connect$(EXESUF): asm-c-connect-1.c asm-c-connect-2.c
	$(NILDO) -o $@ $^

asm-c-connect-%.o: asm-c-connect-%.c
	$(NILDO) -c -o $@ $<

asm-c-connect-sep$(EXESUF): asm-c-connect-1.o asm-c-connect-2.o
	$(NILDO) -o $@ $^

asm-c-connect-test: asm-c-connect$(EXESUF) asm-c-connect-sep$(EXESUF)
	@echo ------------ $@ ------------
	./asm-c-connect$(EXESUF) > asm-c-connect.out1 && cat asm-c-connect.out1
	./asm-c-connect-sep$(EXESUF) > asm-c-connect.out2 && cat asm-c-connect.out2
	@diff -u asm-c-connect.out1 asm-c-connect.out2 && echo "ok"

cross-test :
	@echo ------------ $@ ------------
	$(TOP)/i386-nld$(EXESUF) $(NILDOFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/i386-win32-nld$(EXESUF) $(NILDOFLAGS-win) $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/x86_64-nld$(EXESUF) $(NILDOFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/x86_64-win32-nld$(EXESUF) $(NILDOFLAGS-win) $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm-nld$(EXESUF) $(NILDOFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm-wince-nld$(EXESUF) $(NILDOFLAGS-win) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm64-nld$(EXESUF) $(NILDOFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/c67-nld$(EXESUF) $(NILDOFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/i386-win32-nld$(EXESUF) $(NILDOFLAGS-win) $(TOPSRC)/win32/examples/hello_win.c && echo "ok"
	$(TOP)/x86_64-win32-nld$(EXESUF) $(NILDOFLAGS-win) $(TOPSRC)/win32/examples/hello_win.c && echo "ok"
	$(TOP)/arm-wince-nld$(EXESUF) $(NILDOFLAGS-win) -c $(TOPSRC)/win32/examples/hello_win.c && echo "ok"

# targets for development
%.bin: %.c nld
	$(NILDO) -g -o $@ $<
	$(DISAS) $@

instr: instr.o
	objdump -d instr.o

instr.o: instr.S
	$(CC) -o $@ -c $< -O2 -Wall -g

cache: nld_g
	cachegrind ./nld_g -o /tmp/linpack -lm bench/linpack.c
	vg_annotate nld.c > /tmp/linpack.cache.log

# clean
clean:
	rm -f *~ *.o *.a *.bin *.i *.ref *.out *.out? *.out?b *.cc *.gcc
	rm -f *-cc *-gcc *-nld *.exe hello libnld_test vla_test nldtest[1234]
	rm -f asm-c-connect$(EXESUF)
	rm -f ex? nld_g weaktest.*.txt *.def
	@$(MAKE) -C tests2 $@
	@$(MAKE) -C pp $@

# silent clean, used before running tests
clean-s:
	@$(MAKE) -s --no-print-directory clean
