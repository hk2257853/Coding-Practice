class Solution {
public:
    int Tvertices;
    vector<int> isvisited, color; // acutally isvisited is enough... but lemme do like this...
    
    bool dfsrec(vector<vector<int>>& adj, int ver)
    {        
        isvisited[ver] = 1;
        for (int i = 0; i < adj[ver].size(); i++) // its an adjlist represented in vector.
        {
          if (!isvisited[i])
          {     
              color[i] = !color[ver];
              return dfsrec(adj, i)) return false;
          }
          else  if(color[i] == color[ver]) return false;
        }
        return true;
    }

    // can be a disconnected graph...=
    bool dfsallrec(vector<vector<int>>& adj)
    {
        for (int i = 0; i < Tvertices; i++)
            if(!isvisited[i]) 
            {
                color[i] = 1;
                if(dfsrec(adj, i));
                else return false;
            }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj)
    {
        Tvertices = adj.size();
        isvisited.resize(Tvertices);
        fill(isvisited.begin(), isvisited.end(), 0);
        color.resize(Tvertices);        
        return dfsallrec(adj);        
    }
};