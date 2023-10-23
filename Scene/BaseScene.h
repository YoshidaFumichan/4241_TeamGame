#pragma once
#include "SceneManager.h"
#include "GraphicLoader.h"
#include "Input.h"

/// <summary>
/// 基盤シーン
/// </summary>
class BaseScene {
protected: // 静的メンバ変数
	// 入力クラス
	static SceneManager* sceneManager;
	static GraphicLoader* graphicLoader;
	static Input* input;

public: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	inline virtual void Initialize() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	inline virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	inline virtual void Draw() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	inline virtual void Finalize() = 0;

protected: // メンバ変数
	// 背景音声
	int bgm;
};