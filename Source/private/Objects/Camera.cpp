#include <Objects/Camera.h>
#include <Objects/Node.h>

Camera::Camera(const Size& _size) {
	m_cameraSize = _size;
	m_boundsEnabled = false;
}

Camera::Camera(int _sizeX, int _sizeY)
	: m_position(0, 0) 
{
	m_cameraSize = Size(_sizeX, _sizeY);
	m_boundsEnabled = false;
}

void Camera::setTargetNode(NodePtr _targetNode) {
	this->m_targetNode = _targetNode;
}

Camera::NodePtr Camera::getTargetNode() {
	return m_targetNode;
}

void Camera::setPosition(const Vec2& _newPos) {
	m_position = _newPos;
}

const Vec2& Camera::getPosition() {
	return m_position;
}

void Camera::updateCameraPosition() {
	if (m_targetNode != nullptr) {
		//Center the camera over the target
		setPosition(Vec2(m_targetNode->getPosition().x - m_cameraSize.width / 2,
						 m_targetNode->getPosition().y - m_cameraSize.height / 2));
		//Create camera bounds here
		if (m_boundsEnabled) {
			//Keep the camera in bounds.
			if (m_position.x < m_cameraBounds.xMin)	{
				m_position.x = m_cameraBounds.xMin;
			}
			if (m_position.y < m_cameraBounds.yMin)	{
				m_position.y = m_cameraBounds.yMin;
			}
			if (m_position.x > m_cameraBounds.xMax - m_cameraSize.width) {
				m_position.x = m_cameraBounds.xMax - m_cameraSize.width;
			}
			if (m_position.y > m_cameraBounds.yMax - m_cameraSize.height) {
				m_position.y = m_cameraBounds.yMax - m_cameraSize.height;
			}
		}
	}
}

void Camera::setCameraBounds(float _xMin, float _xMax, float _yMin, float _yMax) {
	m_cameraBounds.xMin = _xMin;
	m_cameraBounds.xMax = _xMax;
	m_cameraBounds.yMin = _yMin;
	m_cameraBounds.yMax = _yMax;
	m_boundsEnabled = true;
}

void Camera::disableBounds() {
	m_boundsEnabled = false;
}