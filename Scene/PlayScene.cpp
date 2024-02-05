#include "PlayScene.h"
#include "EndScene.h"
#include <DxLib.h>
#include <DxLib_FrameWork.h>
#include <assert.h>
#include <time.h>

void PlayScene::Initialize() {
	// 背景画像取得
	BackGraph = LoadGraph(L"Resources/BackGraph.png");
	// BGM取得
	bgm = LoadSoundMem(L"Resources/BGM_Play.mp3");
	// 音量を変更
	ChangeVolumeSoundMem(50, bgm);
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

	lifeHandle = LoadGraph(L"Resources/life.png");
	lifenoHandle = LoadGraph(L"Resources/life2.png");

	scoreGraphHandle = LoadGraph(L"Resources/plyascore.png");
	LoadDivGraph(L"Resources/number.png", 10, 10, 1, 30, 70, scoreHandle);


}

void PlayScene::Update() {
	if (oldNotes != nowNotes) {
		if (oldNotes == oldCutNum) {
			if (endhit == 0) {
				life -= 1;
			}
		}
		else {
			if (notes[oldNotes]->hit == 0) {
				life -= 1;
			}
		}
	}

	oldNotes = nowNotes;
	// 開始時カウントダウン
	StartCountDown();

	// スタートフラグが立っていたら
	if (StartFlag) {
		// ノーツの更新処理
		for (int i = 0; i <= cutNum; i++) {
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
				damageFlag = true;
			}
		}


		if (life <= 0) {
			sceneManager->SetNextScene(new EndScene());
		}


		if (notes[cutNum]->EndFlag) {
			endhit = notes[cutNum]->hit;
			oldCutNum = cutNum;
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
	DrawGraph(0, 50, scoreGraphHandle, true);

	if (score < 10) {
		DrawGraph(280, 50, scoreHandle[score], true);
	}
	else if (score < 100) {
		int n = (score / 10);
		DrawGraph(280, 50, scoreHandle[n], true);
		n = (score % 10);
		DrawGraph(310, 50, scoreHandle[n], true);
	}
	else if (score < 1000) {
		int n = (score / 100);
		DrawGraph(280, 50, scoreHandle[n], true);
		n = (score % 100);
		n = (n / 10);
		DrawGraph(310, 50, scoreHandle[n], true);
		n = (score % 100);
		n = (n % 10);
		DrawGraph(340, 50, scoreHandle[n], true);
	}

	
	if (life == 3)
	{
		DrawGraph(0, 550, lifeHandle, true);
		DrawGraph(125, 550, lifeHandle, true);
		DrawGraph(250, 550, lifeHandle, true);
	}
	else if (life == 2)
	{
		DrawGraph(0, 550, lifenoHandle, true);
		DrawGraph(125, 550, lifeHandle, true);
		DrawGraph(250, 550, lifeHandle, true);
	}
	else if (life == 1)
	{
		DrawGraph(0, 550, lifenoHandle, true);
		DrawGraph(125, 550, lifenoHandle, true);
		DrawGraph(250, 550, lifeHandle, true);
	}
	else if (life == 0)
	{
		DrawGraph(0, 550, lifenoHandle, true);
		DrawGraph(125, 550, lifenoHandle, true);
		DrawGraph(250, 550, lifenoHandle, true);
	}
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
	srand(time(NULL));
	cutNum = rand() % 4 + 1;
	// 湯切り
	for (int i = 0; i < cutNum; i++) {
		notes[i]->Initialize(0, GetNowCount() + i * 1000);
	}
	// ラーメン完成
	notes[cutNum]->Initialize(1, GetNowCount() + cutNum * 1000);
}
