#pragma once
#include "interfaces/movable.hpp"
#include "models/game_objects/scene_object.hpp"
#include "models/hitboxes/box_hitbox.hpp"
#include "models/input/input_reader.hpp"

class Player: public SceneObject, public IMovable, public InputReader{
public:
  Player(std::string object_name, Transform transform, std::string sprite, std::string shader, BoxHitbox hitbox);
  void set_velocity(float new_velocity);
  void move(Input direction) override;
  void render() override;
private:
  float player_velocity = 100.f;

  void handle_user_input(std::vector<Input> user_input);
  void move_left();
  void move_right();
  void move_up();
  void move_down();
  void update_model_matrix_after_user_input();
};
