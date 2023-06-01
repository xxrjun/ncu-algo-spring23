# 定義分數背包問題的函數，輸入為物品的價值、重量和背包的容量
def fractional_knapsack(value, weight, capacity):
    # 創建一個索引列表，對應每個物品
    index = list(range(len(value)))

    # 計算每個物品的價值和重量的比率
    ratio = [v/w for v, w in zip(value, weight)]
    
    # 根據價值和重量的比率，對索引列表進行排序，排序方式為降序
    index.sort(key=lambda i: ratio[i], reverse=True)
 
    # 初始化最大價值為0
    max_value = 0
    # 初始化每個物品的分數為0
    fractions = [0]*len(value)
    # 遍歷每個物品
    for i in index:
        # 如果當前物品的重量小於或等於背包的剩餘容量
        if weight[i] <= capacity:
            # 將當前物品全部放入背包
            fractions[i] = 1
            # 更新最大價值
            max_value += value[i]
            # 更新背包的剩餘容量
            capacity -= weight[i]
        else:
            # 如果當前物品的重量大於背包的剩餘容量，則只放入部分物品
            fractions[i] = capacity/weight[i]
            # 更新最大價值
            max_value += value[i]*capacity/weight[i]
            # 當背包已滿時，結束循環
            break
 
    # 返回最大價值和每個物品的分數
    return max_value, fractions
 
# 測試數據
# n = 3
# value = [20, 60, 45]
# weight = [1, 2, 3]
# capacity = 5
n = 5
capacity = 10
value = [10, 9, 12, 4, 8]
weight = [4, 3, 6, 2, 5]

# 調用函數，獲得最大價值和每個物品的分數
max_value, fractions = fractional_knapsack(value, weight, capacity)
# 輸出最大價值
print('The maximum value of items that can be carried:', max_value)
