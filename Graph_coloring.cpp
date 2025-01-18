#include <bits/stdc++.h>
using namespace std;

#define V 5 // Number of vertices in graph

// A function to check if the current color assignment is valid
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false; // adjacent vertex has the same color
        }
    }
    return true;
}

// Function to assign colors to vertices of graph using backtracking
bool graphColoring(int graph[V][V], int m, int color[], int v) {
    if (v == V) return true; // All vertices are assigned colors

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color to vertex

            if (graphColoring(graph, m, color, v + 1)) {
                return true; // Recur for next vertex
            }

            color[v] = 0; // Backtrack
        }
    }
    return false; // No valid color found for this vertex
}

// Function to solve the m-coloring problem
bool solveGraphColoring(int graph[V][V], int m) {
    int color[V] = {0}; // Array to store colors assigned to vertices

    if (!graphColoring(graph, m, color, 0)) {
        cout << "Solution does not exist";
        return false;
    }

    // Print the color assignment
    cout << "Solution exists: The color assignments are:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
    return true;
}

int main() {
    // Example graph (adjacency matrix)
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int m = 3; // Number of colors
    solveGraphColoring(graph, m);

    return 0;
}


