vector<long long int> dijkstra(vector<vector<pair<int, long long int>>> & graph, int start){
    priority_queue<pair<long long int, int>> pq;
    int n = int(graph.size());
    vector<long long int> dist(n, 1e18);
    dist[start] = 0;
    for(auto & [v, w] : graph[start]){
        if(dist[v] > w){
            dist[v] = w;
            pq.push({w, v});
        }
    }
    while(!pq.empty()){
        int u;
        long long int w;
        tie(w, u) = pq.top();
        pq.pop();
        if(dist[u] != w) continue;
        for(auto & [v, w] : graph[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}