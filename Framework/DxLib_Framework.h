#pragma once
#include <Dxlib.h>

#include "Input.h"
#include "SceneManager.h"

/// <summary>
/// フレームワーク
/// </summary>
class DxLib_Framework
{
private: // 静的メンバ変数
	// ウィンドウのタイトルに表示する文字列
	static const wchar_t* TITLE;
	// ウィンドウ横幅
	static const int WIN_WIDTH = 1280;
	// ウィンドウ縦幅
	static const int WIN_HEIGHT = 720;
	// スタート時間取得
	static int startTime;
public: // 静的メンバ関数
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	static DxLib_Framework* GetInstance();

	/// <summary>
	/// タイトルを取得
	/// </summary>
	/// <returns>タイトル</returns>
	static const wchar_t* GetTITLE() { return TITLE; }

	/// <summary>
	/// ウィンドウ横幅を取得
	/// </summary>
	/// <returns>ウィンドウ横幅</returns>
	static const int& GetWIN_WIDTH() { return WIN_WIDTH; }

	/// <summary>
	/// ウィンドウ縦幅を取得
	/// </summary>
	/// <returns>ウィンドウ縦幅</returns>
	static const int& GetWIN_HEIGHT() { return WIN_HEIGHT; }

	/// <summary>
	/// スタート時間を取得
	/// </summary>
	/// <returns>スタート時間</returns>
	static const int& GetStartCount() { return startTime; }

public: // メンバ関数
	/// <summary>
	/// 実行処理
	/// </summary>
	void Run();

private: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	inline void Initialize();

	/// <summary>
	/// ゲームループ処理
	/// </summary>
	inline void Loop();

	/// <summary>
	/// 終了処理
	/// </summary>
	inline void Finalize();

private: // メンバ変数
	// 入力情報
	Input* input = nullptr;

};