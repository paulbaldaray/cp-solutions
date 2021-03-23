'''
parse input
turn it into an object
name(args)
map name -> args.split(1)
'''
from collections import defaultdict
from sys import stdin
facts = defaultdict(list)
index = 0
iostream = [l for l in stdin]

def parseLine(output) -> list[(str, [str])]:
	global index
	if index == len(iostream):
		return False
	line = iostream[index]
	index += 1
	if line.strip() == "":
		return False
	while line.strip() != "":
		i = line.find('(')
		name = line[:i].strip()
		line = line[i+1:]
		i = line.find(')')
		args = line[:i].split(',') # may have leading spaces
		args = list(map(lambda s : s.strip(), args))
		line = line[i+1:]
		output.append((name, args))
	return True

def solve(name, args):
	ans = 0
	for fact in facts[name]:
		if len(fact) != len(args):
			continue
		var = {}
		works = True
		for a, f in zip(args, fact):
			if a == '_':
				continue
			elif not a.startswith('_'):
				if a != f:
					works = False
			else:
				if a not in var:
					var[a] = f
				elif f != var[a]:
					works = False
		ans += works
	return ans

factslist = []
querylist = []
while parseLine(factslist):
	pass
while parseLine(querylist):
	pass
for name, args in factslist:
	facts[name].append(args)
for name, args in querylist:
	print(solve(name, args))
