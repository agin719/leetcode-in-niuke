C


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use#as a separator for each node, and,as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph{0,1,2# 1,2# 2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by#.

First node is labeled as0. Connect node0to both nodes1and2.
Second node is labeled as1. Connect node1to node2.
Third node is labeled as2. Connect node2to node2(itself), thus forming a self-cycle.

Visually, the graph looks like the following:

      1
     / \
    /   \
   0 --- 2
        / \
        \_/

      /**
       *Definition for undirected graph.
       *struct UndirectedGraphNode {
       *    int label;
       *    vector<UndirectedGraphNode *> neighbors;
       *    UndirectedGraphNode(int x) : label(x) {};
       *};
       */

class Solution {
  public:

    void travel(UndirectedGraphNode *node) {
      UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
      is_traval_.insert(node);
      for (auto &it : node->neightbors) {
        new_node->neighbors.push_back(it);
        if (is_traval_.find(node) != is_traval_.end()) {
          travel(it);
        }
      }
      node->neighbors.push_back(new_node);
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if (node == NULL) return NULL;
      travel(node);
      for (auto &it : is_traval_) {
        UndirectedGraphNode *new_node = it->neighbors.back();
        for (auto &neighbor : new_node->neighbors) {
          neighbor = neighbor->neighbors.back();
        }
      }
      return node->neighbors.back();
    }
    
  private:
    set<UndirectedGraphNode*> is_traval_;    
};
