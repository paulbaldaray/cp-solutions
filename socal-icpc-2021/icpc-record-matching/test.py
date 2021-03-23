from sys import stdin

lines = [l.strip() for l in stdin.readlines()]

records = {}
first_mismatches, second_mismatches = [], []

first_group = lines[:lines.index('')]
second_group = lines[lines.index('')+1:]

for line in first_group:
    name = [i for i in line[:2]]
    email = line[-1]
    records[email] = name

for line in second_group:
    name = [i for i in line[:2]]
    space_index = name.index(' ')
    first, last = name[:space_index], name[space_index:]
    email = line[-1]
    for e, n in records.items():
        space_index = n.index(' ')
        i_first, i_last = n[:space_index], n[space_index:]
        if name.lower() != n.lower() or email.lower() != e.lower():
            first_mismatches.append(['I', e, i_last, i_first])
            second_mismatches.append(['O', email, last, first])

if first_mismatches and second_mismatches:
    for m in first_mismatches:
        print(' '.join(m))
    for m in second_mismatches:
        print(' '.join(m))
else:
    print(True)
