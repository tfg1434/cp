def solve():
    s = input()

    # the sum of indices of all 'b's in bes...
    # where the last bessie i have ACHIEVEd
    # is 0..j
    ans = 0
    dp = [[0]*6 for _ in range(len(s)+1)]
    for i in range(len(s)):
        dp[i+1] = dp[i][:]

        for j in range(6):
            if j == 5:
                if s[i] == "b":
                    dp[i+1][0] = dp[i][j]+(i+1)
                continue

            if s[i] == "bessie"[j+1]:
                dp[i+1][j+1] = dp[i][j]

        ans += dp[i+1][5]
    
    print(ans)


solve()
