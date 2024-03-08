set -e

g++ 1939A.cpp -std=c++17 -o cpp

for((i = 1; i < 100; ++i)); do
    python3 gen.py > input_file
    # python3 1939A.py < input_file > myAnswer
    ./cpp < input_file > myAnswer
    cat input_file myAnswer > tmp_file
    python3 checker.py < tmp_file
done

echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
