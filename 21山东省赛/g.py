from decimal import *
from functools import *
from math import *


def round_dec(nn, d):
    s = '0.' + '0' * int(d)
    return Decimal(str(nn)).quantize(Decimal(s))


n, k = map(int, input().split())
a = list(map(int, input().split()))
S = reduce(lambda x, y: x + y, a)
ans = ''
ans += str(floor(S / n))
S -= floor(S / n) * n
ans += '.'
while k > 0 and S > 0:
    S *= 10
    ans += str(floor(S / n))
    S -= floor(S / n) * n
    k -= 1
for i in range(k):
    ans += '0'
print(ans)
