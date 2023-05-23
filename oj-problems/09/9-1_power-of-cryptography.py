def bs(left, right, target, n):

    while left <= right:
        mid = left + (right - left) // 2

        num = pow(mid, n)
        if num == target:
            return mid
        elif num < target:
            left = mid + 1
        else:
            right = mid - 1

t = int(input())

for i in range(t):
    lst = list(map(int, input().split()))
    n, p = lst[0], lst[1]



    print(bs(1, 10 ** 9, p, n))
    
