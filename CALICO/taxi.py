from typing import Dict, List

def solve(city: str, N: int, taxis: List[Dict]) -> None:
    '''
    Identify the cheapest ride option for all integer distances from the given set of taxis.
    
    city: the name of the city you're in
    N: the number of ciphers
    taxis: the ride options available to you
    '''
    def intersect_next(tx, tx_set):
        next_x = float('inf')
        m1 = tx['m']
        b1 = tx['b']
        for t in tx_set:
            m2 = t['m']
            b2 = t['b']

            if (m1 == m2): continue
            next_x = min(next_x, (b2-b1)/(m1-m2))
        return next_x
            

        #  k = intersect_with(tx['m'], tx['b'])
        #  next_x = min([k(t['m'], t['b']) for t in tx_set])
        #  return next_x
    
    def intersect_with(m1, b1):
        def given(m2, b2):
            #  if m2 == m1 and b2 != b1:
                #  return None
            if m2 == m1:
                return float('inf')
            x = (b2 - b1) / (m1 - m2)
            return x
        return given
    
    def val_at(x):
        def val(m, b):
            return m * x + b
        return val
    
    taxis.sort(key= lambda t : t['m'])
    cur_x = 0
    val = val_at(cur_x)
    cur_best = min(taxis, key= lambda x : val(x['m'], x['b']))
    while len(taxis) > 0 and taxis[-1]['m'] >= cur_best['m']:
        taxis.pop(-1)
    print(len(taxis))
    
    ranges = []
    while len(taxis) > 0:
        next_x = intersect_next(cur_best, taxis)
        print(cur_best['name'])
        print(next_x)
        if next_x == int(next_x):
            next_x -= 1
        ranges.append(((cur_x, int(next_x)), cur_best))
        cur_x = int(next_x) + 1
        val = val_at(cur_x)
        cur_best = min(taxis, key= lambda x : val(x['m'], x['b']))
        while len(taxis) > 0 and taxis[-1]['m'] >= cur_best['m']:
            taxis.pop(-1)
    ranges.append(((cur_x, float('inf')), cur_best))

    print('{}:'.format(city))
    for r in ranges:
        coord, t = r
        x1, x2 = coord
        if x2 == float('inf'):
            print('{}+: {}'.format(x1, t['name']))
        elif x1 == x2:
            print('{}: {}'.format(x1, t['name']))
        else:
            print('{}-{}: {}'.format(x1, x2, t['name']))

def main():
    T = int(input())
    for _ in range(T):
        info = input().strip().split(' ')
        city, N = info[0], int(info[1])
        taxis = []
        for _ in range(N):
            taxi = input().strip().split(' ')
            taxis.append({'name': taxi[0], 'b': int(taxi[1]), 'm': int(taxi[2])})
        solve(city, N, taxis)
        # Don't forget the blank line in between test cases!
        input()
        # Don't forget the blank line in between outputs!
        print()

if __name__ == '__main__':
    main()
