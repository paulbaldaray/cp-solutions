[(lambda X, R, C : print(f'Case #{t+1}:', 'RICHARD' if (((min(R, C)*max(R, C)) % X != 0) or (X == 3 and min(R, C) == 1) or (X == 4 and min(R, C) <= 2) or (X == 5 and ((min(R, C) <= 2) or ((min(R, C), max(R, C)) == (3, 5)))) or (X == 6 and min(R, C) <= 3) or (X >= 7)) else 'GABRIEL'))(*map(int, input().split())) for t in range(int(input()))]
