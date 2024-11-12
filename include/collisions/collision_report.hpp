#pragma once

class CollisionReport {
public:
  CollisionReport(bool is_colliding, float collision_depth_x,
                  float collision_depth_y)
      : is_colliding(is_colliding), collision_depth_x(collision_depth_x),
        collision_depth_y(collision_depth_y){};
  bool is_colliding;
  float collision_depth_x;
  float collision_depth_y;
};
