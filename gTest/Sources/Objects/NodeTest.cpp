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

	if (parentNode == std::make_shared<Node>(*childNode->getParent()))
		return;
/*	ASSERT_EQ(parentNode, std::make_shared<Node::NodePtr>(childNode->getParent())) 
		<< "childNode doest not contain link to parent node";
/*
	ASSERT_EQ(parentNode->getChildByKey("first child"), childNode) 
		<< "cannot find link to child";*/
}

TEST(Node_test, removeChildTest)
{
	auto parentNode = Node::create();
	auto childNode = Node::create();
	parentNode->addChild(childNode, 0, "first child");
	parentNode->removeChild(childNode);

	/*ASSERT_NE(parentNode, childNode->getParent())
		<< "child node still contain link to old parent node";

	ASSERT_NE(parentNode->getChildByKey("first child"), childNode)
		<< "parent node still contain link to child node";*/
}

#endif // !_NODE_TEST_
