#include "Managers/SceneManager.h"
#include "gtest/gtest.h"

TEST(SMGRTest, addScene)
{
	SceneManager smgr;
	auto scene = std::make_shared<Scene>();

	smgr.addSceneToPool("scene", scene);
	ASSERT_EQ(smgr.getScenePool().size(), 1)
		<< "Scene not added to the pool";
}

TEST(SMGRTest, getSceneFromPool)
{
	SceneManager smgr;
	auto scene = std::make_shared<Scene>();

	smgr.addSceneToPool("scene", scene);

	ASSERT_EQ(smgr.getSceneFromPool("scene"), scene)
		<< "Scene not added to the pool";
}

TEST(SMGRTest, removeSceneFromPoolByTag)
{
	SceneManager smgr;
	auto scene = std::make_shared<Scene>();

	smgr.addSceneToPool("scene", scene);
	smgr.removeSceneFromPool("scene");
	ASSERT_EQ(smgr.getScenePool().size(), 0)
		<< "Scene not added to the pool";
}

TEST(SMGRTest, removeSceneFromPoolByPtr)
{
	SceneManager smgr;
	auto scene = std::make_shared<Scene>();

	smgr.addSceneToPool("scene", scene);
	smgr.removeSceneFromPool(scene);
	ASSERT_EQ(smgr.getScenePool().size(), 0)
		<< "Scene not added to the pool";
}