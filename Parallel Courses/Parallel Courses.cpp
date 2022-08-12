int parallelCourses(int n, vector<vector<int>> &pre){

	//using kahn algorithm to find top sort
	//in degree array +1 because the node value start from 1
    vector<int> in(n+1,0);
    //adjacency list to store graph
    vector<int> adj[n+1];
    //iterate over pre array and create in degree array as well as adjacency list
    for(auto x : pre){
        in[x[1]]++;
        adj[x[0]].push_back(x[1]);
    }
    in[0]=INT_MAX;
    //queue for storing zero indegree vertices
    queue<int> q;
    //iterating over indegree array and pushing all zero indegree node into queue
    for(int i=0;i<n+1;i++){
        if(in[i]==0)q.push(i);
    }
    //cnt stores the number of semester required to complete all course if possible and ts stores the top sort size
    int cnt = 1,ts=0;
    while(!q.empty()){
    	//storing the current queue size
        int sz = q.size();
        bool flag = false;
        //iterating over all queue nodes
        for(int i=0;i<sz;i++){
            int curr = q.front();
            //increase count of ts since we got a new node in ts order
            ts++;
            q.pop();
            //move over all the nodes that are connected to curr and decrease their indegree by 1 if some nodes indegree becomes zero it means we have a new independent course
            for(auto x: adj[curr]){
                in[x]--;
                if(in[x]==0){
                    flag=true;
                    q.push(x);
                }
            }
        }
        //if we found some independent course then those independent course can be scheduled in same semester
        if(flag){
            cnt++;
        }
    }
    
    //if top sort ordering is possible then our ans is valid otherwise we return -1
    return (ts==n)?cnt: -1;
}

