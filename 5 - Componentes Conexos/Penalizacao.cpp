#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

/**
 * Professor: Wladmir Cardoso Brandão 
 * Nome: Homenique Vieira Martins
 *  
 * 
 * total do custo de todas as operações (0)(V*logv)
 * 
 *  */
class Graph
{
    int numVertices;
    vector<vector<int>> adjLists;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex, bool *visited, vector<int> *visitedVector);
    int countCompoments();
};

Graph::Graph(int vertices)
{
    numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        vector<int> vi;
        adjLists.push_back(vi);
    }
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
}

int Graph::countCompoments()
{
    int count = 0;
    bool *visited = new bool[numVertices];
     
 
    memset(visited, false, numVertices*sizeof(bool));

    for (int i = 0; i < numVertices; i++)
    {

        if (visited[i] == false)
        {
            vector<int> vi;
            DFS(i, visited, &vi);
            count++;

            sort(vi.begin(), vi.end());

            for (int w = 0; w < vi.size(); w++)
            {
                cout << char(vi.at(w) + 'a') << ",";
            }

            cout << endl;
        }
    }

    return count;
}

void Graph::DFS(int vertex, bool *visited, vector<int> *visitedVector)
{
    visited[vertex] = true;
    vector<int> adjList = adjLists[vertex];
    vector<int>::iterator i;
    visitedVector->push_back(vertex);

    for (i = adjList.begin(); i != adjList.end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i, visited, visitedVector);
        }
    }
}

int main(int argc, char const *argv[])
{
    // tamanho
    int N = 0;
    //vertex and Edges
    int vertex = 0, edges = 0;

    // Entrada para o numero de Teste
    cin >> N;

    for (int i = 0; N > i; i++)
    {

        cin >> vertex;
        cin >> edges;

        Graph *G = new Graph(vertex);

        for (int b = 0; b < edges; b++)
        {
            char vet1, vet2;

            cin >> vet1;

            cin >> vet2;

            G->addEdge(vet1 - 'a', vet2 - 'a');
            G->addEdge(vet2 - 'a', vet1 - 'a');
        }

        cout << "Case #" << i + 1 << ":" << endl;

        cout << G->countCompoments() << " connected components\n"
             << std::endl;
    }

    return 0;
}
