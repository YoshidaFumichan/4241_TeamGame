#include "BaseScene.h"

/// <summary>
/// 静的メンバ変数の実態
/// </summary>
SceneManager* BaseScene::sceneManager = SceneManager::GetInstance();
GraphicLoader* BaseScene::graphicLoader = GraphicLoader::GetInstance();
Input* BaseScene::input = Input::GetInstance();