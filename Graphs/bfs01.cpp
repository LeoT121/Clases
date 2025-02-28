//Esta funcion recibe como parametros el grafo en un vector de pairs
//El first es el nodo y el second es un booleano que indica el peso

vector<int> bfs_01(vector<vector<pair<int, bool>>> & graph, int start){
    int n = int(graph.size());
    vector<int> dist(n, n + 1);
    deque<int> dq;
    dist[start] = 0;
    dq.push_front(start);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        for(auto & [v, w] : graph[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                if(w)
                    dq.push_back(v);
                else
                    dq.push_front(v);
            }
        }
    }
    return dist;
}