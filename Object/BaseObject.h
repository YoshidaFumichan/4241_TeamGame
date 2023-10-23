#pragma once
#include "GraphicLoader.h"

class BaseCollider;

/// <summary>
/// 基底クラス
/// </summary>
class BaseObject {
protected: // サブクラス
	/// <summary>
	/// 座標情報
	/// </summary>
	struct Position {
		int x;
		int y;
	};

public: // メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	BaseObject() {};

	/// <summary>
	/// デストラクタ
	/// </summary>
	~BaseObject();

	/// <summary>
	/// 初期化処理
	/// </summary>
	inline virtual void Initialize() {};

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() {};

	/// <summary>
	/// 更新処理
	/// </summary>
	inline virtual void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	inline virtual void Draw();

	/// <summary>
	/// 衝突時処理
	/// </summary>
	/// <param name="collider">衝突相手</param>
	virtual void OnCollision(BaseCollider* collider) = 0;

	/// <summary>
	/// コライダーの解除
	/// </summary>
	void UnsetCollider();

	/// <summary>
	/// 座標を取得
	/// </summary>
	/// <returns>座標</returns>
	inline const Position& GetPosition() { return position; }

	/// <summary>
	/// グラフィックナンバーを取得
	/// </summary>
	/// <returns>グラフィックナンバー</returns>
	inline const int& GetGraphicNum() { return graphicHandle; }

	/// <summary>
	/// 座標を設定
	/// </summary>
	/// <param name="position">座標</param>
	inline void SetPosition(const Position& position) { this->position = position; }

	/// <summary>
	/// コライダーを設定
	/// </summary>
	/// <param name="collider">コライダー</param>
	void SetCollider(BaseCollider* collider);

	/// <summary>
	/// グラフィックナンバーを設定
	/// </summary>
	/// <param name="graphicNum">グラフィックナンバー</param>
	inline void SetGraphicHandle(const int& graphicHandle) { this->graphicHandle = graphicHandle; }

protected: // メンバ変数
	// 座標
	Position position;
	// コライダー
	BaseCollider* collider;
	// 画像のナンバー
	int graphicHandle;
	// 大きさ
	int sizeX;	// 横幅
	int sizeY;	// 縦幅
};