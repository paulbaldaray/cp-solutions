T, B = map(int, input().split())

def change():
  global arr
  global queries
  global f
  a, b, c, d = arr[f], arr[f+1], arr[B-f], arr[B-f+1]
  print(f, flush=True); x = int(input())
  print(f+1, flush=True); y = int(input())
  queries += 2
  if (x,y) == (d, c):
    arr = arr[::-1]
    arr[f], arr[f+1], arr[B-f], arr[B-f+1] = d, c, b, a
  elif (x,y) == (a^1, b^1):
    arr = [z^1 if z != -1 else z for z in arr]
    arr[f], arr[f+1], arr[B-f], arr[B-f+1] = a^1, b^1, c^1, d^1
  elif (x,y) == (d^1, c^1):
    arr = [z^1 if z != -1 else z for z in arr[::-1]]
    arr[f], arr[f+1], arr[B-f], arr[B-f+1] = d^1, c^1, b^1, a^1

for tc in range(T):
  queries = 1
  arr = [-1] * (B + 2)
  same_bits = [False] * (B//2 + 1)
  same_as_first = [False] * (B//2 + 1)
  homogeneous = 0
  found = False
  l, r = 1, B
  while not found and queries < B:
    for i in range(5):
      print(l+i, flush=True); arr[l+i] = int(input())
      print(r-i, flush=True); arr[r-i] =  int(input())
      same_bits[l+i] = arr[l+i] == arr[r-i]
      queries += 2
    for i in range(4):
      if same_bits[l+i] != same_bits[l+i+1]:
        f = l+i
        found = True
        break
    if found: break
    for i in range(5):
      same_as_first[l+i] = arr[l+i] == arr[l]
    homogeneous += 1; l += 5; r -= 5
  if not found:
    l, r = 1, B
    for _ in range(B//10):
      print(l, flush=True)
      x = int(input())
      queries += 1
      for i in range(5):
        arr[l+i] = x if same_as_first[l+i] else x^1
        arr[r-i] = arr[l+i] if same_bits[l+i] else arr[l+i]^1
      l += 5; r-=5
  else:
    h,hr = 1, B
    for _ in range(homogeneous):
      if queries % 10 == 1: change()
      print(h, flush=True)
      x = int(input())
      queries += 1
      for i in range(5):
        arr[h+i] = x if same_as_first[h+i] else x^1
        arr[hr-i] = arr[h+i] if same_bits[h+i] else arr[h+i]^1
      h += 5; hr-=5
    if homogeneous % 2 == 1:
      print(1, flush=True)
      int(input())
      queries += 1
    while l < r:
      if queries % 10 == 1: change()
      print(l, flush=True); arr[l] = int(input())
      print(r, flush=True); arr[r] = int(input())
      queries += 2
      l+=1; r-=1
  print(''.join(list(map(str, arr[1:B+1]))), flush=True)
  if input() == 'N':
    break
