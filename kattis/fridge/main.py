def solve(s) -> str:
	counts = {c : 0 for c in '0123456789'}
	for c in s:
		counts[c] += 1
	for c in '123456789':
		if counts[c] == 0:
			return c
	num = min(counts.values())
	ans = ''
	for c in '1234567890':
		if num == counts[c]:
			ans = c
			break
	assert(ans != '')
	if ans == '0':
		return '1'+'0'*(num+1)
	else:
		return ans*(num+1)

print(solve(input()))
