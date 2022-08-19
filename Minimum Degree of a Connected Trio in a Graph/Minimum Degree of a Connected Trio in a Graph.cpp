class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        
        vector<int> in(n+1,0);
        vector<vector<int> > adjmat(n+1,vector<int> (n+1,0));
        for(auto &x : edges){
            int src = x[0],des = x[1];
            adjmat[src][des]=1;
            adjmat[des][src]=1;
            in[src]++;
            in[des]++;
        }
        
        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(adjmat[i][j] && adjmat[i][k] && adjmat[j][k]){
                        ans = min(ans,in[i]+in[j]+in[k]-6);
                    }
                }
            }
        }
        return (ans==INT_MAX)? -1 : ans;
    }
};
