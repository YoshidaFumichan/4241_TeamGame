#include "Input.h"

#include <Dxlib.h>

Input* Input::GetInstance() {
	// インスタンスを宣言
	static Input instance;
	return &instance;
}

void Input::Update() {
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (short i = 0; i < 256; i++) {
		oldkeys[i] = keys[i];
	}
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}