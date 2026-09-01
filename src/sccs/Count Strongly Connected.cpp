class Solution 
{
  public:
 
    
    vector<vector<int>> g, gt;
    int N;
    
    vector<bool> seen;
    stack<int> st;
    
    vector<vector<int>> sccs;
        
    void dfs(int i)
    {
        seen[i] = true;
        for(const auto &nei : g[i])
        {
            if(!seen[nei])
            {
                dfs(nei);
            }
        }
        st.push(i);
    }
    
    
    vector<int> comp;
    void dfs1(int i)
    {
        seen[i] = true;
        for(const auto &nei : gt[i])
        {
            if(!seen[nei])
            {
                dfs1(nei);
            }
        }
        comp.push_back(i);
    }
    
    
    
        
    int kosaraju(int V, vector<vector<int>> &edges) 
    {
        g.clear();
        gt.clear();
        sccs.clear();
        comp.clear();
        
        g.resize(V);
        gt.resize(V);
        N = V;
        seen.resize(V, false);
        
        for(const auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            gt[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++)
        {
            if(!seen[i])
            {
                dfs(i);
            }
        }
        seen.assign(V, false);
        
        while(!st.empty())
        {
            int temp = st.top();
            st.pop();
            if(!seen[temp])
            {
                dfs1(temp);
                sccs.push_back(comp);
                comp.clear();
            }
        }
        
        return sccs.size();
    }
};
