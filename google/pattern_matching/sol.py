for tc in range(1, int(input())+1):
  pfxs, sfxs, root = [], [], ""
  for _ in range(int(input())):
    tokens = input().split('*')
    pfxs.append(tokens[0])
    sfxs.append(tokens[-1])
    root += ''.join(tokens[1:-1])
  pfx, sfx = max(pfxs, key = len), max(sfxs, key = len)
  hpfx = all([pfx.find(s) == 0 for s in pfxs])
  hsfx = all([sfx.find(s) == len(sfx)-len(s) for s in sfxs])
  print('Case #'+str(tc)+': '+(pfx+root+sfx if hpfx and hsfx else '*'))
