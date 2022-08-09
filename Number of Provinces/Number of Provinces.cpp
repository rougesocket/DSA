class Solution {
public:
    int get(vector<int>& dsuf,int x){
        return (dsuf[x]==-1)? x : dsuf[x]=get(dsuf,dsuf[x]);
    }
    void unite(vector<int>& dsuf,int x,int y){
        int parentX = get(dsuf,x);
        int parentY = get(dsuf,y);
        if(parentX==parentY)return;
        dsuf[parentX]=parentY;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> dsuf(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(isConnected[i][j]==1)unite(dsuf,i,j);
            }
        }
        int ans = 0;
        for(auto x : dsuf){
            if(x==-1)ans++;
        }
        return ans;
    }
};
