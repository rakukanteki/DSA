# DFS(Depth First Search) is a searching algorithm in graph.
# Complexity - O(v)

# Function of DFS
def dfs(graph, node, visited=set()):
    print(node)
    visited.add(node)
    for child in graph[node]:
        if child not in visited:
            dfs(graph, child, visited)


numbers_input = [[1, 2], [1, 5],[2, 3], [2, 4], [2, 5], [3, 4], [3, 6], [4, 5], [4, 6], [5, 6]]
nodes = 6
graph = {}

for i in range(1, nodes+1):
    graph[i] = []

for (u, v) in numbers_input:
    graph[u].append(v)
    graph[v].append(u)

dfs(graph, 3)
