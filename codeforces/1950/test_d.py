from collections import Counter
n = 10000
def is_binary(i):
    return not (set(str(i)) - {'0', '1'})

b = [x for x in range(1, n) if is_binary(x)]
print(b)
# for i in range(1, len(b)):
#     for j in range(i, len(b)):
#         print(b[i], b[j], b[i] * b[j])
