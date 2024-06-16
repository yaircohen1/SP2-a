// Coheny405@gmail.com
// 206386708

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    // Test #1
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Test #2
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test #3
     vector<vector<int>> graph3 = {
        {0, 5, 8, 0},
        {1, 0, 1, 0},
        {3, -3, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Test #4
     vector<vector<int>> graph4 = {
        {0, 5, 1, 0, 7},
        {1, 0, 1, 0, -4},
        {1, -3, 0, 1, 0},
        {0, 8, 9, 0, 0},
        {0, 10, 0, 12, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    
    // Test #5
     vector<vector<int>> graph5 = {
        {0, 2, 1, 0, 5, -2},
        {2, 0, 1, 0, -2, 6},
        {1, 1, 0, 1, 0, 10},
        {0, 0, 1, 0, -8, 12},
        {5, -2, 0, -8, 0, 1},
        {-2, 6, 10, 12, 1, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Test #6
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");

    // Test #7
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    // Test #8 #9 #10 #11 #12
     vector<vector<int>> graph3 = {
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {-3, 0, 0, 0},
        {0, 0, -2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 1) == "2->0->1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "Negative path: 2->0");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "-1");
    
    // Test #13 #14
    vector<vector<int>> graph4 = {
        {0, -5, 0, 0},
        {0, 0, 0, 0},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "Negative path: 3->0->1");

     // Test #15 #16
     vector<vector<int>> graph5={{0, 0, 1, 1, 0},
                                {10, 0, 10, 0, 0},
                                {1, 10, 0, 5, 2},
                                {1, 12, 1, 0, 0},
                                {0, 0, 2, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g,3,1)=="3->2->1");
    CHECK(ariel::Algorithms::shortestPath(g,1,3)=="1->0->3");

}

TEST_CASE("Test isContainsCycle")
{
    // Test #17
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Test #18
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    // Test #19
    vector<vector<int>> graph3 = {
        {0, 0, 1, 1, 0},
        {10, 0, 10, 0, 0},
        {1, 10, 0, 5, 2},
        {1, 12, 1, 0, 0},
        {0, 0, 2, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g)=="The cycle is: 0->2->0");

    // Test #20
    vector<vector<int>> graph4 = {
        {0, -5, 0, 0},
        {0, 0, 1, 1},
        {-3, 0, 0, -8},
        {-6, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "Group A: {0, 2}\nGroup B: {1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test negative cycle in the graph")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle found");

     vector<vector<int>> graph2 = {
        {0, 5, 8, 0},
        {1, 0, 1, 0},
        {3, -3, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative Cycle: 1->2->1");

     vector<vector<int>> graph3 = {
        {0, 5, 1, 0, 7},
        {1, 0, 1, 0, -4},
        {1, -3, 0, 1, 0},
        {0, 8, 9, 0, 0},
        {0, 10, 0, 12, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Negative Cycle: 1->2->1");
}