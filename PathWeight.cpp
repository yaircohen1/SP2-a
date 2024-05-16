// Coheny405@gmail.com
// 206386708

#include "PathWeight.hpp"
using namespace std;

namespace ariel{
    // Function to find the shortest path in a weighted graph using Dijkstra's algorithm
    string PathWeight::shortestPathDijkstra(const Graph& g, size_t start, size_t end){
        size_t numV = g.getNumV();
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        vector<int> d(numV, numeric_limits<int>::max());
        vector<int> parent(numV, -1);

        d[start] = 0;
        // Priority queue to store vertices with their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int start_int = static_cast<int>(start);
        pq.push({0,start_int}); // first pair is distance = 0, and ver = start_int
        // Dijkstra's algorithm loop
        while (!pq.empty()) {
            int dCurrentVer = pq.top().first;
            int currentVer = pq.top().second;
            pq.pop(); // Remove the vertex with the smallest distance
            for (size_t neighbor = 0; neighbor<numV; ++neighbor){
                // Check if theres an edge between current V to its neighbors and check if its not already checked
                if(inputMatrix[size_t(currentVer)][neighbor]!=0) {
                  int weight = inputMatrix[size_t(currentVer)][neighbor];
                  // Relaxation step
                    if (d[neighbor] > d[size_t(currentVer)] + weight) {
                        d[neighbor] = d[size_t(currentVer)] + weight;
                        parent[neighbor] = currentVer;
                        pq.push({d[neighbor], static_cast<int>(neighbor)}); // Update the priority queue with the new distance
                        }
                    }
                }
        }

        // Check if there's no path from the start vertex to the end vertex
        if (d[end] == numeric_limits<int>::max()) {
            return "-1"; // Return -1 if the end vertex is not reachable
        }
        // Construct the shortest path string
        string pathStr = to_string(end);
        size_t current = end;
        while (parent[current] != parent[start]) {
            pathStr = to_string(parent[current]) + "->" + pathStr;
            current = size_t(parent[current]);
        }
        return pathStr; // Return the constructed path string
    }   

    // Function to find the shortest path in a weighted graph with negative edges using the Bellman-Ford algorithm
    string PathWeight::shortestPathBellmanFord(const Graph& g, size_t start, size_t end, bool flag) {
        size_t numV = g.getNumV();
        const vector<vector<int>> &inputMatrix = g.getMatrix();
        vector<int> d(numV, numeric_limits<int>::max());
        vector<int> parent(numV, -1);

        d[start] = 0;

        // Relax edges numV-1 times
        for (size_t relax = 1; relax < numV; ++relax) {
            for (size_t u = 0; u < numV; ++u) {
                for (size_t v = 0; v < numV; ++v) {
                    // Check if there's an edge from u to v and if d[u] isn't max to add weight
                    if (inputMatrix[u][v] != 0 && d[u] != numeric_limits<int>::max()) {
                        int weight = inputMatrix[u][v];
                        if (d[u] + weight < d[v]) {
                            d[v] = d[u] + weight;
                            parent[v] = static_cast<int>(u);
                        }
                    }
                }
            }
        }

        // Check for negative-weight cycles (one more round of relaxtion)
        bool negativeCycleFound = false;
        for (size_t u = 0; u < numV; ++u) {
            for (size_t v = 0; v < numV; ++v) {
                // Check if there's an edge from u to v and if d[u] isn't max to add weight
                if (inputMatrix[u][v] != 0 && d[u] != numeric_limits<int>::max()) { 
                    int weight = inputMatrix[u][v];
                    if (d[u] + weight < d[v]) {
                        // if flag is true the function got a call from negativeCycle(g)
                        if(flag){
                            vector<int> cycle;
                            int currentVer = static_cast<int>(u);
                            // Track back the cycle
                            do {
                            cycle.push_back(currentVer);
                            currentVer = parent[size_t(currentVer)];
                            } while (currentVer != static_cast<int>(u) && currentVer != -1);

                            cycle.push_back(static_cast<int>(u)); // Add the start vertex of the cycle 
                            reverse(cycle.begin(), cycle.end()); // Reverse the cycle to get the correct order
                            string cycleStr;
                            for (size_t i = 0; i < cycle.size(); ++i) {
                                if (i > 0) cycleStr += "->";
                                    cycleStr += to_string(cycle[i]);
                            }
                            negativeCycleFound = true;
                            return "Negative Cycle: " + cycleStr;  // Return the negative cycle
                        }
                        else {
                            return "error: negative cycle";
                        }
                    }
                }
            }
        }
        if (!negativeCycleFound && flag) {
            return "No negative cycle found";
        }
        
        // Check if there's no path from the start vertex to the end vertex
        if (d[end] == numeric_limits<int>::max()) {
            return "-1";
        }

        // Construct the shortest path string
        string pathStr = to_string(end);
        size_t current = end;
        while (parent[current] != parent[start]) {
            pathStr = to_string(parent[current]) + "->" + pathStr;
            current = size_t(parent[current]);
        }
        if (d[end]<0) return "Negative path: "+ pathStr; // Return negative path if the distance is negative
        
        return pathStr;
    }  
    
};