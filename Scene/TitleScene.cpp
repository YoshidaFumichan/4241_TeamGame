#include "TitleScene.h"
#include "PlayScene.h"
#include <DxLib.h>

TitleScene::~TitleScene() {
}

void TitleScene::Initialize() {
	// タイトル画像取得
	titleGraph = LoadGraph(L"Resources/Title.png");
	// BGM取得
	bgm = LoadSoundMem(L"Resources/BGM.mp3");
	// BGM再生
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void TitleScene::Update() {	
	// シーン切り替え
	if (input->GetKey(KEY_INPUT_SPACE)) {
		sceneManager->SetNextScene(new PlayScene());
	}
}

void TitleScene::Draw() {
	// 描画
	DrawGraph(0, 0, titleGraph, true);
}

void TitleScene::Finalize() {
	// タイトル画像削除
	DeleteGraph(titleGraph);
	// タイトルBGM削除
	DeleteSoundMem(bgm);
}
