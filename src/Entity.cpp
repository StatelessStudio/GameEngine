#include "Entity.h"
#include "Exception.h"

#include <sstream>
#include <iostream>

namespace SSGE
{

Entity::Entity() :
	id(0),
	hasId(false),
	scale(Vec3(1, 1, 1))
{
}

unsigned int Entity::getId()
{
	if (!hasId) {
		throw SSGE::Exception("ID has not been set for entity");
	}

	return id;
}

void Entity::setId(unsigned int _id)
{
	id = _id;
	hasId = true;
}

Vec3 Entity::getScale()
{
	return scale;
}

void Entity::setScale(Vec3 _scale)
{
	scale = _scale;
}


/**
 * Serialize an entity for transmission
 * 
 * @return std::string Returns the serialized string
 */
std::string Entity::serialize()
{	
	std::stringstream ss;
	ss << id << "," <<
		hasId << "," <<
		position.x << "," <<
		position.y << "," <<
		position.z << "," <<
		rotation.x << "," <<
		rotation.y << "," <<
		rotation.z << "," <<
		scale.x << "," <<
		scale.y << "," <<
		scale.z <<
	"\r\n";

	return ss.str();
}

/**
 * Unserialize a string into this Entity
 * 
 * @param std::string payload Serialized Entity
 * @return bool Returns true if unserialization succeeds
 */
bool Entity::unserialize(std::string payload)
{
	try {
		float* order[] = {
			&position.x,
			&position.y,
			&position.z,
			&rotation.x,
			&rotation.y,
			&rotation.z,
			&scale.x,
			&scale.y,
			&scale.z
		};

		int i = 0;
		size_t pos = 0;
		std::string token;

		while (payload.size()) {
			int delimSize = 0;

			if ((pos = payload.find(",")) != std::string::npos) {
				token = payload.substr(0, pos);
				delimSize = 1;
			}
			else {
				token = payload;
			}

			switch (i) {
				case 0:
					id = std::stoi(token, nullptr);
					break;

				case 1:
					hasId = (bool)std::stoi(token, nullptr);
					break;

				default:
					// TODO: Catch i overflow
					*order[i - 2] = std::stof(token, nullptr);
					break;
			}

			payload.erase(0, pos + delimSize);
			i++;
		}

		return true;
	}
	catch (std::exception ex) {
		return false;
	}
}

} // namespace SSGE
