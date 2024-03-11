import re

def solve():
    n = int(input())
    s = input()
    Pie = [m.start() for m in re.finditer("pie", s)]
    Map = [m.start() for m in re.finditer("map", s)]
    Mapie = [m.start() for m in re.finditer("mapie", s)]

    print(len(Pie) + len(Map) - len(Mapie))

for _ in range(int(input())):
    solve()
