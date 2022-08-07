class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int> in(n);
        vector<int> adj[n];
        for(auto x : pre){
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto x : adj[curr]){
                    in[x]--;
                    if(in[x]==0)q.push(x);
                }
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};
