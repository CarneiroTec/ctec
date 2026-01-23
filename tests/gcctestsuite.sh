#!/bin/sh

TESTSUITE_PATH=$HOME/gcc/gcc-3.2/gcc/testsuite/gcc.c-torture
CTEC="./ctec -B. -I. -DNO_TRAMPOLINES" 
rm -f ctec.sum ctec.log
nb_failed="0"

for src in $TESTSUITE_PATH/compile/*.c ; do
  echo $CTEC -o /tmp/test.o -c $src 
  $CTEC -o /tmp/test.o -c $src >> ctec.log 2>&1
  if [ "$?" = "0" ] ; then
     result="PASS"
  else
     result="FAIL"
     nb_failed=$(( $nb_failed + 1 ))
  fi
  echo "$result: $src"  >> ctec.sum
done

for src in $TESTSUITE_PATH/execute/*.c ; do
  echo $CTEC $src 
  $CTEC $src >> ctec.log 2>&1
  if [ "$?" = "0" ] ; then
     result="PASS"
  else
     result="FAIL"
     nb_failed=$(( $nb_failed + 1 ))
  fi
  echo "$result: $src"  >> ctec.sum
done

echo "$nb_failed test(s) failed." >> ctec.sum
echo "$nb_failed test(s) failed."
