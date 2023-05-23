n = -1
while n != 0:
    n = int(input())

    if n == 0: break
    
    max_len_of_side = 0
    no = 0
    for i in range(n):
        lst = list(map(int, input().split()))
        w, h = lst[0], lst[1]

        cur_len_of_side = 0

        if w == h:
            cur_len_of_side = w // 4
        elif w < h:
            if (h // 4) <= w:
                cur_len_of_side = h // 4
            else:
                cur_len_of_side = w
        else:
            if (w // 4) <= h:
                cur_len_of_side = w // 4
            else:
                cur_len_of_side = h
        
        if cur_len_of_side > max_len_of_side:
            max_len_of_side = cur_len_of_side
            no = i + 1
        
    print(no)