def dfs(graph, node, visited, parent):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            return dfs(graph, child, visited, node)
        else:
            if child != parent:
                return True
    return False


edges = [[1, 2], [1, 3], [2, 3], [2, 4], [4, 5], [5, 1]]
nodes = 5

graph = {}
visited = {}
for key in range(1, nodes+1):
    graph[key] = []
    visited[key] = False

for (u, v) in edges:
    graph[u].append(v)
    graph[v].append(u)

temp = dfs(graph, 1, visited, -1)
print(f"Is cycle present ? -> {temp}")