import functools
to_num = {c:i+1 for i, c in enumerate('1ijk')}
to_let = {i+1:c for i, c in enumerate('1ijk')}
matrix = [[],
	[0, 1, 2,3, 4],
	[0, 2,-1,4,-3],
	[0, 3,-4,-1,2],
	[0, 4,3,-2,-1],
]

def sign(x):
	return -1 if x.startswith('-') else 1

def multstr(x, y):
	sx, sy = sign(x), sign(y)
	x, y = x[-1], y[-1]
	s = sx*sy*matrix[to_num[x]][to_num[y]]
	return ('-' if s < 0 else '') + to_let[abs(s)]

def exp(s, e):
	if e == 0:
		return '1'
	sp = exp(s, e//2)
	if e & 1:
		return multstr(multstr(sp, sp), s)
	return multstr(sp, sp)

def find(T, S, V, X):
	vis = set()
	current = '1'
	while current != V and X >= 0:
		if not T:
			if current in vis:
				return T, -1
			vis.add(current)
			T = list(S)
			X -= 1
		current = multstr(current, T.pop())
	return (T, X) if T else (list(S), X-1)

def solve():
	(_, X), S = map(int, input().split()), input()
	if exp(functools.reduce(multstr, S, '1'), X) != '-1':
		return False
	T, X = find([], S[::-1], 'i', X)
	return X >= 0 and find(T, S[::-1], 'j', X)[1] >= 0

if __name__ == '__main__':
	for i in range(int(input())):
		print(f'Case #{i+1}:','YES' if solve() else 'NO')
