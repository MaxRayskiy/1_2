#pragma once
#include"SetGraph.h"

using std::vector;

SetGraph::SetGraph(int graph_size)
    : size(graph_size)
    , SetOfNextVertices(static_cast<unsigned int>(graph_size))
    , SetOfPrevVertices(static_cast<unsigned int>(graph_size))
{}

SetGraph::SetGraph(const IGraph *other)
    : size(other->VerticesCount())
    , SetOfNextVertices(static_cast<unsigned int>(other->VerticesCount()))
    , SetOfPrevVertices(static_cast<unsigned int>(other->VerticesCount()))
{
    for (int vertex = 0; vertex < size; ++vertex) {  // для каждой вершины
        std::vector<int> copy_vertices;
        GetNextVertices(vertex, copy_vertices);  // узнаем следующие от нее вершины
        for (const auto next_vertex : copy_vertices) {
            AddEdge(vertex, next_vertex);
        }
    }
}

int SetGraph::VerticesCount() const  {
    return size;
}

void SetGraph::AddEdge(int from, int to) {
    SetOfNextVertices[from].insert(to);
    SetOfPrevVertices[to].insert[from];
}

void SetGraph::GetNextVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (const auto next_vertex : SetOfNextVertices[vertex]){
        vertices.push_back(next_vertex);
    }
}

void SetGraph::GetPrevVertices(int vertex, std::vector<int>& vertices) const {
    vertices.clear();
    for (const auto prev_vertex : SetOfPrevVertices[vertex]){
        vertices.push_back(prev_vertex);
    }
}