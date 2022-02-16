for t in range(int(input())):
	s = input()
	x = int(s, 8)
	played = [[0]*3 for _ in range(3)]
	ptype = [[0]*3 for _ in range(3)]
	moves_played = 0
	for i in range(9):
		played[i//3][i%3] = bool((1 << i) & (x))
		moves_played += int(bool((1 << i) & (x)))
	for i in range(9):
		ptype[i//3][i%3] = bool((1 << (i + 9)) & (x))
	def check_win(t):
		for r in range(3):
			if all([played[r][c] and ptype[r][c] == t for c in range(3)]):
				return True
		for c in range(3):
			if all([played[r][c] and ptype[r][c] == t for r in range(3)]):
				return True
		if all([played[i][i] and ptype[i][i] == t for i in range(3)]):
			return True
		if all([played[i][3-i-1] and ptype[i][3-i-1] == t for i in range(3)]):
			return True
		return False
	if check_win(True):
		print('X wins')
	elif check_win(False):
		print('O wins')
	elif moves_played == 9:
		print('Cat\'s')
	else:
		print('In progress')
