class Solution {
public:
    vector<vector<int> > ans;
    void dfs(vector<vector<int> > & adj,int start,int end,vector<int > & visited,vector<int>& path){
        if(start==end){
            path.push_back(end);
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        visited[start]=1;
        path.push_back(start);
        for(auto x : adj[start]){
            if(visited[x]==0){
                dfs(adj,x,end,visited,path);     
            }
        }
        path.pop_back();
        visited[start]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int > visited(graph.size(),0);
        vector<int> path;
        dfs(graph,0,graph.size()-1,visited,path);
        return ans;
    }
};
