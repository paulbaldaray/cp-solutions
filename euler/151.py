def addOne(nums):
	return list(map(lambda x : x + 1, nums))
def expected(b, papers, total):
	if b == 0:
		return total
	ans = 0
	x = int(sum(papers) == 1)
	for i in range(5):
		if papers[i]:
			npapers = papers[:i] + [papers[i] - 1] + addOne(papers[i+1:])
			ans += papers[i] * expected(b-1, npapers, total + x)
	return ans / sum(papers)
print(round(expected(15, [1, 0, 0, 0, 0], 0), 6) - 1)
