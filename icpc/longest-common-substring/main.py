N = int(input())
s = input()
subs = set()
for i in range(len(s)):
	for j in range(len(s)):
		subs.add(s[i:j+1])
for i in range(N-1):
	s = input()
	next_subs = set()
	for sub in subs:
		if s.find(sub) != -1:
			next_subs.add(sub)
	subs = next_subs
print(max(map(len, subs)) if subs else 0)
