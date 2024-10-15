#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list representation

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add edge from u to v
        adj[v].push_back(u); // Uncomment this line for undirected graph
    }

    void displayGraph() {
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (int neighbor : adj[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            std::cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }

    void dfsUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        std::vector<bool> visited(V, false);
        dfsUtil(start, visited);
        std::cout << std::endl;
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Graph adjacency list:" << std::endl;
    g.displayGraph();

    std::cout << "BFS starting from vertex 0:" << std::endl;
    g.bfs(0);

    std::cout << "DFS starting from vertex 0:" << std::endl;
    g.dfs(0);

    return 0;
}
