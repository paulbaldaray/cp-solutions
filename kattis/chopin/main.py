import sys
keys = (('Bb', 'A#'), ('Db', 'C#'), ('Eb', 'D#'), ('Gb', 'F#'), ('Ab', 'G#'))
io = (line.split() for line in sys.stdin)
for i, (k, t) in enumerate(io):
	print (f'Case {i+1}: ', end='')
	for k1, k2 in keys:
		if k == k1:
			print(f'{k2} {t}')
			break
		elif k == k2:
			print(f'{k1} {t}')
			break
	else:
		print('UNIQUE')
