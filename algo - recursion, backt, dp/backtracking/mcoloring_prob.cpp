class Solution{
public:
    bool isSafe(bool graph[101][101], int src, int c, vector<int> &vec)
    {
        for(int i = 0; i < vec.size(); i++) // check if any neighbour have same color as vertex src
        {
            if(graph[src][i] && vec[i] == c) return false;
        }
        return true;
    }

    // go from vertex 0 to n -1 n try applying color on it
    bool isp(bool graph[101][101], int m, int v, int V, vector<int> &vec)
    {
        if(v == V) return true;
        for(int i = 0; i < m; i++) // trying the colors (like I tried 0 to 9 in suduko!)
        {
            if(isSafe(graph, v, i, vec))
            {
                vec[v] = i;
                if(isp(graph, m, v + 1, V, vec)) return true;
                vec[v] = -1;
            }
        }
        return false;
    }

    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> vec(n, -1); // to know about the colors the vertices have
        return isp(graph, m, 0, n, vec);
        
    }
};

/*
Question:
why greedy can't do the job?
any chance to use recursion? (its little bit like n queen prob, neighbor can't be queen)
*/