#include "BaseScene.h"

/// <summary>
/// �ÓI�����o�ϐ��̎���
/// </summary>
SceneManager* BaseScene::sceneManager = SceneManager::GetInstance();
GraphicLoader* BaseScene::graphicLoader = GraphicLoader::GetInstance();
Input* BaseScene::input = Input::GetInstance();