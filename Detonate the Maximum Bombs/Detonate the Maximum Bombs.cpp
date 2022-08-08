class Solution {
public:
    int bfs(vector<int> adj[],int start,int n){
        int cnt = 0;
        queue<int> q;
        q.push(start);
        vector<bool> visited(n,false);
        visited[start]=true;
        while(!q.empty()){
            int sz = q.size();
            cnt+=q.size();
            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop();
                for(auto x : adj[curr]){
                    if(!visited[x]){
                        visited[x]=true;
                        q.push(x);
                    }
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            int x=bombs[i][0],y=bombs[i][1],r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int x1=bombs[j][0],y1=bombs[j][1];
                if((long long int)pow((x1-x),2)+(long long int)pow((y1-y),2)-(long long int)pow(r,2)<=0){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,bfs(adj,i,n));
        }
        return ans;
    }
};
