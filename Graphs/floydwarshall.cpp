//Esta funcion recibe como parametros el grafo en un vector de pairs
//El first es el nodo y el second es el peso de la arista

vector<vector<long long int>> floydwarshall(vector<vector<pair<int, long long int>>> & graph){
    int n = int(graph.size());
    vector<vector<long long int>> dist(n, vector<long long int>(n, 1e18));
    for(int u = 0; u < n; ++ u){
        for(auto & [v, w] : graph[u]){
            dist[u][v] = w;
        }
    }
    for(int k = 0; k < n; ++ k){
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //Si existe un ciclo negativo entonces hay algun nodo u tal que dist[u][u] < 0
    return dist;
}