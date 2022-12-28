// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}


// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
// TODO
int Graph::outDegree(int v) {
    if (v <1 || v >= nodes.size()) return -1;
    int sum = 0;
    for (Edge edge : nodes[v].adj){
        if (edge.dest != v) sum++;
    }
    return sum;
}

// ..............................
// b) Devolvendo o grau... pesado
// TODO
int Graph::weightedOutDegree(int v) {
    if (v <1 || v >= nodes.size()) return -1;
    int sum = 0;
    for (Edge edge : nodes[v].adj){
        if (edge.dest != v) sum += edge.weight;
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO
int Graph::connectedComponents() {
    int sum =0;
    for (Node& node : nodes){
        node.visited =0;
    }
    while (true){
        int first = -1;
        for (int i =1 ; i<nodes.size();i++)
            if (!(nodes[i].visited)) {
                first = i;
                break;
            }
        if (first == -1) break;
        sum++;
        dfs(first);
    }
    return sum;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int res = 0;
    for (Node& node : nodes){
        node.visited =0;
    }
    while (true){
        int first = -1;
        for (int i =1 ; i<nodes.size();i++)
            if (!(nodes[i].visited)) {
                first = i;
                break;
            }
        if (first == -1) break;
        int number = numberOfNodesInComponent(first);
        if (number >res) res = number;
    }
    return res;
}

int Graph::numberOfNodesInComponent(int v){
    nodes[v].visited = true;
    int sum = 1;
    for (Edge edge : nodes[v].adj){
        int w = edge.dest;
        if (!nodes[w].visited){
            sum += numberOfNodesInComponent(w);
        }
    }
    return sum;
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO
list<int> Graph::topologicalSorting() {
    list<int> res;
    list<int> temp;
    for (Node& n : nodes){
        n.visited = false;
    }
    for (int i = 1 ; i<nodes.size();i++){
        if (!nodes[i].visited){
            temp = orderStartingByV(i);
            res.insert(res.begin(),temp.begin(),temp.end());
        }
    }
    return res;
}

list<int> Graph::orderStartingByV(int v){
    list<int> res;
    nodes[v].visited = true;
    for (Edge edge : nodes[v].adj){
        int w = edge.dest;
        if (!nodes[w].visited){
            list<int> temp = orderStartingByV(w);
            res.insert(res.begin(),temp.begin(),temp.end());
        }
    }
    res.push_front(v);
    return res;
}

// ----------------------------------------------------------
// Exercicio 4: To be or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    for (Node& n : nodes) n.visited = false;
    for(int i = 1 ; i <nodes.size();i++)
        if (!nodes[i].visited)
            if (virifyCicle(i)) return true;
    return false;
}

bool Graph::virifyCicle(int n){
    nodes[n].visited = true;
    for (Edge e : nodes[n].adj){
        int w = e.dest;
        if (n != w && nodes[w].visited) return true;
        if (virifyCicle(w)) return true;
    }
    nodes[n].visited = false;
    return false;
}
