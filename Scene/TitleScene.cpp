#include "TitleScene.h"
#include "PlayScene.h"
#include <DxLib.h>

void TitleScene::Initialize() {
	// タイトル画像取得
	titleGraph = LoadGraph(L"Resources/Title.png");
	manualGraph = LoadGraph(L"Resources/Manual.png");
	// BGM取得
	bgm = LoadSoundMem(L"Resources/BGM_Title.mp3");
	// 音量調整
#if DEBUG
	ChangeVolumeSoundMem(0, bgm);
#else
	ChangeVolumeSoundMem(50, bgm);
#endif // DEBUG
	// BGM再生
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void TitleScene::Update() {
	// シーン切り替え
	if (input->GetKey(KEY_INPUT_SPACE) && !input->GetOldKey(KEY_INPUT_SPACE)) {
		if (change == 1) {
			sceneManager->SetNextScene(new PlayScene());
		}
		change = 1;
	}
}

void TitleScene::Draw() {
	// 描画
	if (change == 0) {
		DrawGraph(0, 0, titleGraph, true);
	}
	else if (change == 1) {
		DrawGraph(0, 0, manualGraph, true);
	}
}

void TitleScene::Finalize() {
	// タイトル画像削除
	DeleteGraph(titleGraph);
	DeleteGraph(manualGraph);
	// タイトルBGM削除
	DeleteSoundMem(bgm);
}
