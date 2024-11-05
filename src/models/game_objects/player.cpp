#include "models/game_objects/player.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "models/clock.hpp"
#include "models/game_objects/drawable_object.hpp"
#include "models/hitboxes/box_hitbox.hpp"
#include "models/input/input_reader.hpp"

Player::Player(std::string object_name, Transform transform, std::string sprite,
               std::string shader, BoxHitbox player_hitbox)
    : SceneObject(object_name, transform, sprite, shader, player_hitbox), InputReader() {}

void Player::set_velocity(float new_velocity){
  player_velocity = new_velocity;  
}

void Player::render(){
  std::vector<Input> current_frame_input = InputReader::read_user_input();
  handle_user_input(current_frame_input);
  DrawableObject::render();
}

void Player::handle_user_input(std::vector<Input> user_input){
  std::vector<Input>::iterator user_input_iterator;

  for (user_input_iterator = user_input.begin(); user_input_iterator != user_input.end(); user_input_iterator++){
    move(*user_input_iterator);
  }
}

void Player::move(Input direction){
  switch (direction) {
    case LEFT:
      move_left();
      break;
    case RIGHT:
      move_right();
      break;
    case UP:
      move_up();
      break;
    case DOWN:
      move_down();
      break;
  }

  update_model_matrix_after_user_input();
}

void Player::move_left(){
  transform.position.x -= (player_velocity * Clock::get_time_since_last_frame());
}

void Player::move_right(){
  transform.position.x += (player_velocity * Clock::get_time_since_last_frame());
}

void Player::move_up(){
  transform.position.y -= (player_velocity * Clock::get_time_since_last_frame());
}
  
void Player::move_down(){
  transform.position.y += (player_velocity * Clock::get_time_since_last_frame());
}

void Player::update_model_matrix_after_user_input(){
  // TODO: might be a better way to do this
  initialise_model_matrix();
  //model_matrix = glm::translate(model_matrix, glm::vec3(transform.position, 0.0f));
}
