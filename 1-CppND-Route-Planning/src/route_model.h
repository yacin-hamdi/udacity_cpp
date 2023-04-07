#ifndef ROUTE_MODEL_H
#define ROUTE_MODEL_H

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
          float h_value{ std::numeric_limits<float>::max() };
          
          float g_value = 0.0;
          bool visited{ false };
          std::vector<Node*> neighbors;
          Node* parent = nullptr;

          void FindNeighbors();

          float distance(Node other) const {
              return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
          }
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}

      private:
        int index;
        Node* FindNeighbor(std::vector<int> node_indices);
        RouteModel * parent_model = nullptr;
    };

    RouteModel(const std::vector<std::byte> &xml);
    std::vector<Node> path;
    Node& FindClosestNode(float x, float y);
    auto& SNodes() { return m_Nodes; }
    auto& GetNodeToRoadMap() { return node_to_road; }
    
  private:
      std::vector<Node> m_Nodes;
      std::unordered_map<int, std::vector<const Model::Road*>> node_to_road;
      void CreateNodeToRoadHashmap();
      

};

#endif
