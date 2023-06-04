def bigExponentialAddition(m,  n):
    res = 0
    dist = abs(m - n)
    if (m < n):
        res = bigExponential(m)
    else:
        res = bigExponential(n)

    res += res * bigExponential(dist)

    return res

def bigExponential(num):

    # base case
    if (num == 0):
        return 1
    elif (num == 1):
        return 2

    # divide
    half_n = num // 2
    power = bigExponential(half_n)

    # combine
    if num % 2 == 0:
        return power * power
    else:
        return 2 * power * power


cases = int(input())
for i in range(cases):
    lst = list(input().split())
    m, n = int(lst[0]), int(lst[1]) 
    print(bigExponentialAddition(m, n))




