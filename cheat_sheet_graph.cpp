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
*/

// dfs
void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adjList)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adjList);
        }
    }
}

// bfs
void bfs(int startNode, const vector<vector<int>> &adjList)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// bfs with levels
void bfs_with_level(int startNode, const vector<vector<int>> &adjList)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();  // nodes at current level

        while(size--) {
            int node = q.front();
            q.pop();
            cout << "Level " << level << ": " << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
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
// 3) do int d = pq.top().first and for (const auto &edge : adjList[u]) instead of indices to avoid mess/confusion.
vector<int> dijkstra(int startNode, int n, const vector<vector<pair<int, int>>> &adjList)
{
    vector<int> dist(n, 1e9); // 1e9 represents infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node}

    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;         // stale data

        for (const auto &edge : adjList[u])
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
bool detectCycleDFS(int node, vector<bool> &visited, vector<bool> &inStack, const vector<vector<int>> &adjList)
{
    visited[node] = true;
    inStack[node] = true;

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            if (detectCycleDFS(neighbor, visited, inStack, adjList))
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
bool hasCycle(int n, const vector<vector<int>> &adjList)
{
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);
    for (int i = 0; i < n; i++) // as it's a directed disconnected graph
    {
        if (!visited[i])
        {
            if (detectCycleDFS(i, visited, inStack, adjList))
                return true;
        }
    }
    return false;
}

// cycle detection in an undirected graph using DFS (returns true if cycle exists)
// core idea is it's already visited and not parent 
bool detectCycleUndirectedDFS(int node, int parent, vector<bool> &visited, const vector<vector<int>> &adjList)
{
    visited[node] = true;

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            if (detectCycleUndirectedDFS(neighbor, node, visited, adjList))
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
bool hasCycleUndirected(int n, const vector<vector<int>> &adjList)
{
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) // as it's an undirected disconnected graph
    {
        if (!visited[i])
        {
            if (detectCycleUndirectedDFS(i, -1, visited, adjList))
                return true;
        }
    }
    return false;
}

// topological sort DFS helper
void topoSortDFS(int node, vector<bool> &visited, stack<int> &stk, const vector<vector<int>> &adjList)
{
    visited[node] = true;
    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            topoSortDFS(neighbor, visited, stk, adjList);
        }
    }
    stk.push(node);
}

// prints topological order
void printTopologicalOrder(int n, const vector<vector<int>> &adjList)
{
    vector<bool> visited(n, false);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topoSortDFS(i, visited, stk, adjList);
        }
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
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

    vector<bool> visited(n, false);
    cout << "DFS starting from node 0: ";
    dfs(0, visited, adjList); // DFS starting from node 0
    cout << endl;
    
    cout << "BFS starting from node 0: ";
    bfs(0, adjList); // BFS starting from node 0
    cout << endl;

    // Cycle detection
    cout << "Has cycle: " << (hasCycle(n, adjList) ? "Yes" : "No") << endl;

    // Topological sorting
    cout << "Topological Order: ";
    printTopologicalOrder(n, adjList);

    // Undirected graph cycle detection demo
    vector<vector<int>> undirectedAdjList(n);
    // Cyclic undirected graph: 0-1, 1-2, 2-3, 3-0
    undirectedAdjList[0].push_back(1); undirectedAdjList[1].push_back(0);
    undirectedAdjList[1].push_back(2); undirectedAdjList[2].push_back(1);
    undirectedAdjList[2].push_back(3); undirectedAdjList[3].push_back(2);
    undirectedAdjList[3].push_back(0); undirectedAdjList[0].push_back(3);
    cout << "Undirected cyclic graph has cycle: " << (hasCycleUndirected(n, undirectedAdjList) ? "Yes" : "No") << endl;

    // Acyclic undirected graph: 0-1, 1-2, 2-3
    vector<vector<int>> undirectedAcyclicAdjList(n);
    undirectedAcyclicAdjList[0].push_back(1); undirectedAcyclicAdjList[1].push_back(0);
    undirectedAcyclicAdjList[1].push_back(2); undirectedAcyclicAdjList[2].push_back(1);
    undirectedAcyclicAdjList[2].push_back(3); undirectedAcyclicAdjList[3].push_back(2);
    cout << "Undirected acyclic graph has cycle: " << (hasCycleUndirected(n, undirectedAcyclicAdjList) ? "Yes" : "No") << endl;

    // Dijkstra's algorithm representation and call
    vector<vector<pair<int, int>>> weightedAdjList(n);
    weightedAdjList[0].push_back({1, 4});
    weightedAdjList[0].push_back({2, 1});
    weightedAdjList[2].push_back({1, 2});
    weightedAdjList[1].push_back({3, 1});
    weightedAdjList[2].push_back({3, 5});

    vector<int> dists = dijkstra(0, n, weightedAdjList);
    cout << "Dijkstra distances from 0: ";
    for (int d : dists)
    {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
