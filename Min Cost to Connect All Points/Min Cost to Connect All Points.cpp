class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int> > adj[n];
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dist = abs(points[j][0]-x1)+abs(points[j][1]-y1);
                adj[i].push_back({j,dist});
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<"The vertex is "<<i<<": ";
        //     for(auto x : adj[i]){
        //         cout<<"("<<x.first<<","<<x.second<<") ";
        //     }    
        //     cout<<endl;
        // }
        
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
        vector<int> wt(n,INT_MAX);
        wt[0]=0;
        pq.push({0,0});
        vector<int> visited(n,0);
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int curr = temp.second;
            visited[curr]=1;
            for(auto x : adj[curr]){
                int cost = x.second,des = x.first;
                if(!visited[des] && wt[des]>cost){
                    wt[des]=cost;
                    pq.push({cost,des});
                }
            }
        }
        int s = 0;
        for(auto x : wt)s+=x;
        return s;
    }
};
