//Este algoritmo mantiene la cantidad de componentes que hay en un grafo bidireccional
//Los nodos estan 0-indexados

struct DSU{
    vector<int> p, sz;
    int numSets;
    // Constructor del DSU que inicializa los vectores de parent, size y el numero de sets
    DSU(int n) : numSets(n), p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    // Encuentra la raiz de cada set
    int find(int u) {
        return (p[u] == u) ? u : p[u] = find(p[u]);
    }
    //Funcion de unir dos nodos que comparten una arista
    void unite(int u, int v){
        int x = find(u);
        int y = find(v);
        //verificar si estan conectados
        if(x == y) return;
        if(sz[x] >= sz[y]) swap(x, y);
        sz[y] += sz[x];
        p[x] = y;
        numSets --;
    }
};