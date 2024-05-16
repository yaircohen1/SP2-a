// Coheny405@gmail.com
// 206386708

#include "Graph.hpp"
using namespace std;

namespace ariel {
    // Constructor for the Graph class
    Graph::Graph(): Matrix(), numV(0), numE(0), isDirected(false), isWeighted(false), isNegative(false) {}

    // Function to load a graph from an input matrix
    void Graph::loadGraph(const vector<vector<int>> &inputMatrix) {
        //Check if inputMatrix is valid
        // Check if the num of rows (mat.size) == num of columns (mat[0].size)
        if (inputMatrix.size() != inputMatrix[0].size()) {
            throw invalid_argument ("Invalid graph: The graph is not a square matrix.");
        }
        // Check if inputMatrix is empty (it has zero rows)
        if(inputMatrix.empty()){
            throw invalid_argument ("Invalid graph:: the matrix is empty");
        }
        // Load the matrix and set the number of vertices
        this->Matrix = inputMatrix;
        this->numV = inputMatrix.size();
        // Count the edges
        this->numE = 0; // Resets to default
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=0){
                    this->numE++;
                }
            }
        }
        // Check if the Graph is directed (if matrix is symmetric: yes - undirected, otherwise - directed)
        this->isDirected = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=Matrix[j][i]){
                    this->isDirected = true;
                    break;
                }
            }
        }
        // If the Graph is undirected (symmetric), the num of edges is numE/2
        if (!(isDirected)){
            this->numE = this->numE/2;
        }
        // Check if the Graph is weighted (if matrix has values other than 1 or 0 in the cells: yes - weighted, otherwise - weighted)
        this->isWeighted = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]!=1 && Matrix[i][j]!=0){
                    this->isWeighted = true;
                    break;
                }
            }
        }
        // Check if the Graph has negative weighted edges (if matrix has values less than 0: yes - negative , otherwise - un-negative)
        this->isNegative = false; // Resets to default 
        for(size_t i = 0; i < numV; i++) {
            for(size_t j = 0; j < numV; j++) {
                if (Matrix[i][j]<0){
                    this->isNegative = true;
                    break;
                }
            }
        }
    }

// Function to print information about the graph
void Graph::printGraph() const {
    cout << "Graph Info:" << endl;
    cout << "Directed: " <<  (this->isDirected ? "true" : "false") << endl; 
    cout << "Weighted: " << (this->isWeighted ? "true" : "false") << endl;
    cout << "Negative Edge: " << (this->isNegative ? "true" : "false") << endl;
    cout << "Number of Vertices: " << this->numV << endl;
    cout << "Number of Edges: " << this->numE << endl;
}

// Getters 
const vector<vector<int>>& Graph::getMatrix() const {return this->Matrix;}
size_t Graph::getNumV() const {return this->numV;}
size_t Graph::getNumE() const {return this->numE;}
bool Graph::getIsDirected() const {return this->isDirected;}
bool Graph::getIsWeighted() const {return this->isWeighted;}
bool Graph::getHasNegativeEdges() const {return this->isNegative;}

// Destructor for the Graph class
Graph::~Graph() {}
}

