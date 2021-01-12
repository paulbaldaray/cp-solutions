total = 0
a, b = 1, 1
while True:
	a, b = b, a + b
	if b > 4*10**6:
		break
	if b % 2 == 0:
		total += b
print(total)
