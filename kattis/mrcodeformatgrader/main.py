C, N = map(int, input().split())
err = list(map(int, input().split()))
error = [[0, 0]]
correct = [[0, 0]]
for e in err:
	if e == error[-1][1] + 1:
		if e == 1:
			error.append([1, 1])
		else:
			error[-1][1] += 1
	else:
		correct.append([error[-1][1] + 1, e - 1])
		error.append([e, e])
if error[-1][1] != C:
	correct.append([error[-1][1] + 1, C])
def format_range(x):
	if x[0] == x[1]:
		return str(x[1])
	return str(x[0]) + '-' + str(x[1])
def format_list(l):
	if len(l) <= 1:
		return format_range(l[0]) if l else ''
	return ', '.join(map(format_range, l[:-1])) + ' and ' + format_range(l[-1])
print('Errors: ' + format_list(error[1:]))
print('Correct: ' + format_list(correct[1:]))
