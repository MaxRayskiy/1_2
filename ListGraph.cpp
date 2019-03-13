#pragma once
#include"ListGraph.h"

using std::vector;

ListGraph::ListGraph(int graph_size)
    : size(graph_size)
    , ListOfNextVertices(static_cast<unsigned int>(graph_size))
    , ListOfPrevVertices(static_cast<unsigned int>(graph_size))
{}

ListGraph::ListGraph(const IGraph *other)
    : size(other->VerticesCount())
    , ListOfNextVertices(static_cast<unsigned int>(other->VerticesCount()))
    , ListOfPrevVertices(static_cast<unsigned int>(other->VerticesCount()))
{
    for (int vertex = 0; vertex < size; ++vertex) {  // для каждой вершины
        std::vector<int> copy_vertices;
        other->GetNextVertices(vertex, copy_vertices);  // узнаем следующие от нее вершины
        for (const auto next_vertex : copy_vertices) {
            AddEdge(vertex, next_vertex);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    ListOfNextVertices[from].push_back(to);
    ListOfPrevVertices[to].push_back(from);
}

int ListGraph::VerticesCount() const  {
    return size;
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    for (const auto next_vertex : ListOfNextVertices[vertex]) {
        vertices.push_back(next_vertex);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for (const auto next_vertex : ListOfPrevVertices[vertex]) {
        vertices.push_back(next_vertex);
    }
}

