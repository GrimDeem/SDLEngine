#ifndef _NODE_TEST_
#define _NODE_TEST_

#include "gtest/gtest.h"
#include "Objects/Node.h"

TEST(Node_test, createTest)
{
	auto node = Node::create();
	ASSERT_NE(node, nullptr) << "node not created";
}

TEST(Node_test, addChildTest)
{
	auto parentNode = Node::create();
	auto childNode = Node::create();
	parentNode->addChild(childNode, 0, "first child");

	ASSERT_EQ(parentNode, childNode->getParent()) 
		<< "childNode doest not contain link to parent node";

	ASSERT_EQ(parentNode->getChildByKey("first child"), childNode) 
		<< "cannot find link to child";
}

TEST(Node_test, removeChildTest)
{
	auto parentNode = Node::create();
	auto childNode = Node::create();
	parentNode->addChild(childNode, 0, "first child");
	parentNode->removeChild(childNode);

	ASSERT_NE(parentNode, childNode->getParent())
		<< "child node still contain link to old parent node";

	ASSERT_NE(parentNode->getChildByKey("first child"), childNode)
		<< "parent node still contain link to child node";
}

TEST(Node_test, removeChildren)
{
	auto parentNode = Node::create();
	auto child1 = Node::create();
	auto child2 = Node::create();

	parentNode->addChild(child1);
	parentNode->addChild(child2);

	ASSERT_NE(parentNode->getDrawableChildren().size(), 0)
		<< "children doesnt added";

	parentNode->removeChildren();

	ASSERT_EQ(parentNode->getDrawableChildren().size(), 0)
		<< "children doesnt removed";
}

TEST(Node_test, removeFromParent)
{
	auto parentNode = Node::create();
	auto child = Node::create();

	parentNode->addChild(child, 0, "child");
	child->removeFromParent();

	ASSERT_NE(parentNode, child->getParent())
		<< "children still contain link to parent node";

	ASSERT_NE(parentNode->getChildByKey("child"), child)
		<< "parent node still contain link to child";
}

TEST(Node_test, recursiveMethodsTest)
{
	auto parentNode = Node::create();
	auto child = Node::create();

	parentNode->addChild(child, 0, "child");

	ASSERT_EQ(parentNode->getPosition(), child->getPosition())
		<< "starting positions does not equal";

	parentNode->moveRecursive(3, 3);

	ASSERT_EQ(parentNode->getPosition(), child->getPosition())
		<< "recursive move error";

	parentNode->setScaleRecursive(3);

	ASSERT_EQ(parentNode->getScale(), child->getScale())
		<< "recursive scale error";

}
#endif // !_NODE_TEST_
