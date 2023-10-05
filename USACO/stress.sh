set -e
g++ modernArtIII.cpp -std=c++17 -o code
g++ gen.cpp -std=c++17 -o gen
g++ brute.cpp -std=c++17 -o brute
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    cmp --silent myAnswer correctAnswer || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
