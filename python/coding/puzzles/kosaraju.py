from collections import defaultdict

def kosaraju(N,M,A,B): 
    g = defaultdict(list)
    g_p = defaultdict(list)
    component_id = defaultdict(int)
    condensed_graph = defaultdict(list)
    weight_component = defaultdict(int)
    visited = set()
    stack = []
    components = []

    def dfs(u):
        visited.add(u)

        for v in g[u]:
            if v not in visited:
                dfs(v)

        stack.append(u)
    
    def dfs2(u,id):
        visited.add(u)
        component_id[u] = id
        weight_component[id] += 1

        for v in g_p[u]:
            if v not in visited:
                dfs2(v,id)
    
    for u,v in zip(A,B):
        if v not in g[u]:
            g[u].append(v)
    
    for u in list(g.keys()):
        if u not in visited:
            dfs(u)
    # reverse graph

    for k,v in g.items():
        for u in v:
            g_p[u].append(k)
            
    visited = set()
    id = 0
    while stack:
        u = stack.pop()
        if u not in visited:
            dfs2(u,id)
            id += 1
    print(component_id)
    
    # build condensed graph
    
    for u,neighbors in g.items():
        for v in neighbors:
            cu = component_id[u]
            cv = component_id[v]

            if cu != cv:
                condensed_graph[cu].append(cv)
    
    # DP on condensed DAG in reverse topological order
    # Kosaraju assigns IDs in topological order (0 = source), so process from max to 0
    num_components = id
    dp = defaultdict(int)
    for u in range(num_components - 1, -1, -1):
        dp[u] = weight_component[u]
        for v in condensed_graph[u]:
            dp[u] = max(dp[u], weight_component[u] + dp[v])

    return max(dp.values())

N = 10
M = 9
A = [3, 2, 5, 9, 10, 3, 3, 9, 4]
B = [9, 5, 7, 8, 6, 4, 5, 3, 9]


res = kosaraju(N=N,M=M,A=A,B=B)
print(res)
