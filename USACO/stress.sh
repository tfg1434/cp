set -e
g++ outofsort.cpp -std=c++17 -o code
g++ sortgen.cpp -std=c++17 -o gen
# g++ brute.cpp -std=c++17 -o brute
for((i = 1; i < 100; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    cat input_file
    cat myAnswer
    # cmp --silent myAnswer correctAnswer || break
    # echo "Passed test: "  $i
done

# echo "WA on the following test:"
# cat input_file
# echo "Your answer is:"
# cat myAnswer
# echo "Correct answer is:"
# cat correctAnswer
