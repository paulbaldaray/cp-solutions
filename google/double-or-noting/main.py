def clean_str(s):
	ns = []
	found_one = False
	for c in s:
		if c == '0' and found_one:
			ns.append('0')
		if c == '1':
			ns.append('1')
			found_one = True
	return ''.join(ns) if ns else '0'

def not_str(s):
	ns = []
	for c in s:
		if c == '0':
			ns.append('1')
		else:
			ns.append('0')
	return clean_str(''.join(ns))

def double(s):
	ns = s + '0'
	return clean_str(ns)

def solve():
	start, end = input().split()
	vis = set()
	q = {start}
	for i in range(20):
		nq = set()
		for x in q:
			if x in vis:
				continue
			vis.add(x)
			if x == end:
				return i
			nq.add(not_str(x))
			nq.add(double(x))
		q = nq
		if not q:
			break
	return 'IMPOSSIBLE'
		
if __name__ == '__main__':
	for t in range(int(input())):
		print(f'Case #{t+1}: {solve()}')
