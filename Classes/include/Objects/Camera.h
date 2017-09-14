#ifndef _CAMERA_
#define _CAMERA_

#include "../Core/Vec2.h"
#include <memory>
class Node;

class Camera
{
private: 
	typedef std::shared_ptr<Node> NodePtr;
	Vec2 position;
	Size cameraSize;
	NodePtr target;
	
	
	Camera(int sizeX, int sizeY);
	Camera(Camera const&) = delete;		//forbid to copy and create new instances
	Camera& operator= (Camera const&) = delete;
	void setPosition(Vec2 newPos);
public:
	static Camera& getInstance()
	{
		static Camera cam(1366, 768);
		return cam;
	}

	void setTarget(NodePtr targetNode);
	NodePtr getTargetNode();
	
	Vec2 getPosition();

	void updateCameraPosition();
};

#endif // !_CAMERA_
