for t in range(int(input())):
	x, y = map(int, input().split())
	path = []
	print(f'Case #{t+1}: ',end='')
	while x or y:
		if x%2 == y%2:
			break
		idx = ((x+y)//2^x^y)&1^bool({x,y}-{-1,0,1})+y%2*2
		path.append('WESN'[idx])
		x, y = (x+1,x-1,x,x)[idx]//2, (y,y,y+1,y-1)[idx]//2
	else:
		print(''.join(path))
		continue
	print('IMPOSSIBLE')
