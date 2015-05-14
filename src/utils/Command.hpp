/*
 * Command.hpp
 *
 *  Created on: 13 maj 2015
 *      Author: slawek
 */

#ifndef UTILS_COMMAND_HPP_
#define UTILS_COMMAND_HPP_
#include <functional>
#include <SFML/System.hpp>

#include "entities/SceneNode.hpp"

namespace sfml_playground
{

// Forward declaration of SceneNode
class SceneNode;

class Command
{
public:
	Command()			= default;
	virtual ~Command()	= default;

	std::function<void(SceneNode&, sf::Time)> action;
};

} /* namespace sfml_playground */

#endif /* UTILS_COMMAND_HPP_ */