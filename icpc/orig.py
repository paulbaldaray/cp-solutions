print(*__import__('functools').reduce(lambda a,b:[a[i]+b[i]for i in[0,1,2]],[(x==(y+1)%3,(x+1)%3==y,x==y)for x,y in map(lambda z:map(lambda c:'RPS'.find(c),z.split()),__import__('sys').stdin)],[0]*3))

