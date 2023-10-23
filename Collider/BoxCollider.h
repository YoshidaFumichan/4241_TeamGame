#pragma once
#include "BaseCollider.h"

/// <summary>
/// 四角コライダー
/// </summary>
class BoxCollider :
	public BaseCollider {
public: // メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	BoxCollider(const int& sizeX, const int& sizeY);

	/// <summary>
	/// 描画処理
	/// </summary>
	inline void Draw() override;

	/// <summary>
	/// 横幅を取得
	/// </summary>
	/// <returns>横幅</returns>
	inline const int& GetSizeX() { return sizeX; }

	/// <summary>
	/// 縦幅を設定
	/// </summary>
	/// <returns>縦幅</returns>
	inline const int& GetSizeY() { return sizeY; }

	/// <summary>
	/// 横幅を設定
	/// </summary>
	/// <param name="sizeX">横幅</param>
	inline void SetSizeX(const int& sizeX) { this->sizeX = sizeX; }

	/// <summary>
	/// 縦幅を設定
	/// </summary>
	/// <param name="sizeY">縦幅</param>
	inline void SetSizeY(const int& sizeY) { this->sizeY = sizeY; }

private: // メンバ変数
	int sizeX;	// 横幅
	int sizeY;	// 縦幅
};