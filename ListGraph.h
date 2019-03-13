#pragma once

#include"IGraph.h"

#include<vector>

class ListGraph: public IGraph {
private:
    std::vector<std::vector<int>> ListOfNextVertices;
    std::vector<std::vector<int>> ListOfPrevVertices;
    int size;
public:
    ListGraph(int graph_size);
    ListGraph(const IGraph *other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    //~ListGraph() = default;
};
