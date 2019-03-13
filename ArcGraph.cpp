#pragma once
#include"ArcGraph.h"

using std::vector;

ArcGraph::ArcGraph(int graph_size)
    : size(graph_size)
{}

ArcGraph::ArcGraph(const IGraph *other)
    : size(other->VerticesCount())
{
    for (int vertex = 0; vertex < size; ++vertex) {  // для каждой вершины
        std::vector<int> copy_vertices;
        other->GetNextVertices(vertex, copy_vertices);  // узнаем следующие от нее вершины
        for(const auto next_vertex : copy_vertices) {
            AddEdge(vertex, next_vertex);
        }
    }
}

int ArcGraph::VerticesCount() const  {
    return size;
}

void ArcGraph::AddEdge(int from, int to) {
    edges.emplace_back(from, to);
}

void ArcGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (const auto edge : edges) {
        if (edge.first == vertex) {
            vertices.push_back(edge.second);
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (const auto edge : edges) {
        if (edge.second == vertex) {
            vertices.push_back(edge.first);
        }
    }
}