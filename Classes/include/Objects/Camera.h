#ifndef _CAMERA_
#define _CAMERA_

#include "Core/Vec2.h"
#include <memory>
class Node;

class Camera
{
private: 
	typedef std::shared_ptr<Node> NodePtr;
	Vec2 position;
	Size cameraSize;
	NodePtr targetNode;
	
	void setPosition(Vec2 newPos);
public:
	Camera(Size size);
	Camera(int sizeX, int sizeY);
	
	void setTargetNode(NodePtr targetNode);
	NodePtr getTargetNode();
	
	Vec2 getPosition();

	void updateCameraPosition();
};

#endif // !_CAMERA_
