test = '1 0 1 1 0 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1'
arr = list(map(int, test.split()))
queries = 1
while True:
  line = input();
  if len(line) == len(arr):
    ans = ''.join(list(map(str, arr)))
    print(ans)
    print('Y' if ans == line else 'N')
    break
  if queries % 10 == 1:
    print("Modification: ", end="")
    mod = input()
    if mod == "R":
      arr = arr[::-1]
    elif mod == "C":
      arr = [z^1 for z in arr]
    elif mod == "RC":
      arr = [z^1 for z in arr[::-1]]
  print(arr[int(line)-1])
  queries += 1
