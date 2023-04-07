#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    float GetDistance() const { return distance; }
    void AStarSearch();
   

  private:
      RouteModel::Node* start_node;
      RouteModel::Node* end_node;
      std::vector<RouteModel::Node*> open_list{};
      float CalculateHValue(RouteModel::Node*);
      float distance;
      std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node* current_node); 
      RouteModel::Node* NextNode();
      void AddNeighbors(RouteModel::Node*);
    RouteModel &m_Model;

};

#endif