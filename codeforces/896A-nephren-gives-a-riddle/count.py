zero = "What are you doing at the end of the world? Are you busy? Will you save us?",
begin = "What are you doing while sending \"",
middle = "\"? Are you busy? Will you send \"",
end = "\"?";

def size(n):
	# if n <= 62:
		# return 1 << 63
	a, b = len(zero), len(begin)+ len(middle)+ len(end)
	ans = (1 << n)*a + ((1 << n) - 1)*b
	assert ans <= 1 << 63
	return ans

print(size(60))
