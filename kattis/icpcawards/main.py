N = int(input())
vis = set()
winners = 12
for i in range(N):
	uni, name = input().split()
	if winners and uni not in vis:
		winners -= 1
		print(uni, name)
		vis.add(uni)
	
