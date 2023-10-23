#pragma once
#include "BaseScene.h"
#include "BaseObject.h"

#include <list>

/// <summary>
/// プレイシーン
/// </summary>
class PlayScene :
	public BaseScene {
public: // メンバ関数
	/// <summary>
	/// 
	/// </summary>
	~PlayScene();

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

};