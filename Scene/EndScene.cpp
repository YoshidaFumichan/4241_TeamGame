#include "EndScene.h"
#include "TitleScene.h"
#include <DxLib.h>

void EndScene::Initialize() {
	// タイトル画像取得
	endGraph = LoadGraph(L"Resources/End.png");
	// BGM再生
	bgm = LoadSoundMem(L"Resources/BGM_Title.mp3");
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void EndScene::Update() {
	// シーン切り替え
	if (input->GetKey(KEY_INPUT_SPACE) && !input->GetOldKey(KEY_INPUT_SPACE)) {
		sceneManager->SetNextScene(new TitleScene());
	}
}

void EndScene::Draw() {
	DrawGraph(0, 0, endGraph, true);
}

void EndScene::Finalize() {
	// タイトル画像削除
	DeleteGraph(endGraph);
	// タイトルBGM削除
	DeleteSoundMem(bgm);
}
