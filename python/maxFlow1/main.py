n = int(input())
numbers = set()
matrix = []
for i in range(n):
        nums = input()
        matrix.append([int(x) for x in nums.split(" ")])
        numbers.update(matrix[i])
numbers = sorted(list(numbers))

def findMax():
        global numbers
        def createGraph(x):
                graph = {}
                graph[-1] = list(range(n))
                graph[200] = []
                for i in range(2 * n + 1):
                        graph[i] = []
                for i in range(n):
                        graph[n+i].append(200)
                for i in range(n):
                        for j in range(n):
                                if matrix[i][j] <= x:
                                        graph[i].append(n + j)
                return graph
        visited = []
        def dfs(graph,node):
                global visited
                visited.append(node)
                if node == 200:
                        return [200]
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

        for number in numbers:
                if(maxFlow(createGraph(number)) == n):
                        return number
print(findMax())