// AED 2022/2023 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [last update: 27/11/2022]

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        string airline;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        string airport;
        int distance;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    /**
     * Add edge from source to destination with a certain weight
     * @param src
     * @param dest
     * @param airline
     * @param weight
     */
    void addEdge(int src, int dest,const string& airline, int weight = 1);


    void dfs(int v);


    void bfs(int v);

    void setAirport(int v , const string& airport);


    list<pair<int , string>> getFlights(int node);

    string getAirport(int v);

    list<string> getAirportsReachable(int v, int f);

    list<list<string>> calculateBestTrajectory(const list<int>& startup,const list <int>& end,const list<string>& airlines);
    bool existPath(int v, int k);
    void showPath (int v1, int v2);
    list<int> dfsShow(int v);
    string getAirline(int a , int b , list<string> air);
    int getNumFlightsTotal();

    int getNumFlightsAirport(int v);

    pair<pair<std::string, std::string>, int> diameter();
    // show articulation points
};

#endif
