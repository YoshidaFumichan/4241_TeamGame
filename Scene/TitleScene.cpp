#include "TitleScene.h"
#include "PlayScene.h"
#include <DxLib.h>

void TitleScene::Initialize() {
	// �^�C�g���摜�擾
	titleGraph = LoadGraph(L"Resources/Title.png");
	manualGraph = LoadGraph(L"Resources/Manual.png");
	// BGM�擾
	bgm = LoadSoundMem(L"Resources/BGM_Title.mp3");
	// ���ʒ���
#if DEBUG
	ChangeVolumeSoundMem(0, bgm);
#else
	ChangeVolumeSoundMem(50, bgm);
#endif // DEBUG
	// BGM�Đ�
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
}

void TitleScene::Update() {
	// �V�[���؂�ւ�
	if (input->GetKey(KEY_INPUT_SPACE) && !input->GetOldKey(KEY_INPUT_SPACE)) {
		if (change == 1) {
			sceneManager->SetNextScene(new PlayScene());
		}
		change = 1;
	}
}

void TitleScene::Draw() {
	// �`��
	if (change == 0) {
		DrawGraph(0, 0, titleGraph, true);
	}
	else if (change == 1) {
		DrawGraph(0, 0, manualGraph, true);
	}
}

void TitleScene::Finalize() {
	// �^�C�g���摜�폜
	DeleteGraph(titleGraph);
	DeleteGraph(manualGraph);
	// �^�C�g��BGM�폜
	DeleteSoundMem(bgm);
}
