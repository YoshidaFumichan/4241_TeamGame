#pragma once
#include "BaseScene.h"

/// <summary>
/// タイトルシーン
/// </summary>
class EndScene :
	public BaseScene {
private: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw()override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize()override;

private: // メンバ変数
	// 背景画像
	int endGraph = 0;
};