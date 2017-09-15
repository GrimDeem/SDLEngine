#include "Objects/Camera.h"
#include "Objects/Node.h"

Camera::Camera(Size size)
{
	cameraSize = size;
	boundsEnabled = false;
}

Camera::Camera(int sizeX, int sizeY)
	: position(0, 0)
{
	cameraSize = Size(sizeX, sizeY);
	boundsEnabled = false;
}

void Camera::setTargetNode(NodePtr targetNode)
{
	this->targetNode = targetNode;
}

Camera::NodePtr Camera::getTargetNode()
{
	return targetNode;
}

void Camera::setPosition(Vec2 newPos)
{
	position = newPos;
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
		if (boundsEnabled == true)
		{
			//Keep the camera in bounds.
			if (position.x < cameraBounds.xMin)
			{
				position.x = cameraBounds.xMin;
			}
			if (position.y < cameraBounds.yMin)
			{
				position.y = cameraBounds.yMin;
			}
			if (position.x > cameraBounds.xMax - cameraSize.width)
			{
				position.x = cameraBounds.xMax - cameraSize.width;
			}
			if (position.y > cameraBounds.yMax - cameraSize.height)
			{
				position.y = cameraBounds.yMax - cameraSize.height;
			}
		}
	}
}

void Camera::setCameraBounds(float _xMin, float _xMax, float _yMin, float _yMax)
{
	cameraBounds.xMin = _xMin;
	cameraBounds.xMax = _xMax;
	cameraBounds.yMin = _yMin;
	cameraBounds.yMax = _yMax;
	boundsEnabled = true;
}

void Camera::disableBounds()
{
	boundsEnabled = false;
}