#include "TitleScene.h"
#include "PlayScene.h"
#include <DxLib.h>

TitleScene::~TitleScene() {
}

void TitleScene::Initialize() {
	// �^�C�g���摜�擾
	titleGraph = LoadGraph(L"Resources/Title.png");
	// BGM�擾
	bgm = LoadSoundMem(L"Resources/BGM.mp3");
	// BGM�Đ�
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void TitleScene::Update() {	
	// �V�[���؂�ւ�
	if (input->GetKey(KEY_INPUT_SPACE)) {
		sceneManager->SetNextScene(new PlayScene());
	}
}

void TitleScene::Draw() {
	// �`��
	DrawGraph(0, 0, titleGraph, true);
}

void TitleScene::Finalize() {
	// �^�C�g���摜�폜
	DeleteGraph(titleGraph);
	// �^�C�g��BGM�폜
	DeleteSoundMem(bgm);
}
