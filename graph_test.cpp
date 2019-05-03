#include "graph.cpp"
#include <algorithm>

#include <gtest/gtest.h>

class TestListGraph : public testing::Test {
 protected:
  ListGraph* graph;
  void SetUp() {
    graph = new ListGraph(5);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 3);
    graph->AddEdge(1, 2);
  }
  void TearDown() { delete graph; }
};

TEST_F(TestListGraph, Test1) {
  vector<int> first_next;
  graph->GetNextVertices(1, first_next);
  vector<int> second_next;
  graph->GetNextVertices(2, second_next);
  std::sort(first_next.begin(), first_next.end());
  std::sort(second_next.begin(), second_next.end());
  ASSERT_NE(first_next, second_next);
}

TEST_F(TestListGraph, Test2) {
  vector<int> zero_prev;
  graph->GetPrevVertices(0, zero_prev);
  ASSERT_EQ(zero_prev, vector<int>());
}

TEST_F(TestListGraph, Test3) {
  SetGraph graph2(5);
  graph2.AddEdge(0, 1);
  graph2.AddEdge(0, 2);
  graph2.AddEdge(3, 4);
  graph2.AddEdge(4, 3);
  graph2.AddEdge(1, 2);
  ListGraph graph_new(&graph2);
  vector<int> temp[2];
  for (int i = 0; i < 5; i++) {
    temp[0].clear();
    temp[1].clear();
    graph->GetNextVertices(i, temp[0]);
    graph_new.GetNextVertices(i, temp[1]);
    std::sort(temp[0].begin(), temp[0].end());
    std::sort(temp[1].begin(), temp[1].end());

    ASSERT_EQ(temp[0], temp[1]);
  }
}
class TestSetGraph : public testing::Test {
 protected:
  SetGraph* graph;
  void SetUp() {
    graph = new SetGraph(5);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 3);
    graph->AddEdge(1, 2);
  }
  void TearDown() { delete graph; }
};

TEST_F(TestSetGraph, Test1) {
  vector<int> first_next;
  graph->GetNextVertices(1, first_next);
  vector<int> second_next;
  graph->GetNextVertices(2, second_next);
  std::sort(first_next.begin(), first_next.end());
  std::sort(second_next.begin(), second_next.end());
  ASSERT_NE(first_next, second_next);
}

TEST_F(TestSetGraph, Test2) {
  vector<int> zero_prev;
  graph->GetPrevVertices(0, zero_prev);
  ASSERT_EQ(zero_prev, vector<int>());
}

TEST_F(TestSetGraph, Test3) {
  ListGraph graph2(5);
  graph2.AddEdge(0, 1);
  graph2.AddEdge(0, 2);
  graph2.AddEdge(3, 4);
  graph2.AddEdge(4, 3);
  graph2.AddEdge(1, 2);
  SetGraph graph_new(&graph2);
  vector<int> temp[2];
  for (int i = 0; i < 5; i++) {
    temp[0].clear();
    temp[1].clear();
    graph->GetNextVertices(i, temp[0]);
    graph_new.GetNextVertices(i, temp[1]);
    std::sort(temp[0].begin(), temp[0].end());
    std::sort(temp[1].begin(), temp[1].end());
    ASSERT_EQ(temp[0], temp[1]);
  }
}
class TestMatrixGraph : public testing::Test {
 protected:
  MatrixGraph* graph;
  void SetUp() {
    graph = new MatrixGraph(5);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 3);
    graph->AddEdge(1, 2);
  }
  void TearDown() { delete graph; }
};

TEST_F(TestMatrixGraph, Test1) {
  vector<int> first_next;
  graph->GetNextVertices(1, first_next);
  vector<int> second_next;
  graph->GetNextVertices(2, second_next);
  std::sort(first_next.begin(), first_next.end());
  std::sort(second_next.begin(), second_next.end());
  ASSERT_NE(first_next, second_next);
}

TEST_F(TestMatrixGraph, Test2) {
  vector<int> zero_prev;
  graph->GetPrevVertices(0, zero_prev);
  ASSERT_EQ(zero_prev, vector<int>());
}

TEST_F(TestMatrixGraph, Test3) {
  ArcGraph graph2(5);
  graph2.AddEdge(0, 1);
  graph2.AddEdge(0, 2);
  graph2.AddEdge(3, 4);
  graph2.AddEdge(4, 3);
  graph2.AddEdge(1, 2);
  MatrixGraph graph_new(&graph2);
  vector<int> temp[2];
  for (int i = 0; i < 5; i++) {
    temp[0].clear();
    temp[1].clear();
    graph->GetNextVertices(i, temp[0]);
    graph_new.GetNextVertices(i, temp[1]);
    std::sort(temp[0].begin(), temp[0].end());
    std::sort(temp[1].begin(), temp[1].end());
    ASSERT_EQ(temp[0], temp[1]);
  }
}
class TestArcGraph : public testing::Test {
 protected:
  ArcGraph* graph;
  void SetUp() {
    graph = new ArcGraph(5);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(3, 4);
    graph->AddEdge(4, 3);
    graph->AddEdge(1, 2);
  }
  void TearDown() { delete graph; }
};

TEST_F(TestArcGraph, Test1) {
  vector<int> first_next;
  graph->GetNextVertices(1, first_next);
  vector<int> second_next;
  graph->GetNextVertices(2, second_next);
  std::sort(first_next.begin(), first_next.end());
  std::sort(second_next.begin(), second_next.end());
  ASSERT_NE(first_next, second_next);
}

TEST_F(TestArcGraph, Test2) {
  vector<int> zero_prev;
  graph->GetPrevVertices(0, zero_prev);
  ASSERT_EQ(zero_prev, vector<int>());
}

TEST_F(TestArcGraph, Test3) {
  MatrixGraph graph2(5);
  graph2.AddEdge(0, 1);
  graph2.AddEdge(0, 2);
  graph2.AddEdge(3, 4);
  graph2.AddEdge(4, 3);
  graph2.AddEdge(1, 2);
  ArcGraph graph_new(&graph2);
  vector<int> temp[2];
  for (int i = 0; i < 5; i++) {
    temp[0].clear();
    temp[1].clear();
    graph->GetNextVertices(i, temp[0]);
    graph_new.GetNextVertices(i, temp[1]);
    std::sort(temp[0].begin(), temp[0].end());
    std::sort(temp[1].begin(), temp[1].end());
    ASSERT_EQ(temp[0], temp[1]);
  }
}
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
