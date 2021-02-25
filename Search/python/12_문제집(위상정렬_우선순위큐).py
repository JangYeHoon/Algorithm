from queue import PriorityQueue
def topologicalSort():
    pq = PriorityQueue()
    for i in range(1, n + 1):
        if link_cost[i] == 0:
            pq.put(i)
    for i in range(1, n + 1):
        node = pq.get()
        print(node, end=" ")
        for next in graph[node]:
            link_cost[next] -= 1
            if link_cost[next] == 0:
                pq.put(next)

n, m = map(int, input().split(' '))
graph = []
link_cost = [0] * (n + 1)
for _ in range(0, n + 1):
    graph.append([])
for _ in range(m):
    a, b = map(int, input().split(' '))
    graph[a].append(b)
    link_cost[b] += 1
topologicalSort()