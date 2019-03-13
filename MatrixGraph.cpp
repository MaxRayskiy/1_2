#pragma once
#include"MatrixGraph.h"

using std::vector;

MatrixGraph::MatrixGraph(int graph_size)
    : size(graph_size)
    , graph(static_cast<unsigned int>(graph_size))
{
    for (int i = 0; i < graph_size; ++i) {
        graph[i].resize(static_cast<unsigned int>(graph_size));
    }
}

MatrixGraph::MatrixGraph(const IGraph *other)
    : size(other->VerticesCount())
    , graph(static_cast<unsigned int>(other->VerticesCount()))
{
    for (int i = 0; i < size; ++i) {
        graph[i].resize((static_cast<unsigned int>(size)));
    }
    for (int vertex = 0; vertex < size; ++vertex) {  // для каждой вершины
        std::vector<int> copy_vertices;
        GetNextVertices(vertex, copy_vertices);  // узнаем следующие от нее вершины
        for(const auto next_vertex : copy_vertices) {
            AddEdge(vertex, next_vertex);
        }
    }
}

int MatrixGraph::VerticesCount() const  {
    return size;
}

void MatrixGraph::AddEdge(int from, int to) {
    graph[from][to] = 1;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (int next_vertex = 0; next_vertex < size; ++next_vertex) {
        if (graph[vertex][next_vertex] == 1) {
            vertices.push_back(next_vertex);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (int prev_vertex = 0; prev_vertex < size; ++prev_vertex) {
        if (graph[prev_vertex][vertex] == 1) {
            vertices.push_back(prev_vertex);
        }
    }
}