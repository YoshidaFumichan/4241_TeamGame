#include "PlayScene.h"
#include "EndScene.h"
#include <DxLib.h>
#include <DxLib_FrameWork.h>
#include <assert.h>

void PlayScene::Initialize() {
	// 背景画像取得
	BackGraph = LoadGraph(L"Resources/BackGraph.png");
	// BGM取得
	bgm = LoadSoundMem(L"Resources/BGM_Play.mp3");
	// 音量を変更
#if DEBUG
	ChangeVolumeSoundMem(0, bgm);
#else
	ChangeVolumeSoundMem(50, bgm);
#endif // DEBUG
	// BGM再生
	PlaySoundMem(bgm, DX_PLAYTYPE_BACK);
	// カウントダウン用連番画像取得
	LoadDivGraph(L"Resources/Countdown.png", 3, 3, 1,
		DxLib_Framework::GetWIN_WIDTH(), DxLib_Framework::GetWIN_HEIGHT(), CountDownGraph);
	// カウントダウン用現在の時間取得
	StartTime = GetNowCount();
	// カウントダウン初期化
	CountDown = 0;
	// スタートフラグの初期化
	StartFlag = false;
	// エンドフラグの初期化
	EndFlag = false;
	// 湯切りおじさんアニメーション初期化
	CutOjiAnimation = 0;
	// 湯切りおじさん画像取得
	CutOjiGraph[0] = LoadGraph(L"Resources/Cut1.png");
	CutOjiGraph[1] = LoadGraph(L"Resources/Cut2.png");
	CutOjiGraph[2] = LoadGraph(L"Resources/Cut3.png");
	// ラーメンアニメーション
	RamenAnimation = 0;
	// ラーメン画像取得
	RamenGraph[0] = LoadGraph(L"Resources/noramen.png");
	RamenGraph[1] = LoadGraph(L"Resources/ramen.png");
	// ノーツの静的初期化処理
	Notes::StaticInitialize();
	// ノーツの初期化
	for (short i = 0; i < 5; i++) {
		notes[i] = new Notes();
	}
	goodGraph = LoadGraph(L"Resources/good.png");
	missGraph = LoadGraph(L"Resources/miss.png");
}

void PlayScene::Update() {
	oldNotes = nowNotes;
	// 開始時カウントダウン
	StartCountDown();

	// スタートフラグが立っていたら
	if (StartFlag) {
		// ノーツの更新処理
		for (int i = 0; i < 5; i++) {
			notes[i]->Update();

			// 現在のノーツ
			if (notes[i]->nowNotes) {
				this->nowNotes = i;
				// 下キーの処理
				if (notes[i]->type == 0) {
					scoreFlag = false;
					if (notes[i]->hit == 0) {
						CutOjiAnimation = 0;
					}
					else if (notes[i]->hit == 1) {
						// 湯切りをしたら上にあげる
						CutOjiAnimation = 1;
					}
					// 麵なし
					RamenAnimation = 0;
				}

				// 左キーの処理
				if (notes[i]->type == 1) {
					if (notes[i]->hit == 0) {
						// 左を押したら麺が出現
						CutOjiAnimation = 0;
					}
					if (notes[i]->hit == 1) {
						// 麵なしおじさん
						CutOjiAnimation = 2;
						// 麺ありラーメン
						RamenAnimation = 1;
						if (scoreFlag == false) {
							// スコア加算
							score++;
							scoreFlag = true;
						}
					}
				}
			}
		}

		if (nowNotes != oldNotes) {
			damageFlag = false;
		}
		if (notes[nowNotes]->hit == -1) {
			if (damageFlag == false) {
				if (life != 0) {
					life -= 1;
				}
				else {
					sceneManager->SetNextScene(new EndScene());
				}
				damageFlag = true;
			}
		}
		if (notes[4]->EndFlag) {
			// ノーツの生成処理
			CreateNotes();
		}
	}
}

void PlayScene::Draw() {
	// 背景画像描画
	DrawGraph(0, 0, BackGraph, true);
	// 湯切りおじさん画像描画
	DrawGraph(0, 0, CutOjiGraph[CutOjiAnimation], true);
	// ラーメン画像描画
	DrawGraph(DxLib_Framework::GetWIN_WIDTH() / 2 - 62, 450, RamenGraph[RamenAnimation], true);

	if (StartFlag) notes[nowNotes]->Draw();

	if (notes[nowNotes]->hit == 1) {
		DrawGraph(DxLib_Framework::GetWIN_WIDTH() / 2 - 32,
			DxLib_Framework::GetWIN_HEIGHT() / 2 - 32, goodGraph, true);
	}
	if (notes[nowNotes]->hit == -1) {
		DrawGraph(DxLib_Framework::GetWIN_WIDTH() / 2 - 32,
			DxLib_Framework::GetWIN_HEIGHT() / 2 - 32, missGraph, true);
	}

	// カントダウン画像描画
	if (!StartFlag) {
		DrawGraph(0, 0, CountDownGraph[CountDown], true);
	}
	DrawFormatString(0, 100, GetColor(0, 0, 0), L"life = %d", life + 1);
	DrawFormatString(0, 200, GetColor(0, 0, 0), L"score = %d", score);
}

void PlayScene::Finalize() {

}

void PlayScene::StartCountDown() {
	// カウントダウン処理
	if (!StartFlag) {
		if (StartTime + 1000 <= GetNowCount()) {
			CountDown += 1;
			StartTime = GetNowCount();
			if (CountDown == 4) {
				StartFlag = true;
				// ノーツの生成処理
				CreateNotes();
			}
		}
	}
}

void PlayScene::CreateNotes() {

	notes[0]->Initialize(0, GetNowCount());
	notes[1]->Initialize(1, GetNowCount() + 1000);
	notes[2]->Initialize(0, GetNowCount() + 2000);
	notes[3]->Initialize(1, GetNowCount() + 3000);
	notes[4]->Initialize(0, GetNowCount() + 4000);

	//notes[0]->Initialize(0, GetNowCount());
	//notes[1]->Initialize(0, GetNowCount() + 1000);
	//notes[2]->Initialize(0, GetNowCount() + 2000);
	//notes[3]->Initialize(0, GetNowCount() + 3000);
	//notes[4]->Initialize(1, GetNowCount() + 4000);
}
