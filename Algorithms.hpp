#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>

//I.D: 322623323
//mail: mamon8521@gmail.com 


namespace ariel {

    class Algorithms {
    public:
        static bool isConnected(const Graph& graph);
        static std::string shortestPath(const Graph& graph, int start, int end);
        static std::string isContainsCycle(const Graph& graph);
        static std::string isBipartite(const Graph& graph);
        static std::string negativeCycle(const Graph& graph);
    private:
        static void dfs(const Graph& graph, int node, std::vector<bool>& visited);  
        static bool hasCycleDFS(const Graph& graph, int node, std::vector<bool>& visited, std::vector<int>& parent, std::vector<std::vector<int>>& cycles);

    };

} 

#endif 
