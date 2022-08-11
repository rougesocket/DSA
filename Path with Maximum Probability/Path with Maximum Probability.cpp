class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //creating adjacency list
        vector<pair<int,double> > adj[n];
        for(int i=0;i<edges.size();i++){
        	//since undirected graph so there will be edge from u to v and v to u
            int src = edges[i][0],des = edges[i][1];
            double cost=succProb[i];
            adj[src].push_back({des,cost});
            adj[des].push_back({src,cost});
        }
        //creating wt array for storing probability it is initialized with -1 which means we have not reach it
        vector<double> wt(n,-1);
        //creating a priority queue for max operation since we need to find a max probability in each iteration and the vertex associated with it.
        priority_queue<pair<double,int> > pq;
        //storing the start point since we need to multiply probability so we make probability as 1
        pq.push({1.0,start});
        //and weight as zero
        wt[start]=0;
        // iterate till queue is empty or we find the target
        while(!pq.empty()){
        	//pop the max element
            auto temp = pq.top();
            pq.pop();
            //finding probability
            double cost = temp.first;
            //the vertex associated
            int curr = temp.second;
            //if it is the target then cost holds the answer
            if(curr==end)return cost;
            //otherwise iterate over adjacency list of the vertex and push vertex if they are better than the current probability
            for(auto x : adj[curr]){
            	//the destination of the edge
                int des= x.first;
                //the probability of the edge
				double prob = x.second;
                //we check if there is edge from u ---> v the probability of edge * probability of u > probability of v the we need update it. 
				if(prob*cost>wt[des]){
					//updating with new probability
                    wt[des]=prob*cost;
                    //pushing it our queue
                    pq.push({prob*cost,des});
                }
            }
        }
        //there is not path from start to end so we return 0
        return 0.0;
    }
};
