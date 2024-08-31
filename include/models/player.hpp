#include "models/game_object.hpp"
#include "models/input.hpp"

class Player:GameObject{
public:
  Player(std::string object_name, glm::vec2 position, glm::vec2 size, float rotation, std::string sprite, std::string shader);

  void handle_input(Input user_input);
  void set_velocity(float new_velocity);
private:
  const float player_velocity = 100.0f;
};
