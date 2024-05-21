#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Algorithms.hpp"
#include "Graph.hpp"

//I.D: 322623323
//mail: mamon8521@gmail.com 

using namespace std;

void testGraphAddition() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    ariel::Graph expectedGraph;
    vector<vector<int>> expectedGraphMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    expectedGraph.loadGraph(expectedGraphMatrix);

    assert(g3 == expectedGraph);



    ariel::Graph expectedGraph2;
    vector<vector<int>> expectedGraphMatrix2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    expectedGraph2.loadGraph(expectedGraphMatrix2);

    +g1; // doesnt change the graph

    assert(g1 == expectedGraph2);

    g1 += g2;

    ariel::Graph expectedGraph3;
    vector<vector<int>> expectedGraphMatrix3 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    expectedGraph3.loadGraph(expectedGraphMatrix3);

    assert(g1 == expectedGraph3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}
    };
    g4.loadGraph(graph4);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g5.loadGraph(graph5);

   ariel::Graph g6;
    vector<vector<int>> matrix6 = {
        {0, 2, 1},
        {2, 0, 2},
        {1, 2, 0}
    };
    g6.loadGraph(matrix6);

    ariel::Graph g7;
    ariel::Graph g8;

    g7 = ++g5;
    g8 = g5++;

    assert(g7 == g6);
    assert(g8 == g6);







    


}

void testGraphSubtraction() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    ariel::Graph expectedGraph;
    vector<vector<int>> expectedGraphMatrix = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}
    };
    expectedGraph.loadGraph(expectedGraphMatrix);

    assert(g3 == expectedGraph);


    ariel::Graph expectedGraph2;
    vector<vector<int>> expectedGraphMatrix2 = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}
    };
    expectedGraph2.loadGraph(expectedGraphMatrix2);

    -g1; // switch signs

    assert(g1 == expectedGraph2);

    -g1; //switch back for the next test


    ariel::Graph expectedGraph3;
    vector<vector<int>> expectedGraphMatrix3 = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}
    };
    expectedGraph3.loadGraph(expectedGraphMatrix3);

    g1 -= g2;

    assert(g1 == expectedGraph3);

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g4.loadGraph(graph4);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g5.loadGraph(graph5);

   ariel::Graph g6;
    vector<vector<int>> matrix6 = {
        {0, 0, -1},
        {0, 0, 0},
        {-1, 0, 0}
    };
    g6.loadGraph(matrix6);

    ariel::Graph g7;
    ariel::Graph g8;

    g7 = --g5;
    g8 = g5--;

    assert(g7 == g6);
    assert(g8 == g6);


}

void testGraphMultiplication() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g4 = g1 * g2;
    ariel::Graph expectedGraph;
    vector<vector<int>> expectedGraphMatrix = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}
    };
    expectedGraph.loadGraph(expectedGraphMatrix);

    assert(g4 == expectedGraph);
}


void testScalarMultiplication() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    g1 *= 2;

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedGraphMatrix = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    expectedGraph.loadGraph(expectedGraphMatrix);

    assert(g1 == expectedGraph);
}

void testScalarDivision() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g1.loadGraph(graph);

    g1 /= 2;

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedGraphMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    expectedGraph.loadGraph(expectedGraphMatrix);

    assert(g1 == expectedGraph);
}



void testInvalidOperations() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    // Graph with different dimensions
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {2, 1, 1, 0}
    };

    try {
        g2.loadGraph(graph2);
        ariel::Graph result = g1 * g2; // This should fail
        assert(false); // Should not reach this point
    } catch (const std::exception& e) {
        // Expected to throw an exception
        std::cout << "Caught expected exception for *: " << e.what() << std::endl;
    }

    try {
        ariel::Graph result = g1 + g2; // This should also fail
        assert(false); // Should not reach this point
    } catch (const std::exception& e) {
        // Expected to throw an exception
        std::cout << "Caught expected exception for +: " << e.what() << std::endl;
    }

    try {
        g1 += g2; // This should fail
        assert(false); // Should not reach this point
    } catch (const std::exception& e) {
        // Expected to throw an exception
        std::cout << "Caught expected exception for +=: " << e.what() << std::endl;
    }

    try {
        ariel::Graph result = g1 - g2; // This should fail
        assert(false); // Should not reach this point
    } catch (const std::exception& e) {
        // Expected to throw an exception
        std::cout << "Caught expected exception for -: " << e.what() << std::endl;
    }

    try {
        g1 -= g2; // This should fail
        assert(false); // Should not reach this point
    } catch (const std::exception& e) {
        // Expected to throw an exception
        std::cout << "Caught expected exception for -=: " << e.what() << std::endl;
    }
}

void testEqualAndNotEqual() {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    
    g2.loadGraph(graph);
    assert(g1 == g2);

    ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 3, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g3.loadGraph(graph2);

    assert(g1 != g3);
}

void testBiggerAndSmaller(){

   ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); 

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2); 

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    g3.loadGraph(graph3); 

    ariel::Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(graph4); 

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}};
    g5.loadGraph(graph); 



    assert(g2 > g1); // contains
    assert(g3 > g1); // edges
    assert(g5 > g1); // dimensions

    assert(g2 >= g1);
    assert(g3 >= g1);
    assert(g1 >= g4); // equals
    
    assert(g1 < g2); // contains
    assert(g1 < g3); // edges
    assert(g1 < g5); // dimensions

    assert(g1 <= g2);
    assert(g1 <= g3);
    assert(g1 <= g4); // equals


}


    void testGraphOutput() {

    ariel::Graph g;
    vector<vector<int>> graphMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graphMatrix);

    std::ostringstream oss;
    oss << g;

    std::string expectedOutput = "[0, 1, 0], [1, 0, 1], [0, 1, 0]\n";
    assert(oss.str() == expectedOutput);
    
}

void test_algorithms1() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -3, 0, 0},
        {0, 0, -2, 0},
        {0, 0, 0, 4},
        {0, 0, 0, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == true);
    assert(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    assert(ariel::Algorithms::isContainsCycle(g) == "0");
    assert(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}.");
    assert(ariel::Algorithms::negativeCycle(g) == "no negative cycle");

}

void test_algorithms2() {
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, 4, 15},
        {0, 1, 0, 5},
        {0, -12, 1, 0}
    };
    g.loadGraph(graph);
    assert(ariel::Algorithms::isConnected(g) == true);
    assert(ariel::Algorithms::shortestPath(g, 1, 3) == "1->2->3");
    assert(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 3->2->1->3");
    assert(ariel::Algorithms::isBipartite(g) == "0");
    assert(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 2->3->1->2");
}





int main() {

    testGraphAddition();
    testGraphSubtraction();
    testGraphMultiplication();
    testScalarMultiplication();
    testScalarDivision();
    testEqualAndNotEqual();
    testBiggerAndSmaller();
    testInvalidOperations();
    testGraphOutput();

    test_algorithms1();
    test_algorithms2();

    std::cout << "all tests passed" << std::endl;
    return 0;

}
