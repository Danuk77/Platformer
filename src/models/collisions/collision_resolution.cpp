#include "collisions/collision_resolution.hpp"
#include "collisions/collision_report.hpp"
#include "glm/common.hpp"

void resolve_collision(SceneObject &player, CollisionReport &collision_report){
  MinimumOverlapDirection direction_of_minimum_overlap = find_direction_of_minimum_overlap(collision_report);
  std::cout << direction_of_minimum_overlap << std::endl;
  resolve_against_direction_of_minimum_overlap(collision_report, direction_of_minimum_overlap, player);
}

MinimumOverlapDirection find_direction_of_minimum_overlap(CollisionReport &report){
  float absolute_collision_depth_x = glm::abs(report.collision_depth_x);
  float absolute_collision_depth_y = glm::abs(report.collision_depth_y);

  if(absolute_collision_depth_x < absolute_collision_depth_y){
    return Horizontal;
  }else{
    // When both overlap depths are same, we give vertical the precedence
    return Vertial;
  }
}

void resolve_against_direction_of_minimum_overlap(CollisionReport report, MinimumOverlapDirection direction, SceneObject &player){
  if(direction == Vertial){
    player.transform.position.y += report.collision_depth_y;
  }else{
    player.transform.position.x += report.collision_depth_x;
  }
}
