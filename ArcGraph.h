#pragma once

#include"IGraph.h"

#include<vector>

class ArcGraph: public IGraph {
private:
    int size;
    std::vector<std::pair<int,int>> edges;  // начальная вершина + конечная вершина
public:
    ArcGraph(int graph_size);
    ArcGraph(const IGraph *other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    //~ArcGraph() = default;
};
