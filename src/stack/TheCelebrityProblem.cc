class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        if(mat.size() == 1) return 0;
        stack<int> cp;
        for(int i = mat.size() - 1; i >= 0; i--) {
            cp.push(i);
        }
        
        while(!cp.empty() && cp.size() != 1) {
            int f = cp.top();
            cp.pop();
            int s = cp.top();
            cp.pop();
            
            if(mat[f][s] == 1 && mat[s][f] == 0) {
                cp.push(s);
            } else if (mat[f][s] == 0 && mat[s][f] == 1) {
                cp.push(f);
            }
        }
        
        if(cp.empty()) return -1;
        int c = cp.top();
        cp.pop();
        
        
        for(int i = 0; i < mat.size(); i++) {
            if (i == c){
                continue;
            }else if(mat[c][i] != 0 || mat[i][c] != 1) {
                return -1;
            }
        }
        return c;
    }
};
