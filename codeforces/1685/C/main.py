from random import randrange
N = randrange(3, 10)
count = N
l = []
item = 1
while count > 0:
    for _ in range(randrange(1, 4)):
        l.append(item)
        count -= 1
    item += 1
print(1)
print(len(l))
print(' '.join(map(str, l)))
