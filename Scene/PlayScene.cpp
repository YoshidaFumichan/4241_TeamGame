#include "PlayScene.h"
#include <Dxlib.h>

PlayScene::~PlayScene() {
}

void PlayScene::Initialize() {

}

void PlayScene::Update() {

}

void PlayScene::Draw() {

	DrawString(1280 / 2, 720 / 2, L"PLAY", GetColor(0, 0, 0), true);
}

void PlayScene::Finalize() {

}
