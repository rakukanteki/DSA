def dfs(graph, node, visited):
    # print(node)
    visited.add(node)
    count = 0
    for item in graph[node]:
        if item not in visited:
            count += dfs(graph, item, visited)
    return count+1


'''
edges = [['A', 'B'], ['A', 'D'], ['A', 'C'], ['D', 'E'], ['B', 'E']]
nodes = ['A', 'B', 'C', 'D', 'E']
'''

edges = [['A', 'B'], ['A', 'D'], ['A', 'C'], ['D', 'E'], ['B', 'E'], ['F', 'G'], ['F', 'H'], ['I', 'J']]
nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K']

graph = {}

for key in nodes:
    graph[key] = []

for (u, v) in edges:
    graph[u].append(v)
    graph[v].append(u)

visited = set()
# ans = []
for item in nodes:
    if item not in visited:
        temp = dfs(graph, item, visited)
        print(f"Members of {item}: ", temp)

# print(ans)

# print("Number of members: ", dfs(graph, 'A'))