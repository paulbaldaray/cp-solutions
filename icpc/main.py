print(*(lambda g:[g.count(i)for i in[0,1,2]])(list(map(lambda l:(lambda a,b:b-a-1)(*map(lambda c:'RSP'.find(c),l.split()))%3,__import__('sys').stdin))))
