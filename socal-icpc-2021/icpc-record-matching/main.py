import sys
input_stream = iter(list(sys.stdin)+[''])

def get_users(names, emails):
	line = next(input_stream).strip()
	while line != '':
		first, last, email = line.split()
		names.add(first.lower() + ' ' + last.lower())
		emails.add(email.lower())
		yield email, last, first
		line = next(input_stream).strip()

if __name__ == '__main__':
	users, nsets, esets = [], [set(), set()], [set(), set()]
	for user in get_users(nsets[0], esets[0]):
		users.append(user)
	for user in get_users(nsets[1], esets[1]):
		users.append(user)

	users.sort(key=lambda u : tuple(s.lower() for s in u))
	l1, l2, visited = [], [], set()
	for email, last, first in users:
		e, n = email.lower(), first.lower() + ' ' + last.lower()
		if e in visited:
			continue
		visited.add(e)
		if all(e in es for es in esets) or all(n in ns for ns in nsets):
			continue
		elif e in esets[0] or n in nsets[0]:
			l1.append(' '.join(['I', email, last, first]))
		else:
			l2.append(' '.join(['O', email, last, first]))

	for s in l1+l2:
		print(s)
	if not first and not second:
		print('No mismatches.')
