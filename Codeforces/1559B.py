T = int(input())
for _ in range(T):
    n = int(input())
    s = input()

    while "?" in s:
        if s == "?" * len(s):
            s = "BR" * len(s)
            s = s[:len(s)//2]

        s = s.replace("?R", "BR")
        s = s.replace("R?", "RB")
        s = s.replace("B?", "BR")
        s = s.replace("?B", "RB")

    print(s)
