#
# CTEC Compiler Makefile - tests
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

ifeq ($(OS),Windows_NT) # for libctec_test to find libctec.dll
 PATH := $(CURDIR)/$(TOP)$(if $(findstring :\,$(PATH)),;,:)$(PATH)
endif

RUN_CTEC = $(NATIVE_DEFINES) -run $(TOPSRC)/ctec.c $(CTECFLAGS)
DISAS = objdump -d
DUMPCTEC = (set -x; $(TOP)/ctec -vv; ldd $(TOP)/ctec; exit 1)

all test : clean-s $(TESTS)

hello-exe: ../examples/ex1.c
	@echo ------------ $@ ------------
	$(CTEC) $< -o hello$(EXESUF) && ./hello$(EXESUF) || $(DUMPCTEC)

hello-run: ../examples/ex1.c
	@echo ------------ $@ ------------
	$(CTEC) -run $< || $(DUMPCTEC)

libtest: libctec_test$(EXESUF)
	@echo ------------ $@ ------------
	./libctec_test$(EXESUF) $(CTECFLAGS)

libctec_test$(EXESUF): libctec_test.c $(LIBCTEC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%-dir:
	@echo ------------ $@ ------------
	$(MAKE) -k -C $*

# test.ref - generate using cc
test.ref: ctectest.c
	$(CC) -o ctectest.gcc $< $(NATIVE_DEFINES) $(CFLAGS) -w -O0 -std=gnu99 -fno-omit-frame-pointer
	./ctectest.gcc > $@

# auto test
test1 test1b: ctectest.c test.ref
	@echo ------------ $@ ------------
	$(CTEC) -run $< > test.out1
	@diff -u test.ref test.out1 && echo "Auto Test OK"

# iterated test2 (compile ctec then compile ctectest.c !)
test2 test2b: ctectest.c test.ref
	@echo ------------ $@ ------------
	$(CTEC) $(RUN_CTEC) $(RUN_CTEC) -run $< > test.out2
	@diff -u test.ref test.out2 && echo "Auto Test2 OK"

# iterated test3 (compile ctec then compile ctec then compile ctectest.c !)
test3 test3b: ctectest.c test.ref
	@echo ------------ $@ ------------
	$(CTEC) $(RUN_CTEC) $(RUN_CTEC) $(RUN_CTEC) -run $< > test.out3
	@diff -u test.ref test.out3 && echo "Auto Test3 OK"

test%b : CTECFLAGS += -b

# binary output test
test4: ctectest.c test.ref
	@echo ------------ $@ ------------
# object + link output
	$(CTEC) -c -o ctectest3.o $<
	$(CTEC) -o ctectest3 ctectest3.o
	./ctectest3 > test3.out
	@if diff -u test.ref test3.out ; then echo "Object Auto Test OK"; fi
# dynamic output
	$(CTEC) -o ctectest1 $<
	./ctectest1 > test1.out
	@if diff -u test.ref test1.out ; then echo "Dynamic Auto Test OK"; fi
# dynamic output + bound check
	$(CTEC) -b -o ctectest4 $<
	./ctectest4 > test4.out
	@if diff -u test.ref test4.out ; then echo "BCheck Auto Test OK"; fi
# static output
	$(CTEC) -static -o ctectest2 $<
	./ctectest2 > test2.out
	@if diff -u test.ref test2.out ; then echo "Static Auto Test OK"; fi

# use ctec to create libctec.so/.dll and the ctec(.exe) frontend and run them
dlltest:
	@echo ------------ $@ ------------
	$(CTEC) $(NATIVE_DEFINES) -DLIBCTEC_AS_DLL $(TOPSRC)/libctec.c $(LIBS) -shared -o libctec2$(DLLSUF)
	$(CTEC) $(NATIVE_DEFINES) -DONE_SOURCE=0 $(TOPSRC)/ctec.c libctec2$(DLLSUF) $(LIBS) -Wl,-rpath=. -o ctec2$(EXESUF)
	./ctec2$(EXESUF) $(CTECFLAGS) $(RUN_CTEC) -run $(TOPSRC)/examples/ex1.c
ifndef CONFIG_WIN32
	@echo ------------ $@ with PIC ------------
	$(CC) $(CFLAGS) -fPIC $(NATIVE_DEFINES) -DLIBCTEC_AS_DLL -c $(TOPSRC)/libctec.c
	$(CTEC) libctec.o $(LIBS) -shared -o libctec2$(DLLSUF)
	$(CTEC) $(NATIVE_DEFINES) -DONE_SOURCE=0 $(TOPSRC)/ctec.c libctec2$(DLLSUF) $(LIBS) -Wl,-rpath=. -o ctec2$(EXESUF)
	./ctec2$(EXESUF) $(CTECFLAGS) $(RUN_CTEC) -run $(TOPSRC)/examples/ex1.c
endif
	@rm ctec2$(EXESUF) libctec2$(DLLSUF)

memtest:
	@echo ------------ $@ ------------
	$(CC) $(CFLAGS) $(NATIVE_DEFINES) -DMEM_DEBUG=2 $(TOPSRC)/ctec.c $(LIBS) -o memtest-ctec$(EXESUF)
	./memtest-ctec$(EXESUF) $(CTECFLAGS) $(NATIVE_DEFINES) $(TOPSRC)/ctec.c $(LIBS)
	./memtest-ctec$(EXESUF) $(CTECFLAGS) $(NATIVE_DEFINES) -run $(TOPSRC)/ctec.c $(CTECFLAGS) $(TOPSRC)/tests/ctectest.c


# memory and bound check auto test
BOUNDS_OK  = 1 4 8 10 14
BOUNDS_FAIL= 2 5 7 9 11 12 13 15

btest: boundtest.c
	@echo ------------ $@ ------------
	@for i in $(BOUNDS_OK); do \
	   echo ; echo --- boundtest $$i ---; \
	   if $(CTEC) -b -run $< $$i ; then \
	       echo succeeded as expected; \
	   else\
	       echo Failed positive test $$i ; exit 1 ; \
	   fi ;\
	done ;\
	for i in $(BOUNDS_FAIL); do \
	   echo ; echo --- boundtest $$i ---; \
	   if $(CTEC) -b -run $< $$i ; then \
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
	time $(CTEC) -run $(TOPSRC)/examples/ex2.c 1238 2 3 4 10 13 4
	time ./ex3 35
	time $(CTEC) -run $(TOPSRC)/examples/ex3.c 35

weaktest: ctectest.c test.ref
	$(CTEC) -c $< -o weaktest.ctec.o
	$(CC) -c $< -o weaktest.gcc.o $(NATIVE_DEFINES) $(CFLAGS) -w -O0 -std=gnu99 -fno-omit-frame-pointer
	objdump -t weaktest.ctec.o | grep ' w ' | sed -e 's/.* \([a-zA-Z0-9_]*\)$$/\1/' | LC_ALL=C sort > weaktest.ctec.o.txt
	objdump -t weaktest.gcc.o | grep ' w ' | sed -e 's/.* \([a-zA-Z0-9_]*\)$$/\1/' | LC_ALL=C sort > weaktest.gcc.o.txt
	diff weaktest.gcc.o.txt weaktest.ctec.o.txt && echo "Weak Auto Test OK"

ex%: $(TOPSRC)/examples/ex%.c
	$(CC) -o $@ $< $(CFLAGS)

# tiny assembler testing
asmtest.ref: asmtest.S
	$(CC) -Wa,-W -o asmtest.ref.o -c asmtest.S
	objdump -D asmtest.ref.o > asmtest.ref

asmtest asmtest2: asmtest.ref
	@echo ------------ $@ ------------
	$(CTEC) $(MAYBE_RUN_CTEC) -c asmtest.S
	objdump -D asmtest.o > asmtest.out
	@if diff -u --ignore-matching-lines="file format" asmtest.ref asmtest.out ; then echo "ASM Auto Test OK"; fi

# test assembler with ctec compiled by itself
asmtest2: MAYBE_RUN_CTEC = $(RUN_CTEC)

# Check that code generated by libctec is binary compatible with
# that generated by CC
abitest-cc$(EXESUF): abitest.c $(LIBCTEC)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -w

abitest-ctec$(EXESUF): abitest.c libctec.c
	$(CTEC) -o $@ $^ $(NATIVE_DEFINES) $(LIBS)

ABITESTS := abitest-cc$(EXESUF)
ifneq ($(CONFIG_arm_eabi),yes) # not ARM soft-float
 ABITESTS += abitest-ctec$(EXESUF)
endif

abitest: $(ABITESTS)
	@echo ------------ $@ ------------
	./abitest-cc$(EXESUF) $(CTECFLAGS)
ifneq ($(CONFIG_arm_eabi),yes) # not ARM soft-float
	./abitest-ctec$(EXESUF) $(CTECFLAGS)
endif

vla_test$(EXESUF): vla_test.c
	$(CTEC) -o $@ $^

vla_test-run: vla_test$(EXESUF)
	@echo ------------ $@ ------------
	./vla_test$(EXESUF)

asm-c-connect$(EXESUF): asm-c-connect-1.c asm-c-connect-2.c
	$(CTEC) -o $@ $^

asm-c-connect-%.o: asm-c-connect-%.c
	$(CTEC) -c -o $@ $<

asm-c-connect-sep$(EXESUF): asm-c-connect-1.o asm-c-connect-2.o
	$(CTEC) -o $@ $^

asm-c-connect-test: asm-c-connect$(EXESUF) asm-c-connect-sep$(EXESUF)
	@echo ------------ $@ ------------
	./asm-c-connect$(EXESUF) > asm-c-connect.out1 && cat asm-c-connect.out1
	./asm-c-connect-sep$(EXESUF) > asm-c-connect.out2 && cat asm-c-connect.out2
	@diff -u asm-c-connect.out1 asm-c-connect.out2 && echo "ok"

cross-test :
	@echo ------------ $@ ------------
	$(TOP)/i386-ctec$(EXESUF) $(CTECFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/i386-win32-ctec$(EXESUF) $(CTECFLAGS-win) $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/x86_64-ctec$(EXESUF) $(CTECFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/x86_64-win32-ctec$(EXESUF) $(CTECFLAGS-win) $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm-ctec$(EXESUF) $(CTECFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm-wince-ctec$(EXESUF) $(CTECFLAGS-win) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/arm64-ctec$(EXESUF) $(CTECFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/c67-ctec$(EXESUF) $(CTECFLAGS-unx) -c $(TOPSRC)/examples/ex3.c && echo "ok"
	$(TOP)/i386-win32-ctec$(EXESUF) $(CTECFLAGS-win) $(TOPSRC)/win32/examples/hello_win.c && echo "ok"
	$(TOP)/x86_64-win32-ctec$(EXESUF) $(CTECFLAGS-win) $(TOPSRC)/win32/examples/hello_win.c && echo "ok"
	$(TOP)/arm-wince-ctec$(EXESUF) $(CTECFLAGS-win) -c $(TOPSRC)/win32/examples/hello_win.c && echo "ok"

# targets for development
%.bin: %.c ctec
	$(CTEC) -g -o $@ $<
	$(DISAS) $@

instr: instr.o
	objdump -d instr.o

instr.o: instr.S
	$(CC) -o $@ -c $< -O2 -Wall -g

cache: ctec_g
	cachegrind ./ctec_g -o /tmp/linpack -lm bench/linpack.c
	vg_annotate ctec.c > /tmp/linpack.cache.log

# clean
clean:
	rm -f *~ *.o *.a *.bin *.i *.ref *.out *.out? *.out?b *.cc *.gcc
	rm -f *-cc *-gcc *-ctec *.exe hello libctec_test vla_test ctectest[1234]
	rm -f asm-c-connect$(EXESUF)
	rm -f ex? ctec_g weaktest.*.txt *.def
	@$(MAKE) -C tests2 $@
	@$(MAKE) -C pp $@

# silent clean, used before running tests
clean-s:
	@$(MAKE) -s --no-print-directory clean
