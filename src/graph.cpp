// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, const string& airline , int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight,airline});
    if (!hasDir) nodes[dest].adj.push_back({src, weight,airline});
}


// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

pair<pair<string ,string >, int> Graph::diameter() {
    int max_dist = 0;
    string startingAirport;
    string endingAirport;
    for(int a = 1; a <= n; a++) {
        for (int i = 1; i <= n; i++) {
            nodes[i].visited = false;
            nodes[i].distance = -1;
        }
        queue<int> q;
        q.push(a);
        nodes[a].visited = true;
        nodes[a].distance = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto e: nodes[u].adj) {
                int w = e.dest;
                if (!nodes[w].visited) {
                    q.push(w);
                    nodes[w].visited = true;
                    nodes[w].distance = nodes[u].distance + 1;
                    if (nodes[w].distance > max_dist){
                        max_dist = nodes[w].distance;
                        startingAirport = nodes[a].airport;
                        endingAirport = nodes[w].airport;
                    }
                }
            }
        }
    }
    return make_pair(make_pair(startingAirport, endingAirport), max_dist);
}

void Graph::setAirport(int v, const string &airport) {
    nodes[v].airport = airport;
}

list<pair<int, string>> Graph::getFlights( int node){
    list<pair<int, string>> res ;
    for (const Edge& e : nodes[node].adj)
        res.emplace_back(e.dest,e.airline);
    return res;
}

string Graph::getAirport(int v) {
    return nodes[v].airport;
}

int Graph::getNumFlightsTotal(){
    int count = 0;
    for(auto& x : nodes){
        count += x.adj.size();
    }
    return count;
}

int Graph::getNumFlightsAirport(string code){
    int count = 0;
    for(auto& x : nodes){
        if(x.airport == code){
            count += x.adj.size();
        }
    }
    for(auto& x : nodes){
        for(auto& i : x.adj){
            if(getAirport(i.dest) == code) count++;
        }
    }
    return count;
}


list<string> Graph::getAirportsReachable(int v, int f) {
    list<string> res;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].distance = 0;
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        if (nodes[u].distance > f)
            break;
        res.push_back(nodes[u].airport);
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                nodes[w].distance = nodes[u].distance +1;
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
    res.pop_front();
    return res;
}

list<list<string>> Graph::calculateBestTrajectory(const list<int>& startup, const list<int>& end, const list<string>& airlines) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    list<list<string>> res;
    int max_distance = 0;

    queue<list<int>> q;
    for (int s : startup){
        list<int> initial_list;
        initial_list.push_back(s);
        q.push(initial_list);
        nodes[s].visited = true;
        nodes[s].distance = 0;
    }
    while (!q.empty()) {
        list<int> nodes_list = q.front();
        int u = nodes_list.back();
        if (max_distance != 0 && nodes[u].distance == max_distance) break;
        q.pop();
        for (const auto& e : nodes[u].adj) {
            int w = e.dest;
            if ((!nodes[w].visited || nodes[w].distance == nodes[u].distance +1 ) && (airlines.empty() || find(airlines.begin(),airlines.end(),e.airline)!=airlines.end())) {
                if ( max_distance == 0 && find(end.begin(),end.end(),w) != end.end()){
                    max_distance = nodes[u].distance +1;
                }
                list<int> new_list (nodes_list);
                new_list.push_back(w);
                q.push(new_list);
                nodes[w].distance = nodes[u].distance +1;
                nodes[w].visited = true;
            }
        }
    }
    if (max_distance == 0) return res;
    while (!q.empty()){
        list<int> nodes_list = q.front();
        q.pop();
        int u = nodes_list.back();
        if (find(end.begin(),end.end(),u) != end.end()){
            list<string> temp;
            for (int node : nodes_list){
                temp.push_back(nodes[node].airport);
            }
            res.push_back(temp);
        }
    }
    return res;
}








