#include "glad/glad.h"
#include "models/game_objects/transform.hpp"
#include <models/game_objects/game_object.hpp>

GameObject::GameObject(std::string object_name, Transform transform)
    : object_name(object_name), transform(transform)
{
}
