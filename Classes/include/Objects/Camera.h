#ifndef _CAMERA_
#define _CAMERA_

#include <memory>
#include "Core/Vec2.h"

class Node;

class Camera
{
private: 
	typedef std::shared_ptr<Node> NodePtr;
	struct Bounds
	{
		float xMin;
		float xMax;
		float yMin;
		float yMax;
	};

private:
	Vec2 m_position;
	Size m_cameraSize;
	NodePtr m_targetNode;
	Bounds m_cameraBounds;
	bool m_boundsEnabled;

private:
	void setPosition(const Vec2& _newPos);

public:
	Camera(const Size& _size);
	Camera(int _sizeX, int _sizeY);
	
	void setTargetNode(NodePtr _targetNode);
	NodePtr getTargetNode();
	
	const Vec2& getPosition();
	void updateCameraPosition();

	void setCameraBounds(float _xMin, float _xMax, float _yMin, float _yMax);
	void disableBounds();
};

#endif // !_CAMERA_
