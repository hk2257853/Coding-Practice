#include <bits/stdc++.h>
using namespace std;

/* This is a cheat sheet for graph-related algorithms.
Topics covered:
1. Graph representation using adjacency list
2. DFS and BFS
3. Dijkstra's Algorithm
4. Cycle Detection in Directed Graph using DFS
5. Cycle Detection in Undirected Graph using DFS
6. Topological Sort using DFS
7. Find All Paths from Source to Target using DFS
*/

// dfs
void dfs(vector<vector<int>> &graph, int node, vector<bool> &isVisited)
{
    cout << node << " ";               // print
    isVisited[node] = true;            // mark
    for (int neighbor : graph[node]) // for neigh
    {
        if (!isVisited[neighbor]) // !vis
        {
            dfs(graph, neighbor, isVisited); // dfs
        }
    }
}

// bfs
void bfs(vector<vector<int>> &graph, int startNode)
{
    vector<bool> isVisited(graph.size(), false);
    queue<int> q;
    isVisited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!isVisited[neighbor])
            {
                isVisited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// bfs with levels
void bfs_with_level(vector<vector<int>> &graph, int startNode)
{
    vector<bool> isVisited(graph.size(), false);
    queue<int> q;
    isVisited[startNode] = true;
    q.push(startNode);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size(); // nodes at current level

        while (size--)
        {
            int node = q.front();
            q.pop();
            cout << "Level " << level << ": " << node << " ";

            for (int neighbor : graph[node])
            {
                if (!isVisited[neighbor])
                {
                    isVisited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        level++;
    }
}

// dijkstra: get shortest dist from src node to all other nodes in the graph. condition: Edge weights must be non-negative.
// core logic:
// initial dist to all other node = infinity
// scr dist = 0
// in the breadth pick pick up the smallest element and cal dist.

// Mistakes done while implementing:
// 1) confused at pq.push({dist[neighbor], neighbor});
// 2) if (d > dist[u]) continue; missing
// 3) do int d = pq.top().first and for (const auto &edge : graph[u]) instead of indices to avoid mess/confusion.
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int startNode, int n)
{
    vector<int> dist(n, 1e9);                                                           // 1e9 represents infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node}

    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue; // stale data

        for (const auto &edge : graph[u])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[neighbor])
            {
                dist[neighbor] = dist[u] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}

// cycle detection in a directed graph using DFS (returns true if cycle exists)
bool detectCycleDFS(vector<vector<int>> &graph, int node, vector<bool> &isVisited, vector<bool> &inStack)
{
    isVisited[node] = true;
    inStack[node] = true;

    for (int neighbor : graph[node])
    {
        if (!isVisited[neighbor])
        {
            if (detectCycleDFS(graph, neighbor, isVisited, inStack))
                return true;
        }
        else if (inStack[neighbor])
        {
            return true;
        }
    }

    inStack[node] = false;
    return false;
}

// helper wrapper for cycle detection across all components
bool hasCycle(vector<vector<int>> &graph, int n)
{
    vector<bool> isVisited(n, false);
    vector<bool> inStack(n, false);
    for (int i = 0; i < n; i++) // as it's a directed disconnected graph
    {
        if (!isVisited[i])
        {
            if (detectCycleDFS(graph, i, isVisited, inStack))
                return true;
        }
    }
    return false;
}

// cycle detection in an undirected graph using DFS (returns true if cycle exists)
// core idea is it's already visited and not parent
bool detectCycleUndirectedDFS(vector<vector<int>> &graph, int node, int parent, vector<bool> &isVisited)
{
    isVisited[node] = true;

    for (int neighbor : graph[node])
    {
        if (!isVisited[neighbor])
        {
            if (detectCycleUndirectedDFS(graph, neighbor, node, isVisited))
                return true;
        }
        else if (neighbor != parent)
        {
            // neighbor is visited and it's not the parent -> cycle detected!
            return true;
        }
    }
    return false;
}

// helper wrapper for cycle detection across all components of an undirected graph
bool hasCycleUndirected(vector<vector<int>> &graph, int n)
{
    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++) // as it's an undirected disconnected graph
    {
        if (!isVisited[i])
        {
            if (detectCycleUndirectedDFS(graph, i, -1, isVisited))
                return true;
        }
    }
    return false;
}

// topological sort DFS helper
void topoSortDFS(vector<vector<int>> &graph, int node, vector<bool> &isVisited, stack<int> &stk)
{
    isVisited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!isVisited[neighbor])
        {
            topoSortDFS(graph, neighbor, isVisited, stk);
        }
    }
    stk.push(node);
}

// prints topological order
void printTopologicalOrder(vector<vector<int>> &graph, int n)
{
    vector<bool> isVisited(n, false);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i])
        {
            topoSortDFS(graph, i, isVisited, stk);
        }
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

// find all paths from source to target using DFS (backtracking)
void findAllPathsDFS(vector<vector<int>> &graph, int u, int target, vector<bool> &isVisited, vector<int> &currentPath, vector<vector<int>> &allPaths)
{
    isVisited[u] = true;
    currentPath.push_back(u);

    if (u == target)
    {
        allPaths.push_back(currentPath);
    }
    else
    {
        for (int neighbor : graph[u])
        {
            if (!isVisited[neighbor])
            {
                findAllPathsDFS(graph, neighbor, target, isVisited, currentPath, allPaths);
            }
        }
    }

    // backtrack
    currentPath.pop_back();
    isVisited[u] = false;
}

// helper wrapper to get all paths from src to target
vector<vector<int>> getAllPaths(vector<vector<int>> &graph, int src, int target, int n)
{
    vector<bool> isVisited(n, false);
    vector<int> currentPath;
    vector<vector<int>> allPaths;
    findAllPathsDFS(graph, src, target, isVisited, currentPath, allPaths);
    return allPaths;
}

int main()
{
    // graph representation using adjacency list (DAG in this case)
    int n = 5; // number of nodes
    vector<vector<int>> adjList(n);
    // adding edges to make it acyclic
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[2].push_back(3);
    // traversing adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        for (int neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    vector<bool> isVisited(n, false);
    cout << "DFS starting from node 0: ";
    dfs(adjList, 0, isVisited); // DFS starting from node 0
    cout << endl;

    cout << "BFS starting from node 0: ";
    bfs(adjList, 0); // BFS starting from node 0
    cout << endl;

    // Cycle detection
    cout << "Has cycle: " << (hasCycle(adjList, n) ? "Yes" : "No") << endl;

    // Topological sorting
    cout << "Topological Order: ";
    printTopologicalOrder(adjList, n);

    // All paths from source to target using DFS
    cout << "All paths from node 0 to 3 using DFS:" << endl;
    vector<vector<int>> paths = getAllPaths(adjList, 0, 3, n);
    for (const auto &path : paths)
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    // Undirected graph cycle detection demo
    vector<vector<int>> undirectedAdjList(n);
    // Cyclic undirected graph: 0-1, 1-2, 2-3, 3-0
    undirectedAdjList[0].push_back(1);
    undirectedAdjList[1].push_back(0);
    undirectedAdjList[1].push_back(2);
    undirectedAdjList[2].push_back(1);
    undirectedAdjList[2].push_back(3);
    undirectedAdjList[3].push_back(2);
    undirectedAdjList[3].push_back(0);
    undirectedAdjList[0].push_back(3);
    cout << "Undirected cyclic graph has cycle: " << (hasCycleUndirected(undirectedAdjList, n) ? "Yes" : "No") << endl;

    // Acyclic undirected graph: 0-1, 1-2, 2-3
    vector<vector<int>> undirectedAcyclicAdjList(n);
    undirectedAcyclicAdjList[0].push_back(1);
    undirectedAcyclicAdjList[1].push_back(0);
    undirectedAcyclicAdjList[1].push_back(2);
    undirectedAcyclicAdjList[2].push_back(1);
    undirectedAcyclicAdjList[2].push_back(3);
    undirectedAcyclicAdjList[3].push_back(2);
    cout << "Undirected acyclic graph has cycle: " << (hasCycleUndirected(undirectedAcyclicAdjList, n) ? "Yes" : "No") << endl;

    // Dijkstra's algorithm representation and call
    vector<vector<pair<int, int>>> weightedAdjList(n);
    weightedAdjList[0].push_back({1, 4});
    weightedAdjList[0].push_back({2, 1});
    weightedAdjList[2].push_back({1, 2});
    weightedAdjList[1].push_back({3, 1});
    weightedAdjList[2].push_back({3, 5});

    vector<int> dists = dijkstra(weightedAdjList, 0, n);
    cout << "Dijkstra distances from 0: ";
    for (int d : dists)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
