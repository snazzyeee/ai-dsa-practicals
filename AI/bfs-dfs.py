def bfs(graph, start):
    visited = {start}
    queue = [start]
    order = []
    while queue:
        node = queue.pop(0)
        order.append(node)
        for next_node in graph.get(node, []):
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)
    return order


def dfs(graph, start, visited=None):
    if visited is None:
        visited = []
    visited.append(start)
    for next_node in graph.get(start, []):
        if next_node not in visited:
            dfs(graph, next_node, visited)
    return visited
