def solve(n, k) -> List[int]:
    if k == 0:
        return []
    if n < k:
        raise Exception('IMPOSSIBLE')
    elif n == k:
        return [1]
    elif n - k + 1 >= k:
        return [n - k + 1, 1]
    else: # 
        # k - 1 < n - (floor(n / 2) + 1)
        # k - 1 < n - (n / 2 - r + 1)
        # k - 1 < n - n / 2 + r - 1
        # k < n - n / 2 + r
        # k < n / 2 + r
        # k < ceil(n / 2)
        solve(n // 2 + 1, x)

k - 1 <= n - (floor(n / 2) + 1)
k - 1 <= n - (n / 2 - r) - 1
k <= ceil(n / 2)

n - k + 1 = floor(n / 2) + 1

k - 1 <= n - n / 2 + r - 1
k <= n - n / 2 + r
k <= n / 2 + r
k <= n / 2 + r

k <= ceil(n / 2)
