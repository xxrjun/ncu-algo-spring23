# Define infinity as a large enough value
INF = 99999

# Function to print the solution
def printSolution(dist, V):
    print("Following matrix shows the shortest distances between every pair of vertices")
    for i in range(V):
        for j in range(V):
            if(dist[i][j] == INF):
                print("%7s" %("INF"), end="")
            else:
                print("%7d" %(dist[i][j]), end="")
            if j == V-1:
                print()

# Function to implement Floyd Warshall Algorithm
def floydWarshall(graph, V):
    dist = list(map(lambda i : list(map(lambda j : j , i)) , graph))

    # path table
    path = [[0 for x in range(V)] for y in range(V)]

    for k in range(V):
        for i in range(V):
            for j in range(V):
                # dist[i][j] = min(dist[i][j], dist[i][k]+ dist[k][j])

                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k]+ dist[k][j]
                    path[i][j] = path[k][j]

            

    # Print the shortest distance matrix
    printSolution(dist, V)

    # Print the path matrix
    printSolution(path, V)

# Driver program to test the above program
# Let us create the following weighted graph
"""
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3
"""
# graph = [[0, 5, INF, 10],
#          [INF, 0, 3, INF],
#          [INF, INF, 0, 1],
#          [INF, INF, INF, 0]
#         ]

graph2 = [
    [0, 6, INF, 3, INF],
    [INF, 0, 2, 4, INF],
    [INF, INF, 0, INF, 1],
    [INF, 2, 3, 0, 5],
    [INF, 1, 5, INF, 0],
 ]


# floydWarshall(graph, 4)
floydWarshall(graph2, 5)
