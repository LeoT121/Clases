//Este algoritmo retorna la minima distancia a todos los nodos a partir de un nodo inicial
//La complejidad del algoritmo es O(|V| * |E|)
//Los parametros de la funcion son el lista de adyacencia del grafo, se guardan en un pair
//El first es el nodo la arista apunta, y el second el peso de la arista
//Retorna un vector con las distancias
//Si hay un ciclo negativo entonces la funcion retorna un vector vacio
vector<long long int> bellmanford(vector<vector<pair<int, long long int>>> & graph, int start){
    int n = int(graph.size());
    vector<long long int> dist(n, 1e18);
    vector<int> processed(n, 0);
    vector<bool> inqueue(n, 0);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    inqueue[start] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inqueue[u] = 0;
        ++ processed[u];
        //Si se procesa n veces eso quiere decir que hay un ciclo negativo, por lo que retorno un vector vacio
        if(processed[u] == n){
            return {};
        }
        for(auto & [v, w] : graph[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(inqueue[v]) continue;
                inqueue[v] = 1;
                q.push(v);
            }
        }
    }
    return dist;
}