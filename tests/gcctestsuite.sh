#!/bin/sh

TESTSUITE_PATH=$HOME/gcc/gcc-3.2/gcc/testsuite/gcc.c-torture
NILDO="./nld -B. -I. -DNO_TRAMPOLINES" 
rm -f nld.sum nld.log
nb_failed="0"

for src in $TESTSUITE_PATH/compile/*.c ; do
  echo $NILDO -o /tmp/test.o -c $src 
  $NILDO -o /tmp/test.o -c $src >> nld.log 2>&1
  if [ "$?" = "0" ] ; then
     result="PASS"
  else
     result="FAIL"
     nb_failed=$(( $nb_failed + 1 ))
  fi
  echo "$result: $src"  >> nld.sum
done

for src in $TESTSUITE_PATH/execute/*.c ; do
  echo $NILDO $src 
  $NILDO $src >> nld.log 2>&1
  if [ "$?" = "0" ] ; then
     result="PASS"
  else
     result="FAIL"
     nb_failed=$(( $nb_failed + 1 ))
  fi
  echo "$result: $src"  >> nld.sum
done

echo "$nb_failed test(s) failed." >> nld.sum
echo "$nb_failed test(s) failed."
