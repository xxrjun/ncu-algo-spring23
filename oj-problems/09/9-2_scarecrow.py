T = int(input())

for i in range(T):
    N = int(input())
    fields = input()
    fields = fields[:N]

    l = len(fields)
    count = 0
    j = 0
    while j < N:
        if fields[j] == '.':
            count += 1
            j += 3
        else:
            j += 1
        

    print("Case {0}: {1}".format((i + 1), count))


"""
3 cases:
1. if encounter '.' and if next two is '.', then count one and iterate cur + 3
2. encounter '.' but next is '#', need count one and iterate cur + 1
3. encounter '#' just iterate to next one
"""