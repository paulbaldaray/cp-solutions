from sys import stdin
from collections import defaultdict
index = 0
iostream = [l for l in stdin]
total = []
def lower(first, last):
	return first.lower() + last.lower()
def getline(nset, eset):
	global index
	if index == len(iostream):
		return False
	line = iostream[index]
	index += 1
	if line.strip() == "":
		return False
	first, last, email = line.strip().split()
	nset.add(lower(first, last))
	eset.add(email.lower())
	total.append((email, last, first))
	return True

n1, e1, n2, e2 = set(), set(), set(), set()
while getline(n1, e1):
	pass
while getline(n2, e2):
	pass
flist, slist = [], []
total.sort(key=lambda x: (x[0].lower(), x[1].lower(), x[2].lower()))
visited = set()
for email, last, first in total:
	e = email.lower()
	n = lower(first, last)
	x = e+' '+n
	if x in visited:
		continue
	visited.add(x)
	if (e in e1 and e in e2) or (n in n1 and n in n2):
		continue
	elif (e in e1 and not e in e2) or (n in n1 and not n in n2):
		flist.append(' '.join(['I', email, last, first]))
	else:
		slist.append(' '.join(['O', email, last, first]))
for s in flist:
	print(s)
for s in slist:
	print(s)
if not slist and not flist:
	print('No mismatches.')
