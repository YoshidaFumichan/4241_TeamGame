#include "Notes.h"
#include <Input.h>
#include <DxLib.h>
#include <assert.h>

/// <summary>
/// 静的メンバ変数の実態
/// </summary>
int Notes::SoundEffect = 0;
int Notes::notesHandle[] = {};

void Notes::StaticInitialize() {
	// SEを取得
	SoundEffect = LoadSoundMem(L"Resources/SE.mp3");
	notesHandle[0] = LoadGraph(L"Resources/left.png");
	notesHandle[1] = LoadGraph(L"Resources/down.png");

}

void Notes::Initialize(const int& type, const int& StartTime) {
	// タイプを取得
	this->type = type;
	// スタートタイム初期化
	this->StartTime = StartTime;
	// エンドタイム初期化
	EndTime = StartTime + 1000;
	// スタートフラグ
	StartFlag = false;
	// エンドフラグ
	EndFlag = false;
	// 現在のノーツ
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
	int size = 96;
	int posX = 640 - size / 2;
	int posY = 300 - size / 2;
	if (type == 0)	DrawExtendGraph(posX, posY, posX + size, posY + size, notesHandle[1], true);
	else if (type == 1)	DrawExtendGraph(posX, posY, posX + size, posY + size, notesHandle[0], true);
}

inline void Notes::CheckInput() {
	// インスタンスを取得
	Input* input = Input::GetInstance();
	// DOWNキー処理
	if (input->GetKey(KEY_INPUT_DOWN) && !input->GetOldKey(KEY_INPUT_DOWN)) {
		if (type == 0) {
			hit = 1;
			return;
		}
		if (type == !0) {
			hit = -1;
		}
	}
	// ENDキー処理
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



