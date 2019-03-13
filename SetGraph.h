#pragma once

#include"IGraph.h"

#include<vector>
#include<unordered_set>

class SetGraph: public IGraph {
private:
    int size;
    std::vector<std::unordered_set<int>> SetOfNextVertices;
    std::vector<std::unordered_set<int>> SetOfPrevVertices;

public:
    SetGraph(int graph_size);
    SetGraph(const IGraph *other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int>& vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int>& vertices) const override;

    //~SetGraph() = default;
};