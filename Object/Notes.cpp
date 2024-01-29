#include "Notes.h"
#include <Input.h>
#include <DxLib.h>
#include <assert.h>

/// <summary>
/// �ÓI�����o�ϐ��̎���
/// </summary>
int Notes::SoundEffect = 0;

void Notes::StaticInitialize() {
	// SE���擾
	SoundEffect = LoadSoundMem(L"Resources/SE.mp3");
}

void Notes::Initialize(const int& type, const int& StartTime) {
	// �^�C�v���擾
	this->type = type;
	// �X�^�[�g�^�C��������
	this->StartTime = StartTime;
	// �G���h�^�C��������
	EndTime = StartTime + 1000;
	// �X�^�[�g�t���O
	StartFlag = false;
	// �G���h�t���O
	EndFlag = false;
	// ���݂̃m�[�c
	nowNotes = false;
	hit = 0;
}

void Notes::Update() {
	if (!StartFlag) {
		if (StartTime <= GetNowCount()) {
			StartFlag = true;
			nowNotes = true;
			PlaySoundMem(SoundEffect, DX_PLAYTYPE_BACK);
		}
	}
	if (nowNotes) {
		CheckInput();
	}
	if (EndTime <= GetNowCount()) {
		EndFlag = true;
		nowNotes = false;
	}
}

void Notes::Draw() {
	if (type == 0)	DrawFormatString(0, 0, GetColor(0, 0, 0), L"��");
	else if (type == 1)	DrawFormatString(0, 0, GetColor(0, 0, 0), L"��");
}

inline void Notes::CheckInput() {
	// �C���X�^���X���擾
	Input* input = Input::GetInstance();
	// DOWN�L�[����
	if (input->GetKey(KEY_INPUT_DOWN) && !input->GetOldKey(KEY_INPUT_DOWN)) {
		if (type == 0) {
			hit = 1;
			return;
		}
		if (type == !0) {
			hit = -1;
		}
	}
	// END�L�[����
	if (input->GetKey(KEY_INPUT_LEFT) && !input->GetOldKey(KEY_INPUT_LEFT)) {
		if (type == 1) {
			hit = 1;
			return;
		}
		if (type == !1) {
			hit = -1;
		}
	}
}



