#pragma once
#include"MatrixGraph.h"

using std::vector;

MatrixGraph::MatrixGraph(int graph_size)
    : size(graph_size)
    , adjacency_matrix(static_cast<unsigned int>(graph_size),
            vector<int>(static_cast<unsigned int>(graph_size)))
{}

MatrixGraph::MatrixGraph(const IGraph *other)
    : size(other->VerticesCount())
    , adjacency_matrix(static_cast<unsigned int>(other->VerticesCount()),
            vector<int>(static_cast<unsigned int>(other->VerticesCount())))
{
    for (int vertex = 0; vertex < size; ++vertex) {  // для каждой вершины
        std::vector<int> copy_vertices;
        other->GetNextVertices(vertex, copy_vertices);  // узнаем следующие от нее вершины
        for(const auto next_vertex : copy_vertices) {
            AddEdge(vertex, next_vertex);
        }
    }
}

int MatrixGraph::VerticesCount() const  {
    return size;
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacency_matrix[from][to] = 1;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (int next_vertex = 0; next_vertex < size; ++next_vertex) {
        if (adjacency_matrix[vertex][next_vertex] == 1) {
            vertices.push_back(next_vertex);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (int prev_vertex = 0; prev_vertex < size; ++prev_vertex) {
        if (adjacency_matrix[prev_vertex][vertex] == 1) {
            vertices.push_back(prev_vertex);
        }
    }
}