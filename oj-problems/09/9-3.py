n = -1
while n != 0:
    n = int(input())

    if n == 0: break
    
    max_len_of_side = 0
    no = 0
    for i in range(n):
        lst = list(map(int, input().split()))
        w, h = lst[0], lst[1]

        cur_len_of_side1 = 0
        if w == h:
            cur_len_of_side1 = w // 4
        elif w < h:
            if (h // 4) <= w:
                cur_len_of_side1 = h // 4
            else:
                cur_len_of_side1 = w
        else:
            if (w // 4) <= h:
                cur_len_of_side1 = w // 4
            else:
                cur_len_of_side1 = h

        cur_len_of_side2 = 0
        if w == h:
            cur_len_of_side2 = w // 2
        elif w < h:
            cur_len_of_side2 = w // 2
        else:
            cur_len_of_side2 = h // 2 

        cur_len_of_side = max(cur_len_of_side1, cur_len_of_side2)
        if cur_len_of_side > max_len_of_side:
            max_len_of_side = cur_len_of_side
            no = i + 1
        
    print(no)

"""
one rectangle to 4 squares
1. if w == h => (w // 4) is length of side
2. if w < h => if h // 4 <= w then (h // 4) is length of side else w
3. if w > h => if w // 4 <= h then (w // 4) is length of side lese h

one almost square to 4 squares
1. if w == h => (w // 2) is length of side
2. if w < h => w // 2 is length of side
4. if w > h => h // 2 is length of side

"""