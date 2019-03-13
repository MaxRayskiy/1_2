#pragma once

#include"IGraph.h"

#include<vector>

class MatrixGraph: public IGraph {
private:
    int size;
    std::vector<std::vector<int>> graph;

public:
    MatrixGraph(int graph_size);
    MatrixGraph(const IGraph *other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    ~MatrixGraph() = default;
};
