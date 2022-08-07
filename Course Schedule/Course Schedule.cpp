class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
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
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop();
                cnt++;
                for(auto x: adj[curr]){
                    in[x]--;
                    if(in[x]==0){
                        q.push(x);
                    }
                }
            }
        }
        return cnt==n;
        
    }
};
