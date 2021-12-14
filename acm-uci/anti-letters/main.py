from collections import defaultdict
S, P = input(), input()
target = [0]*26
for c in P:
	if c.isupper():
		target[ord(c)-ord('A')] -= 1
	else:
		target[ord(c)-ord('a')] += 1
ans = 0
lookup = defaultdict(int)
lookup[(0,)*26] = 1
pfx = [0]*26
for c in S:
	if c.isupper():
		pfx[ord(c)-ord('A')] -= 1
	else:
		pfx[ord(c)-ord('a')] += 1
	difference = tuple(x - y for x, y in zip(pfx, target))
	if difference in lookup:
		ans += lookup[difference]
	lookup[tuple(pfx)] += 1
print(ans)
