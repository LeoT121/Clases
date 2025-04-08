void dfs1(int u, vector<vector<int>> & graph, vector<bool> & vis, vector<int> & order){
    vis[u] = 1;
    for(int & v : graph[u]){
        if(vis[v]) continue;
        dfs1(v, graph, vis, order);
    }
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>> & graph, vector<bool> & vis, vector<int> & id_scc, int & num){
    vis[u] = 0;
    id_scc[u] = num;
    for(int & v : graph[u]){
        if(!vis[v]) continue;
        dfs2(v, graph, vis, id_scc, num);
    }
}


void scc(vector<vector<int>> & graph){
    int n = int(graph.size());
    vector<bool> vis(n, 0);
    vector<int> order;
    vector<vector<int>> t_graph(n, vector<int>());
    for(int u = 0; u < n; ++ u){
        for(int & v : graph[u]){
            t_graph[v].push_back(u);
        }
    }
    for(int u = 0; u < n; ++ u){
        if(vis[u]) continue;
        dfs1(u, graph, vis, order);
    }
    vector<int> id_scc(n);
    int num_scc = 0;
    for(int i = n - 1; i >= 0; -- i){
        int u = order[i];
        if(!vis[u]) continue;
        dfs2(u, t_graph, vis, id_scc, ++ num_scc);
    }
}