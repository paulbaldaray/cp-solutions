from string import ascii_lowercase, ascii_uppercase

s = input()

lastSeen = dict()

bestLen = 0
best = ""

for i in range(len(s)):
    lastSeen[s[i]] = i

    keyPoints = list()

    for lower,upper in zip(ascii_lowercase, ascii_uppercase):

        a = None
        b = None
        if lower in lastSeen:
            a = lastSeen[lower]
        if upper in lastSeen:
            b = lastSeen[upper]


        if a == None and b == None:
            keyPoints.append((0,True))
            keyPoints.append((i+1, False))
        elif a == None:
            if b+1 < i+1:
                keyPoints.append((b+1, True))
                keyPoints.append((i+1, False))
        elif b == None:
            if a+1 < i+1:
                keyPoints.append((a+1, True))
                keyPoints.append((i+1, False))
        else:
            mx = max(a,b)
            mn = min(a,b)

            # letter not included
            if mx+1 < i+1:
                keyPoints.append((mx+1, True))
                keyPoints.append((i+1, False))
            # letter included and balanced
            if 0 < mn+1:    # always true, just for symmetry
                keyPoints.append((0, True))
                keyPoints.append((mn+1, False))

    keyPoints.sort()
    
    cnt = 0
    j = -1
    for point,isStart in keyPoints:
        if isStart:
            cnt += 1
        else:
            cnt -= 1

        if cnt == 26:
            j = point
            break

    if j != -1:
        if i+1 - j > bestLen:
            bestLen = i+1-j
            best = s[j:i+1]


# print(bestLen, best)
print(best)
