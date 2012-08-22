#!/bin/bash
# Bash script for running Miavita Sleeptest - Duarte Barbosa.

KERNEL=$(uname -r)
ITERATIONS=10
SECONDS=( 0 0 0 2 )
NANOSECONDS=( 2000 1000000 100000000 0 )
INFO=( 2us 1ms 100ms 2s )

echo $KERNEL

echo "Compiling.."
gcc -lrt -O3 -Wall sleeptest_v2.c -o sleeptest
gcc -O3 frycpu.c -o fryit
gcc -lrt -O3 header.c -o header

mkdir $KERNEL
cat /proc/timer_list | grep "resolution" > $KERNEL/resolution

echo -e "\nTests\n"
mkdir $KERNEL/results

for((i=0; i < 4; i++)) do
	echo ${SECONDS[i]} "Seconds "${NANOSECONDS[i]} "Nanoseconds"
	for((j = 1; j <= ITERATIONS; j++)) do
		echo "Iteration:"$j
		./header ${SECONDS[i]} ${NANOSECONDS[i]} >> $KERNEL/resolution
		./sleeptest ${SECONDS[i]} ${NANOSECONDS[i]} >> $KERNEL/results/${INFO[i]}
	done
done

echo -e "\nTests under Load\n"
mkdir $KERNEL/results_load

./fryit &
for((i=0; i < 4; i++)) do
	echo ${SECONDS[i]} "Seconds "${NANOSECONDS[i]} "Nanoseconds"
	for((j = 1; j <= ITERATIONS; j++)) do
		echo "Iteration:"$j
		./header ${SECONDS[i]} ${NANOSECONDS[i]} >> $KERNEL/resolution
		./sleeptest ${SECONDS[i]} ${NANOSECONDS[i]} >> $KERNEL/results_load/${INFO[i]}
	done
done

echo "Done"

killall fryit
echo "FryIt Terminated"

rm sleeptest fryit header
exit
