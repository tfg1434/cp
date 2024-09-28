#!/bin/sh

g++ -std=c++17 identity-theft-dp.cpp -O2 -o sol
g++ -std=c++17 identity-theft-bfs.cpp -O2 -o code

for (( i = 0; i < 100; i += 1 )); do
    if [ $(( $i % 10 )) -eq 0 ]; then
        echo "Running test $i"
    fi
    python gen.py > j
    ./sol < j > answer
    ./code < j > suspect
    if ! cmp -s answer suspect ; then
        echo "WA on test $i"
        echo "Test"
        cat j
        echo "Got"
        cat suspect
        echo "Expected"
        cat answer
        break
    fi
done
