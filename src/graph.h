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

    /**
     * Depth-First Search: example implementation
     * @param v
     */
    void dfs(int v);

    /**
     * Breadth-First Search: example implementation
     * @param v
     */
    void bfs(int v);

    /**
     * Changes the code of the airport of node v to airport
     *
     * Complexity : constant
     * @param v
     * @param airport
     */
    void setAirport(int v , const string& airport);

    /**
     * Gives the flights that leave a certain airport
     * Complexity : O(n) being n the amount of flights that leave airport v
     * @param node of the airport
     * @return list of pair each containing the node of the destination airport and the code of the airline
     */
    list<pair<int , string>> getFlights(int node);

    /**
     * @param v
     * @return Code of the airport
     */
    string getAirport(int v);

    /**
     * Calculates the airports that you can go to from airport v with a maximum number of flights f
     * Complexity : O(|V| + |E|) where |V| and |E| is the cardinality of set of vertices and edges respectively.
     * @param v node of the starting airport
     * @param f maximum number of flights
     * @return list with the codes of the airports
     */
    list<string> getAirportsReachable(int v, int f);

    list<list<string>> calculateBestTrajectory(const list<int>& startup,const list <int>& end,const list<string>& airlines);

    string getAirline(int a , int b , list<string> air);

};

#endif
