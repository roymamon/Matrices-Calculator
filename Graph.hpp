#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>

//I.D: 322623323
//mail: mamon8521@gmail.com 


namespace ariel {

    class Graph {
    public:
        Graph() = default;
        ~Graph() = default;

        void loadGraph(const std::vector<std::vector<int>>& adjacencyMatrix);
        void printGraph() const;
        int size() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

        Graph operator+(const Graph& other) const;
        void operator+();
        Graph& operator+=(const Graph& other);
        Graph operator++();
        Graph operator++(int);


        Graph operator-(const Graph& other) const;
        void operator-();
        Graph& operator-=(const Graph& other);
        Graph operator--();
        Graph operator--(int);
      

        Graph& operator*=(int scalar);
        Graph& operator/=(int scalar);
        Graph operator*(const Graph& other) const;

        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);



    private: 
        std::vector<std::vector<int>> adjacencyMatrix;
        
    };

} 

#endif 
