set -e
g++ G_pdp_O.cpp -std=c++17 -o code
g++ gen.cpp -std=c++17 -o gen
g++ G_pdp_O_edi.cpp -std=c++17 -o brute
for((i = 1; i < 20; ++i)); do
    ./gen > input_file
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
