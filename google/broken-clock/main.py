import itertools
mod = lambda x : x % (360*12*(10**10))
nano = dict(zip(('h', 'm', 's'), (60*60*10**9, 60*10**9, 10**9)))

def check(s, m, h, ns, S, M, H):
	sn = s*nano['s']+ns
	mn = m*nano['m']+sn
	hn = h*nano['h']+mn
	st = sn*720
	mt = mn*12
	ht = hn
	return mod(mt-st) == mod(M-S) and mod(ht-mt) == mod(H-M)

def solve():
	for S, M, H in itertools.permutations(tuple(map(int, input().split()))):
		for h in range(12):
			if (-H + M + h*nano['h']) % 11 == 0:
				ns = mod(h*nano['h'] + (-H + M + h*nano['h']) // 11)
				h = ns // nano['h']
				ns %= nano['h']
				m = ns // nano['m']
				ns %= nano['m']
				s = ns // nano['s']
				ns %= nano['s']
				if check(s, m, h, ns, S, M, H):
					return ' '.join(map(str, [h, m, s, ns]))
	assert(False)

if __name__ == '__main__':
	T = int(input())
	for t in range(T):
		print(f'Case #{t+1}: {solve()}')
