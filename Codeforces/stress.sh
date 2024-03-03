set -e
g++ ac.cpp -std=c++17 -o ac
for((i = 1; i < 1000; ++i)); do
    python3 gen.py > input_file
    python3 UGC_C.py < input_file > myAnswer
    ./ac < input_file > correctAnswer

    cat myAnswer
    cat correctAnswer

    diff myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done

echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
