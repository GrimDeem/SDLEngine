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
	Vec2 position;
	Size cameraSize;
	NodePtr targetNode;
	Bounds cameraBounds;
	bool boundsEnabled;

private:
	void setPosition(Vec2 newPos);

public:
	Camera(Size size);
	Camera(int sizeX, int sizeY);
	
	void setTargetNode(NodePtr targetNode);
	NodePtr getTargetNode();
	
	Vec2 getPosition();
	void updateCameraPosition();

	void setCameraBounds(float _xMin, float _xMax, float _yMin, float _yMax);
	void disableBounds();
};

#endif // !_CAMERA_
