#include "route_model.h"
#include <iostream>

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml) {
    // Create RouteModel nodes.
    int counter = 0;
    for (auto node : this->Nodes()) {
        m_Nodes.push_back(Node(counter, this, node));
        counter++;
    }

    CreateNodeToRoadHashmap();
}


void RouteModel::CreateNodeToRoadHashmap() {
    for (const Model::Road& road : Roads()) {
        if (road.type != Model::Road::Type::Footway) {
            for (int node_idx : Ways()[road.way].nodes) {
                if (node_to_road.find(node_idx) == node_to_road.end()) {
                    node_to_road[node_idx] = std::vector<const Model::Road*>{};
                }
                node_to_road[node_idx].push_back(&road);
            }
        }
    }
}

RouteModel::Node* RouteModel::Node::FindNeighbor(std::vector<int> node_indices) {
    Node* closest_node = nullptr;
    for (int node_idx : node_indices) {
        RouteModel::Node& node = parent_model->SNodes()[node_idx];
        if (this->distance(node) > 0 && !node.visited) {
            if (!closest_node)
                closest_node = &node;
            else

                if (this->distance(node) < this->distance(*closest_node)) 
                    closest_node = &node;
            
        }
    }
    return closest_node;
}

void RouteModel::Node::FindNeighbors() {
    for (auto& road : parent_model->node_to_road[this->index]) {
        RouteModel::Node* new_neighbor = this->FindNeighbor(parent_model->Ways()[road->way].nodes);
        if (new_neighbor) {
            this->neighbors.push_back(new_neighbor);
        }
    }
}

RouteModel::Node& RouteModel::FindClosestNode(float x, float y) {
    RouteModel::Node tmp_node ;
    tmp_node.x = x;
    tmp_node.y = y;
    float min_dist = std::numeric_limits<float>::max();
    float dist;
    int closest_idx;
    for (const Model::Road& road : Roads()) {
        if (road.type != Model::Road::Type::Footway) {
            for (int node_idx : Ways()[road.way].nodes) {
                dist = SNodes()[node_idx].distance(tmp_node);
                if (dist < min_dist) {
                    closest_idx = node_idx;

                    min_dist = dist;
                }
            }
        }
    }

    return this->SNodes()[closest_idx];

}



