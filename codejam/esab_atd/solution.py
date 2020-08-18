SAME, DIFF, UNDEF = 1, 0, -1

T, B = map(int, input().split())

def change():
  global arr
  global f
  a, b, c, d = arr[f], arr[f+1], arr[B-f-2], arr[B-f-1]
  print(f+1, flush=True)
  x = int(input())
  print(f+2, flush=True)
  y = int(input())
  if (x,y) == (d,c):
    arr = arr[::-1]
    arr[f], arr[f+1], arr[B-f-2], arr[B-f-1] = d, c, b, a
  elif (x,y) == (a^1,b^1):
    arr = [z^1 for z in arr if z >= 0]
    arr[f], arr[f+1], arr[B-f-2], arr[B-f-1] = a^1, b^1, c^1, d^1
  elif  (x,y) == (d^1,c^1):
    arr = [z^1 for z in arr[::-1] if z >= 0]
    arr[f], arr[f+1], arr[B-f-2], arr[B-f-1] = d^1, c^1, b^1, a^1

for t in range(T):
  arr = [-1] * B
  arr_type = [-1] * (B//2)
  l, r = 0, B
  found = False
  while not found and l < r:
    for i in range(5):
      print(l+i+1, flush=True)
      arr[l+i] = int(input())
      print(r-i, flush=True)
      arr[r-i-1] = int(input())
      arr_type[l+i] = int(arr[l+i] == arr[r-i-1])
    for i in range(4):
      if arr_type[l+i] != arr_type[l+i+1]:
        f = l+i
        found = True
        break
    l, r = l+5, r-5
  if found:
    change()
    x = 0
    while x+5 <= f and x+5 <= 40:
      print(x+1, flush=True)
      val = int(input())
      for j in range(x, x+5):
        arr[j] = val
        arr[B-j-1] = val if arr_type[j] == SAME else val ^ 1
      x += 5
    i = x // 5
    if i % 2 == 1:
      print(1, flush=True)
      int(input())
      i += 1
    l,r = x, B-x
    while l+1 < r:
      if i and i % 8 == 0:
          change()
          i = 0
      print(l+1, flush=True)
      arr[l] = int(input())
      print(r, flush=True)
      arr[r-1] = int(input())
      l += 1
      r -= 1
      i += 2
  else:
    x = 0
    for i in range(B//10):
      print(x+1, flush=True)
      val = int(input())
      for j in range(x, x+5):
        arr[j] = val
        arr[B-j-1] = val if arr_type[j] == SAME else val ^ 1
      x += 5
  print(''.join(map(str, arr)), flush=True)
  if input() == 'N':
    break
