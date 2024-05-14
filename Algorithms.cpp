#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_set>
#include <limits> 

//I.D: 322623323
//mail: mamon8521@gmail.com 


using namespace std;

namespace ariel {

    //helper method
    void Algorithms::dfs(const Graph& graph, int node, vector<bool>& visited) {
        const auto& adjacencyMatrix = graph.getAdjacencyMatrix(); // Access adjacency matrix using new function
        visited[node] = true;
        for (int i = 0; i < graph.size(); ++i) {
            if (adjacencyMatrix[node][i] && !visited[i]) {
                Algorithms::dfs(graph, i, visited);
            }
        }
    }

    bool Algorithms::isConnected(const Graph& graph) {
        vector<bool> visited(graph.size(), false);
        Algorithms::dfs(graph, 0, visited);

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    string Algorithms::shortestPath(const Graph& graph, int start, int end) {
        const auto& adjacencyMatrix = graph.getAdjacencyMatrix();
        int n = adjacencyMatrix.size(); // Number of vertices

        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> pred(n, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start}); 

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (u == end) break;

            for (int v = 0; v < n; ++v) {
                if (adjacencyMatrix[u][v] != 0) { 
                    int weight = adjacencyMatrix[u][v];
                    if (dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        pred[v] = u;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        if (dist[end] == std::numeric_limits<int>::max()) {
            return "-1"; 
        }

        std::vector<int> path;
        for (int crawl = end; crawl != -1; crawl = pred[crawl]) {
            path.push_back(crawl);
        }
        std::reverse(path.begin(), path.end());

        std::string result;
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) result += "->";
            result += std::to_string(path[i]);
        }
        return result;
    }



    //helper method
    bool Algorithms::hasCycleDFS(const Graph& graph, int node, vector<bool>& visited, vector<int>& parent, vector<vector<int>>& cycles) {
    visited[node] = true;

    const auto& adjacencyMatrix = graph.getAdjacencyMatrix();
    for (int i = 0; i < graph.size(); ++i) {
        if (adjacencyMatrix[node][i]) {
            if (!visited[i]) {
                parent[i] = node;
                if (Algorithms::hasCycleDFS(graph, i, visited, parent, cycles)) {
                    return true;
                }
            } else if (parent[node] != i) {
                vector<int> cycle;
                int cur = node;
                while (cur != i) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(i);
                cycle.push_back(node);
                cycles.push_back(cycle);
                return true;
            }
        }
    }
    return false;
}


string Algorithms::isContainsCycle(const Graph& graph) {
        int n = graph.size();
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        std::vector<std::vector<int>> cycles;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (Algorithms::hasCycleDFS(graph, i, visited, parent, cycles)) {
                    for (const auto& cycle : cycles) {
                        std::string result = "The cycle is: ";
                        for (size_t j = 0; j < cycle.size(); ++j) {
                            if (j > 0) result += "->"; // Add arrows between nodes
                            result += std::to_string(cycle[j]);
                        }
                        return result; 
                    }
                }
            }
        }
        return "0";
    }





    string Algorithms::isBipartite(const Graph& graph) {
        int n = graph.size(); 
        std::vector<int> color(n, -1); 
        std::queue<int> q; 

        std::vector<int> setA, setB;  

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                color[i] = 0; 
                q.push(i);
                setA.push_back(i); 

                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    const auto& adjacencyMatrix = graph.getAdjacencyMatrix(); 

                    for (int v = 0; v < n; ++v) {
                        if (adjacencyMatrix[u][v] != 0) { 
                            if (color[v] == -1) { 
                                color[v] = 1 - color[u]; 
                                q.push(v);

                                if (color[v] == 0) {
                                    setA.push_back(v); 
                                } else {
                                    setB.push_back(v); 
                                }
                            } else if (color[v] == color[u]) { 
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        std::string result = "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i) {
            if (i > 0) result += ", ";
            result += std::to_string(setA[i]);
        }
        result += "}, B={";
        for (size_t i = 0; i < setB.size(); ++i) {
            if (i > 0) result += ", ";
            result += std::to_string(setB[i]);
        }
        result += "}.";
        return result;
    }

    string Algorithms::negativeCycle(const Graph& graph) {
        int n = graph.size();
        const auto& adjacencyMatrix = graph.getAdjacencyMatrix();
        std::vector<int> distance(n, std::numeric_limits<int>::max());
        std::vector<int> predecessor(n, -1);

        int start_vertex = 0;
        distance[start_vertex] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (adjacencyMatrix[u][v] != 0 && distance[u] != std::numeric_limits<int>::max() &&
                        distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                        distance[v] = distance[u] + adjacencyMatrix[u][v];
                        predecessor[v] = u;
                    }
                }
            }
        }

        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (adjacencyMatrix[u][v] != 0 && distance[u] != std::numeric_limits<int>::max() &&
                    distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                    std::vector<int> cycle;
                    for (int x = v; x != -1; x = predecessor[x]) { // Trace the cycle
                        if (std::find(cycle.begin(), cycle.end(), x) != cycle.end()) {
                            cycle.push_back(x);
                            break; 
                        }
                        cycle.push_back(x);
                    }
                    std::reverse(cycle.begin(), cycle.end());
                    std::string result = "The negative cycle is: ";
                    for (size_t i = 0; i < cycle.size(); ++i) {
                        result += std::to_string(cycle[i]);
                        if (i < cycle.size() - 1) result += "->";
                    }
                    return result;
                }
            }
        }

        return "no negative cycle";
    }



} 
