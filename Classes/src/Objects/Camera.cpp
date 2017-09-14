#include "../../include/Objects/Camera.h"
#include "../../include/Objects/Node.h"


void Camera::setTarget(NodePtr targetNode)
{
	this->target = targetNode;
}

Camera::NodePtr Camera::getTargetNode()
{
	return target;
}

Vec2 Camera::getPosition()
{
	return position;
}

void Camera::updateCameraPosition()
{
	if (target != nullptr) {
		setPosition(target->getPosition());

		//Center the camera over the target
		this->position.x = target->getPosition().x - cameraSize.width / 2;
		this->position.y = target->getPosition().y - cameraSize.height / 2;

		//Create camera bounds here
	}
}

Camera::Camera(int sizeX, int sizeY)
	: position(0, 0)
{	
	cameraSize = Size( sizeX, sizeY);
}

void Camera::setPosition(Vec2 newPos)
{
	position = newPos;
}