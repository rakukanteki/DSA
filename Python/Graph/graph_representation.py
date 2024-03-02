num_inputs = [[0, 1], [0, 2], [0, 4], [1, 3], [2, 3], [2, 4], [2, 5], [3, 5]]

nodes = 6

print("In Matrix Representation")
# Matrix Representation.
matrix_graph = []
for i in range(nodes):  # Rows
    temp = []
    for j in range(nodes):  # Columns
        temp.append(0)
    matrix_graph.append(temp)

for (u, v) in num_inputs:
    matrix_graph[u][v] = 1
    matrix_graph[v][u] = 1

for item in matrix_graph:
    print(item)

print("\nIn Adjacency List Representation")
# Adjacency List Representation.
graph = {}
for i in range(nodes):
    graph[i] = []

for (u, v) in num_inputs:
    graph[u].append(v)
    graph[v].append(u)

for item in graph.items():
    print(item)