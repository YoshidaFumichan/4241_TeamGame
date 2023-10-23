#include "SceneManager.h"
#include "BaseScene.h"

SceneManager* SceneManager::GetInstance()
{
	// インスタンスを宣言
	static SceneManager instance;
	return &instance;
}

void SceneManager::Initialize(BaseScene* scene)
{
	// シーンを設定
	this->scene = scene;
	// 初期化処理
	scene->Initialize();
}

// 更新処理
void SceneManager::Update() { scene->Update(); }

// 描画処理
void SceneManager::Draw() { scene->Draw(); }

void SceneManager::Finalize()
{
	//シーン終了処理
	scene->Finalize();
}

void SceneManager::ChangeScene()
{
	if (this->nextScene != nullptr) {
		// 終了処理
		scene->Finalize();
		// 次のシーンを設定
		scene = nextScene;
		// 初期化処理
		scene->Initialize();
		// nextSceneをnullptrにする
		nextScene = nullptr;
	}
}