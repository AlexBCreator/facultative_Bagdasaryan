import numpy as np
n = int(input())

a = np.zeros((n, n), dtype=int)
a[0, 0] = 2
a[0, 1] = -1
for i in range(n-2):
    a[i+1, i] -= 1
    a[i+1, i+1] += 2
    a[i+1, i+2] -= 1
a[n-1, n-2] = -1
a[n-1, n-1] = 2

b = np.zeros(n, dtype=int)
b[0] = 100
b[-1] = 1

x = np.linalg.solve(a, b)
print(x)
