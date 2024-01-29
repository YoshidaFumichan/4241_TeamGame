#include "Notes.h"
#include <Input.h>
#include <DxLib.h>
#include <assert.h>

/// <summary>
/// 静的メンバ変数の実態
/// </summary>
int Notes::SoundEffect = 0;

void Notes::StaticInitialize() {
	// SEを取得
	SoundEffect = LoadSoundMem(L"Resources/SE.mp3");
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
	if (type == 0)	DrawFormatString(0, 0, GetColor(0, 0, 0), L"下");
	else if (type == 1)	DrawFormatString(0, 0, GetColor(0, 0, 0), L"左");
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



