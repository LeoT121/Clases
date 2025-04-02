vector<int> toposort(vector<vector<int>> & graph){
    int n = int(graph.size());
    vector<int> indegree(n, 0);
    for(int u = 0; u < n; ++ u){
        for(auto & v : graph[u]){
            indegree[v] ++;
        }
    }
    queue<int> q;
    for(int u = 0; u < n; ++ u){
        if(!indegree[u]){
            q.push(u);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto & v : graph[u]){
            indegree[v]  --;
            if(!indegree[v]){
                q.push(v);
            }
        }
    }
    if(int(topo.size()) < n) return {};
    return topo;
}