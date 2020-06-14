#include "Node.h"

namespace SSGE
{

Node::Node() :
	position(Vec3(0, 0, 0)),
	rotation(Vec3(0, 0, 0))
{
}

Vec3 Node::getPosition()
{
	return position;
}

void Node::setPosition(Vec3 _position)
{
	position = _position;
}

void Node::translate(Vec3 _translation)
{
	position += _translation;
}

Vec3 Node::getRotation()
{
	return rotation;
}

void Node::setRotation(Vec3 _rotation)
{
	rotation = _rotation;
}

void Node::rotate(Vec3 _rotation)
{
	rotation += _rotation;
}

} // namespace SSGE
