
def findMax():
        graph = {}
        nums = input().split(" ")
        n = int(nums[0])
        m = int(nums[1])
        for i in range(n):
                graph[i] = []
        graph[-1] = []
        graph[400] = []
        numbers = input().split(" ")
        a = 2
        for i in range(n):
                if numbers[i] == "0":
                        graph[-1] += [i]
                else:
                        graph[i] += [400]
        for j in range(m):
                inr = input().split(" ")
                v1 = int(inr[0]) -1
                v2 = int(inr[1]) -1
                if(len(graph[v1]) == 1 and len(graph[v2]) == 1):
                        graph[v1].append(v2)
                        graph[v2].append(v1)
                elif(len(graph[v1]) == 1 and len(graph[v2]) == 0):
                        graph[v2].append(v1)
                elif(len(graph[v1]) == 0 and len(graph[v2]) == 1):
                        graph[v1].append(v2)
                else:
                        graph[v1].append(v2)
                        graph[v2].append(v1)
        visited = []
        def dfs(graph,node):
                global visited
                visited.append(node)
                if node == 400:
                        return [400]
                for neighbor in graph[node]:
                        if neighbor not in visited:
                                visited.append(neighbor)
                                l = dfs(graph,neighbor)
                                if l != -1:
                                        return [node] + l
                return -1

        def maxFlow(graph):
                global visited
                visited = []
                l = dfs(graph,-1)

                if l == -1:
                        return 0
                for i in range(len(l) - 1):
                        a = l[i]
                        b = l[i + 1]
                        graph[a].remove(b)
                        graph[b].append(a)
                return maxFlow(graph) + 1
        return maxFlow(graph)

print(findMax())