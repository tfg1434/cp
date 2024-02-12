set -e
g++ 1637D_gen.cpp -std=c++17 -o gen
g++ 1637D_brute.cpp -std=c++17 -o brute
for((i = 1; i < 100; ++i)); do
    ./gen > input_file
    python3 1637D.py < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
