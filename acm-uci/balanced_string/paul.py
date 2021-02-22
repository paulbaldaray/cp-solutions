import string, collections, bisect
def longestBalancedString(s: str) -> str:
	letters = list(zip(string.ascii_lowercase, string.ascii_uppercase))
	lookup = collections.defaultdict(list)
	for l, u in letters:
		lookup[l].append(len(s))
		lookup[u].append(len(s))
	for i in range(len(s)-1, -1, -1):
		lookup[s[i]].append(i)
	first = last = 0
	for i in range(len(s)):
		ranges = []
		for l, u in letters:
			lo = min(lookup[l][-1], lookup[u][-1])
			hi = max(lookup[l][-1], lookup[u][-1])
			if lo != len(s):
				ranges.append((hi, lo))
			if lookup[l][-1] == i:
				lookup[l].pop()
			if lookup[u][-1] == i:
				lookup[u].pop()
		ranges.sort()
		j = len(s)
		for r, l in reversed(ranges):
			if r >= j:
				j = min(j, l)
		if last - first < j - i:
			last, first = j, i
	return s[first:last]

print(longestBalancedString(input()))
