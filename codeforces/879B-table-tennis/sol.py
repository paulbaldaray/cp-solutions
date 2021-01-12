n, k = map(int, input().split())
players = list(map(int, input().split()))
ans = players[0]
wins = 0
for x in players[1:]:
	if ans < x:
		ans, wins = x, 1
	else:
		wins += 1
	if wins == k:
		break
print(ans)
