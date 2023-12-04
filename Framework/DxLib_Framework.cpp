#include "DxLib_Framework.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Input.h"
#include "GraphicLoader.h"

#include <DxLib.h>
#include <assert.h>

/// <summary>
/// 静的メンバ変数の実態
/// </summary>
const wchar_t* DxLib_Framework::TITLE = L"湯切りで優勝";
int DxLib_Framework::startTime = GetNowCount();

DxLib_Framework* DxLib_Framework::GetInstance() {
	// インスタンスを宣言
	static DxLib_Framework instance;
	return &instance;
}

void DxLib_Framework::Run()
{
	// 初期化処理
	Initialize();
	// ゲームループ
	Loop();
	// 終了処理
	Finalize();
}

inline void DxLib_Framework::Initialize()
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0xFF);

	// DXlibの初期化
	if (DxLib_Init() == -1) { assert(0); }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 入力クラスのインスタンスを取得
	input = Input::GetInstance();

	// シーンを初期化(タイトルシーン)
	SceneManager::GetInstance()->Initialize(new TitleScene());
}

inline void DxLib_Framework::Loop()
{
	while (1)
	{
		// 入力情報の更新処理
		input->Update();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene();

		// 更新処理
		SceneManager::GetInstance()->Update();

		// 描画処理
		SceneManager::GetInstance()->Draw();

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
}

inline void DxLib_Framework::Finalize()
{
	// 終了処理
	SceneManager::GetInstance()->Finalize();
	GraphicLoader::GetInstance()->Finalize();


	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return;
}
