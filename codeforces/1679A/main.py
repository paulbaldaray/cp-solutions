for t in range(int(input())):
    n = int(input())
    if n % 2 or n < 4:
        print(-1)
        continue
    if n % 4 == 2:
        hi = (n-6)//4 + 1
    else:
        hi = (n)//4
    if n % 6 == 4:
        lo = (n-4)//6 + 1
    elif n % 6 == 2:
        lo = (n-8)//6 + 2
    else:
        lo = (n)//6
    print(lo, hi)
