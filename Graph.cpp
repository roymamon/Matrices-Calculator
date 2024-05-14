#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

//I.D: 322623323
//mail: mamon8521@gmail.com 


using namespace std;

namespace ariel {

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    void Graph::loadGraph(const vector<vector<int>>& adjacencyMatrix) {
        if (adjacencyMatrix.empty() || adjacencyMatrix.size() != adjacencyMatrix[0].size()) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        this->adjacencyMatrix = adjacencyMatrix;
    }

    void Graph::printGraph() const {
        cout << "Graph with " << size() << " vertices and ";
        int edges = 0;
        for (const auto& row : adjacencyMatrix) {
            for (int val : row) {
                if(val != 0){
                edges ++;
            }
        }
        }
        
        cout << edges << " edges." << endl;
    }

    int Graph::size() const {
        return adjacencyMatrix.size();
    }

    Graph Graph::operator+(const Graph& other) const {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs need to be the same size");
        }

        std::vector<std::vector<int>> result(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix.size(), 0));
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                result[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
            }
        }
        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

    Graph& Graph::operator*=(int scalar) {
        for (auto& row : adjacencyMatrix) {
            for (auto& val : row) {
                val *= scalar;
            }
        }
        return *this;
    }

    Graph& Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        for (auto& row : adjacencyMatrix) {
            for (auto& val : row) {
                val /= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph& other) const {
        if (adjacencyMatrix[0].size() != other.adjacencyMatrix.size()) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        std::vector<std::vector<int>> result(adjacencyMatrix.size(), std::vector<int>(other.adjacencyMatrix[0].size(), 0));
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < other.adjacencyMatrix[0].size(); ++j) {
                for (size_t k = 0; k < adjacencyMatrix[0].size(); ++k) {
                    if(i != j){
                    result[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
                }
            }
        }

        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
       
        for (size_t i = 0; i < graph.adjacencyMatrix.size(); ++i) {
            os << "[";
            for (size_t j = 0; j < graph.adjacencyMatrix[i].size(); ++j) {
                os << graph.adjacencyMatrix[i][j] << (j < graph.adjacencyMatrix[i].size() - 1 ? ", " : "");
            }
            os << "]" << (i < graph.adjacencyMatrix.size() - 1 ? ", " : "");
        }
        os << endl;
        return os;
    }

    void Graph::operator+()  {
         for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                adjacencyMatrix[i][j] = 1 * adjacencyMatrix[i][j];
            }
        }
    }
    


    void Graph::operator-() {
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                adjacencyMatrix[i][j] = -adjacencyMatrix[i][j];
            }
        }
    }

    Graph& Graph::operator+=(const Graph& other) {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Graphs need to be the same size");
        }
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph& Graph::operator-=(const Graph& other) {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Graphs need to be the same size");
        }
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
            }
        }
        return *this;
    }

    Graph Graph::operator-(const Graph& other) const {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs need to be the same size");
        }

        std::vector<std::vector<int>> result(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix.size(), 0));
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                result[i][j] = adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
            }
        }
        Graph newGraph;
        newGraph.loadGraph(result);
        return newGraph;
    }

     bool Graph::operator==(const Graph& other) const {
        if (this->size() != other.size()) {
            return false;
        }
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[i] != other.adjacencyMatrix[i]) {
                return false;
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph& other)const {
        return !(*this == other);
    }

    void Graph::operator++()  {
         for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                if(i != j){
                adjacencyMatrix[i][j] = 1 + adjacencyMatrix[i][j];
            }
        }
      }
    }

    void Graph::operator--()  {
         for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                if(i != j){
                adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - 1;
            }
        }
    }
 }

     bool contains(const Graph& G1, const Graph& G2) {

        const auto& matrix1 = G1.getAdjacencyMatrix();
        const auto& matrix2 = G2.getAdjacencyMatrix();

        int size1 = matrix1.size();
        int size2 = matrix2.size();

        if (size1 < size2) {
            return false; 
        }

        for (int i = 0; i < size2; i++) {
            for (int j = 0; j < size2; j++) {
                if (matrix2[i][j] != 0 && (matrix1[i][j] == 0 || matrix1[i][j] < matrix2[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

        int countEdges(const std::vector<std::vector<int>>& matrix) {
          int count = 0;
            for (const auto& row : matrix) {
              for (int val : row) {
                  if (val != 0) {
                    count++;
                }
            }
        }
        return count;
    }

        bool Graph::operator>(const Graph& other) const {
        if (contains(*this, other)) return true;
        if (contains(other, *this)) return false;

        int thisEdges = countEdges(adjacencyMatrix);
        int otherEdges = countEdges(other.adjacencyMatrix);
        if (thisEdges != otherEdges) {
            return (thisEdges > otherEdges);
        }

        return std::lexicographical_compare(other.adjacencyMatrix.begin(), other.adjacencyMatrix.end(),
           adjacencyMatrix.begin(), adjacencyMatrix.end(),
             std::greater<std::vector<int>>());
    }

    bool Graph::operator<(const Graph& other) const {
    if (contains(*this, other)) return false;  
    if (contains(other, *this)) return true;   

    int thisEdges = countEdges(adjacencyMatrix);
    int otherEdges = countEdges(other.adjacencyMatrix);
    if (thisEdges != otherEdges) {
        return thisEdges < otherEdges;  
    }

    return std::lexicographical_compare(
        adjacencyMatrix.begin(), adjacencyMatrix.end(),
        other.adjacencyMatrix.begin(), other.adjacencyMatrix.end()
    );

    
  }

     bool Graph::operator>=(const Graph& other) const {
     
      if(*this == other || *this > other){
        return true;
     }

     return false;

}

      bool Graph::operator<=(const Graph& other) const {
     
       if(*this == other || *this < other){
        return true;
     }

     return false;

}
}

