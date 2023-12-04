#include "EndScene.h"
#include "TitleScene.h"
#include <DxLib.h>

void EndScene::Initialize() {
	// �^�C�g���摜�擾
	endGraph = LoadGraph(L"Resources/End.png");
	// BGM�Đ�
	bgm = LoadSoundMem(L"Resources/BGM_Title.mp3");
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void EndScene::Update() {
	// �V�[���؂�ւ�
	if (input->GetKey(KEY_INPUT_SPACE) && !input->GetOldKey(KEY_INPUT_SPACE)) {
		sceneManager->SetNextScene(new TitleScene());
	}
}

void EndScene::Draw() {
	DrawGraph(0, 0, endGraph, true);
}

void EndScene::Finalize() {
	// �^�C�g���摜�폜
	DeleteGraph(endGraph);
	// �^�C�g��BGM�폜
	DeleteSoundMem(bgm);
}
