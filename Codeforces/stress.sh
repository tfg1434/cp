set -e
g++ 1525D.cpp -std=c++17 -o code
g++ gen.cpp -std=c++17 -o gen
g++ 1525Dedi.cpp -std=c++17 -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff myAnswer correctAnswer > /dev/null || break
    cat myAnswer
    cat correctAnswer
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
