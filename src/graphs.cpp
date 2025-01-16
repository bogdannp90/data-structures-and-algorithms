// Description: This file contains the function definitions for graphs
#include "graphs.h"
#include <iostream>
#include "inputValidation.h"
#include "dynamicLists.h"
using namespace std;

// Function to convert an adjacency matrix to an adjacency list
vector<vector<int> > adjacencyMatrixToAdjacencyList(const vector<vector<int> > &AdjMatrix) {
    int NODE_COUNT = AdjMatrix.size();
    vector<vector<int> > adjList(NODE_COUNT);

    for (int i = 0; i < NODE_COUNT; ++i) {
        for (int j = 0; j < NODE_COUNT; ++j) {
            if (AdjMatrix[i][j] != 0) {
                // Add edge if there is a connection
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}

vector<vector<int> > nodeListToAdjacencyMatrix(const vector<vector<int> > &nodeList) {
    int n = nodeList.size();
    vector matrix(n, vector(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j: nodeList[i]) {
            matrix[i][j] = 1; // Assuming unweighted graph
        }
    }
    return matrix;
}

vector<edge> adjacencyMatrixToEdgeList(const vector<vector<int> > &adjMatrix) {
    vector<edge> edgeList;

    int n = adjMatrix.size(); // number of vertices
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // for undirected graph
            if (adjMatrix[i][j] != 0) {
                // there is an edge
                edge e = {i, j};
                edgeList.push_back(e);
            }
        }
    }
    return edgeList;
}

vector<vector<int> > edgeListToAdjacencyMatrix(const vector<edge> &edgeList, int n) {
    vector adjMatrix(n, vector<int>(n, 0)); // Initialize all elements as 0

    for (const auto &e: edgeList) {
        int u = e.node1;
        int v = e.node2;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }
    return adjMatrix;
}

vector<edge> nodeListToEdgeList(const vector<vector<int> > &nodeList) {
    vector<edge> edgeList;
    int n = nodeList.size();
    for (int i = 0; i < n; ++i) {
        for (int j: nodeList[i]) {
            if (i < j) {
                // for undirected graph
                edge e = {i, j};
                edgeList.push_back(e);
            }
        }
    }
    return edgeList;
}

vector<vector<int> > edgeListToNodeList(const vector<edge> &edgeList) {
    int n = 0;
    for (const auto &e: edgeList) {
        n = max(n, max(e.node1, e.node2)); // get the maximum node number
    }
    vector<vector<int> > nodeList(n + 1);
    for (const auto &e: edgeList) {
        nodeList[e.node1].push_back(e.node2);
        nodeList[e.node2].push_back(e.node1);
    }
    return nodeList;
}

void printAdjList(const vector<vector<int> > &AdjList) {
    int NODE_COUNT = AdjList.size();
    for (int i = 0; i < NODE_COUNT; ++i) {
        cout << i << " -> ";
        for (int j = 0; j < AdjList[i].size(); ++j) {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
}

void printAdjMatrix(const vector<vector<int> > &AdjMatrix) {
    int NODE_COUNT = AdjMatrix.size();
    for (int i = 0; i < NODE_COUNT; ++i) {
        for (int j = 0; j < NODE_COUNT; ++j) {
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printEdgeList(const vector<edge> &edgeList) {
    for (const auto &e: edgeList) {
        cout << "(" << e.node1 << ", " << e.node2 << ")" << endl;
    }
}

void dfsMain(const vector<vector<int> > &AdjList, int source) {
    int NODE_COUNT = AdjList.size();
    vector<bool> visited(NODE_COUNT, false);
    cout << "DFS traversal starting from node " << source << ": ";
    dfsRecursive(AdjList, source, visited);
    cout << endl;
}

void dfsRecursive(const vector<vector<int> > &AdjList, int node, vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;
    for (int i: AdjList[node]) {
        if (not visited[i]) {
            dfsRecursive(AdjList, i, visited);
        }
    }
}

void bfs(const vector<vector<int> > &AdjList, int source) {
    int NODE_COUNT = AdjList.size();
    vector<bool> visited(NODE_COUNT, false);
    vector<int> queue;
    queue.push_back(source);
    visited[source] = true;
    cout << "BFS traversal starting from node " << source << ": ";
    while (not queue.empty()) {
        int currentNode = queue.front();
        queue.erase(queue.begin());
        cout << currentNode << " ";
        for (int i: AdjList[currentNode]) {
            if (not visited[i]) {
                queue.push_back(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

bool checkExistanceOfPath(const vector<vector<int> > &AdjList, int source, int destination) {
    int NODE_COUNT = AdjList.size();
    vector<bool> visited(NODE_COUNT, false);
    return pathSearch(AdjList, source, destination, visited);
}

bool pathSearch(const vector<vector<int> > &AdjList, int source, int destination, vector<bool> &visited) {
    if (source == destination) return true;
    visited[source] = true;

    for (int i: AdjList[source]) {
        if (not visited[i]) {
            if (pathSearch(AdjList, i, destination, visited)) {
                return true;
            }
        }
    }
    return false;
}

enum GraphProblemsOptions {
    EXIT = 0, ///< Option to exit the graph problems
    CONVERT_ADJ_MATRIX_TO_ADJ_LIST = 1, ///< Option to convert an adjacency matrix to an adjacency list
    CONVERT_ADJ_MATRIX_TO_EDGE_LIST = 2, ///< Option to convert an adjacency matrix to an edge list
    CONVERT_NODE_LIST_TO_ADJ_MATRIX = 3, ///< Option to convert a node list to an adjacency matrix
    GRAPH_TRAVERSAL = 4, ///< Option to traverse a graph
    CHECK_PATH_EXISTENCE = 5 ///< Option to check the existence of a path between two nodes
};

void displayGraphsMenu() {
    cout << endl << "GRAPHS. APPLICATIONS " << endl;
    cout << "4.1. Graph representation: adjacency matrix <=> node lists" << endl;
    cout << "4.2. Graph representation: adjacency matrix <=> edge lists" << endl;
    cout << "4.3. Graph representation: node lists <=> edge lists" << endl;
    cout << "4.4. Graph traversal: depth-first, breadth-first." << endl;
    cout << "4.5. Check existence of a path between any two nodes" << endl;
    cout << "4.0. Exit Graphs." << endl;
}

void handleGraphs() {
    int choice = 0;
    do {
        displayGraphsMenu();

        choice = handleUserInput<int>("Graph Problem Option: ",
                                      [](int x) { return x >= 0 && x <= 5; },
                                      "Invalid input! Please enter a number between 0 and 5: ");
        cout << endl;
        switch (choice) {
            case CONVERT_ADJ_MATRIX_TO_ADJ_LIST: {
                int localChoice = handleUserInput<int>(
                    "1. Matrix -> Node List\n2. Node List -> Matrix\nEnter your choice: ",
                    [](int x) { return x >= 1 && x <= 2; },
                    "Invalid input! Please enter 1 or 2: ");

                // Get the number of nodes from the user
                int NODE_COUNT = handleUserInput<int>("Enter the number of nodes: ",
                                                      [](int x) { return x > 0; },
                                                      "Invalid input! Please enter a positive number: ");

                if (localChoice == 1) {
                    vector graph(NODE_COUNT, vector<int>(NODE_COUNT, 0));
                    // Get the adjacency matrix from the user
                    cout << "Enter the adjacency matrix:" << endl;
                    for (int i = 0; i < NODE_COUNT; i++) {
                        for (int j = 0; j < NODE_COUNT; j++) {
                            graph[i][j] = handleUserInput<int>("",
                                                               [](int x) { return x >= 0; },
                                                               "Invalid input! Please enter a positive number: ");
                        }
                    }
                    vector<vector<int> > adjList(NODE_COUNT);
                    adjList = adjacencyMatrixToAdjacencyList(graph);

                    cout << "Adjacency List:" << endl;
                    printAdjList(adjList);
                } else {
                    vector AdjList(NODE_COUNT, vector<int>());
                    // Get the adjacency list from the user
                    cout << "Enter the adjacency list:" << endl;
                    for (int i = 0; i < NODE_COUNT; i++) {
                        cout << "Enter the number of nodes adjacent to node " << i << ": ";
                        int count = handleUserInput<int>("",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        cout << "Enter the nodes adjacent to node " << i << ": ";
                        for (int j = 0; j < count; j++) {
                            int node = handleUserInput<int>("",
                                                            [](int x) { return x >= 0; },
                                                            "Invalid input! Please enter a positive number: ");
                            AdjList[i].push_back(node);
                        }
                    }
                    vector<vector<int> > graph(NODE_COUNT, vector<int>(NODE_COUNT, 0));
                    graph = nodeListToAdjacencyMatrix(AdjList);
                    cout << "Adjacency Matrix:" << endl;
                    printAdjMatrix(graph);
                }
            }
            break;

            case CONVERT_ADJ_MATRIX_TO_EDGE_LIST: {
                int localChoice = handleUserInput<int>(
                    "1. Matrix -> Edge List\n2. Edge List -> Matrix\nEnter your choice:",
                    [](int x) { return x >= 1 && x <= 2; },
                    "Invalid input! Please enter 1 or 2: ");
                // Get the number of nodes from the user
                int NODE_COUNT = handleUserInput<int>("Enter the number of nodes:",
                                                      [](int x) { return x > 0; },
                                                      "Invalid input! Please enter a positive number: ");

                if (localChoice == 1) {
                    vector graph(NODE_COUNT, vector<int>(NODE_COUNT, 0));
                    // Get the adjacency matrix from the user
                    cout << "Enter the adjacency matrix:" << endl;
                    for (int i = 0; i < NODE_COUNT; i++) {
                        for (int j = 0; j < NODE_COUNT; j++) {
                            graph[i][j] = handleUserInput<int>("",
                                                               [](int x) { return x >= 0; },
                                                               "Invalid input! Please enter a positive number: ");
                        }
                    }
                    vector<edge> edgeList = adjacencyMatrixToEdgeList(graph);
                    cout << "Edge List:" << endl;
                    printEdgeList(edgeList);
                } else {
                    int EDGE_COUNT = handleUserInput<int>("Enter the number of edges:",
                                                          [](int x) { return x > 0; },
                                                          "Invalid input! Please enter a positive number:");
                    vector<edge> edgeList;
                    // Get the edge list from the user
                    cout << "Enter the edge list:" << endl;
                    for (int i = 0; i < EDGE_COUNT; i++) {
                        cout << "Edge " << i + 1 << ":" << endl;
                        int node1 = handleUserInput<int>("\tFirst node:",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        int node2 = handleUserInput<int>("\tSecond node:",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        edge e = {node1, node2};
                        edgeList.push_back(e);
                    }
                    vector<vector<int> > graph(NODE_COUNT, vector<int>(NODE_COUNT, 0));
                    graph = edgeListToAdjacencyMatrix(edgeList, NODE_COUNT);
                    cout << "Adjacency Matrix:" << endl;
                    printAdjMatrix(graph);
                }
            }
            break;

            case CONVERT_NODE_LIST_TO_ADJ_MATRIX: {
                const int localChoice = handleUserInput<int>(
                    "1. Node List -> Edge List\n2. Edge List -> Node List\nEnter your choice:",
                    [](const int x) { return x >= 1 && x <= 2; },
                    "Invalid input! Please enter 1 or 2: ");
                if (localChoice == 1) {
                    // Get the number of nodes from the user
                    const int NODE_COUNT = handleUserInput<int>("Enter the number of nodes:",
                                                                [](const int x) { return x > 0; },
                                                                "Invalid input! Please enter a positive number: ");
                    // Get the adjacency list from the user
                    vector<vector<int> > AdjList(NODE_COUNT);
                    cout << "Enter the adjacency list:" << endl;
                    for (int i = 0; i < NODE_COUNT; i++) {
                        cout << "Enter the number of nodes adjacent to node " << i << ": ";
                        int count = handleUserInput<int>("",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        cout << "Enter the nodes adjacent to node " << i << ": ";
                        for (int j = 0; j < count; j++) {
                            int node = handleUserInput<int>("",
                                                            [](int x) { return x >= 0; },
                                                            "Invalid input! Please enter a positive number: ");
                            AdjList[i].push_back(node);
                        }
                    }
                    vector<edge> edgeList = nodeListToEdgeList(AdjList);
                    cout << "Edge List:" << endl;
                    printEdgeList(edgeList);
                } else {
                    // Get the number of edges from the user
                    const int EDGE_COUNT = handleUserInput<int>("Enter the number of edges:",
                                                                [](const int x) { return x > 0; },
                                                                "Invalid input! Please enter a positive number:");
                    // Get the edge list from the user
                    vector<edge> edgeList;
                    cout << "Enter the edge list:" << endl;
                    for (int i = 0; i < EDGE_COUNT; i++) {
                        cout << "Edge " << i + 1 << ":" << endl;
                        int node1 = handleUserInput<int>("\tFirst node:",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        int node2 = handleUserInput<int>("\tSecond node:",
                                                         [](int x) { return x >= 0; },
                                                         "Invalid input! Please enter a positive number: ");
                        edge e = {node1, node2};
                        edgeList.push_back(e);
                    }
                    vector<vector<int> > AdjList = edgeListToNodeList(edgeList);
                    cout << "Node List:" << endl;
                    printAdjList(AdjList);
                }
            }
            break;

            case GRAPH_TRAVERSAL: {
                // Get the number of nodes from the user
                const int NODE_COUNT = handleUserInput<int>("Enter the number of nodes:",
                                                            [](const int x) { return x > 0; },
                                                            "Invalid input! Please enter a positive number: ");

                // Get the adjacency matrix from the user
                vector graph(NODE_COUNT, vector(NODE_COUNT, 0));
                cout << "Enter the adjacency matrix:" << endl;
                for (int i = 0; i < NODE_COUNT; i++) {
                    for (int j = 0; j < NODE_COUNT; j++) {
                        graph[i][j] = handleUserInput<int>("",
                                                           [](int x) { return x >= 0; },
                                                           "Invalid input! Please enter a positive number: ");
                    }
                }

                const int localChoice = handleUserInput<int>(
                    "1. Depth-first traversal\n2. Breadth-first traversal\nEnter your choice:",
                    [](const int x) { return x >= 1 && x <= 2; },
                    "Invalid input! Please enter 1 or 2: ");

                if (localChoice == 1) {
                    int source = handleUserInput<int>("Enter the source node:",
                                                      [NODE_COUNT](const int x) { return x >= 0 && x < NODE_COUNT; },
                                                      "Invalid input! Please enter a number between 0 and " + to_string(
                                                          NODE_COUNT - 1) + ": ");
                    dfsMain(adjacencyMatrixToAdjacencyList(graph), source);
                } else {
                    int source = handleUserInput<int>("Enter the source node:",
                                                      [NODE_COUNT](const int x) { return x >= 0 && x < NODE_COUNT; },
                                                      "Invalid input! Please enter a number between 0 and " + to_string(
                                                          NODE_COUNT - 1) + ": ");
                    bfs(adjacencyMatrixToAdjacencyList(graph), source);
                }
            }
            break;

            case CHECK_PATH_EXISTENCE: {
                int localChoice = 0;

                do {
                    // Get the number of nodes from the user
                    const int NODE_COUNT = handleUserInput<int>("Enter the number of nodes:",
                                                                [](const int x) { return x > 0; },
                                                                "Invalid input! Please enter a positive number: ");
                    // Get the adjacency matrix from the user
                    vector graph(NODE_COUNT, vector(NODE_COUNT, 0));
                    cout << "Enter the adjacency matrix:" << endl;
                    for (int i = 0; i < NODE_COUNT; i++) {
                        for (int j = 0; j < NODE_COUNT; j++) {
                            graph[i][j] = handleUserInput<int>("",
                                                               [](int x) { return x >= 0; },
                                                               "Invalid input! Please enter a positive number: ");
                        }
                    }
                    // Get the source node from the user
                    int source = handleUserInput<int>("Enter the source node:",
                                                      [NODE_COUNT](const int x) { return x >= 0 && x < NODE_COUNT; },
                                                      "Invalid input! Please enter a number between 0 and " + to_string(
                                                          NODE_COUNT - 1) + ": ");
                    // Get the destination node from the user
                    int destination = handleUserInput<int>("Enter the destination node:",
                                                           [NODE_COUNT](const int x) {
                                                               return x >= 0 && x < NODE_COUNT;
                                                           },
                                                           "Invalid input! Please enter a number between 0 and " +
                                                           to_string(NODE_COUNT - 1) + ": ");
                    // Check the existence of a path between the source and destination nodes
                    if (checkExistanceOfPath(adjacencyMatrixToAdjacencyList(graph), source, destination)) {
                        cout << "There is a path between nodes " << source << " and " << destination << endl;
                    } else {
                        cout << "There is no path between nodes " << source << " and " << destination << endl;
                    }

                    localChoice = handleUserInput<int>(
                        "1. Check another path\n0. Back to main menu\nEnter your choice:",
                        [](int x) { return x >= 0 && x <= 1; },
                        "Invalid input! Please enter 0 or 1: ");
                } while (localChoice == 1);
            }
            break;
            case EXIT:
                cout << "Exiting Graph Problems!" << endl;
                break;

            default:
                cout << "Invalid option! Please enter a number from 0 to 2!" << endl;
                break;
        }
    } while (choice != EXIT);
}
