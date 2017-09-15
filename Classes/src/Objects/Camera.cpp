#include "Objects/Camera.h"
#include "Objects/Node.h"

Camera::Camera(Size size)
{
	cameraSize = size;
}

Camera::Camera(int sizeX, int sizeY)
	: position(0, 0)
{
	cameraSize = Size(sizeX, sizeY);
}

void Camera::setTargetNode(NodePtr targetNode)
{
	this->targetNode = targetNode;
}

Camera::NodePtr Camera::getTargetNode()
{
	return targetNode;
}

Vec2 Camera::getPosition()
{
	return position;
}

void Camera::updateCameraPosition()
{
	if (targetNode != nullptr) {
		//Center the camera over the target
		setPosition(Vec2(targetNode->getPosition().x - cameraSize.width / 2,
						 targetNode->getPosition().y - cameraSize.height / 2));
		//Create camera bounds here
	}
}

void Camera::setPosition(Vec2 newPos)
{
	position = newPos;
}