#pragma once
#include "BaseObject.h"

#include "assert.h"
#include "ColliderTypes.h"

/// <summary>
/// ベースコライダー
/// </summary>
class BaseCollider {
protected: // サブクラス
	/// <summary>
	/// 座標情報
	/// </summary>
	struct Position {
		int x;
		int y;
	};

public: // メンバ関数
	friend class CollisionManager;
	BaseCollider() = default;
	virtual ~BaseCollider() = default;

	/// <summary>
	/// オブジェクトを取得
	/// </summary
	/// <returns>オブジェクト</returns>
	inline BaseObject* GetObject() {
		return object;
	}

	/// <summary>
	/// オブジェクトを設定
	/// </summary>
	/// <param name="object">オブジェクト</param>
	inline void SetObject(BaseObject* object) {
		this->object = object;
	}

	/// <summary>
	/// 更新処理
	/// </summary>
	inline virtual void Update() {
		position.x = object->GetPosition().x;
		position.y = object->GetPosition().y;
	}

	/// <summary>
	/// 描画処理
	/// </summary>
	inline virtual void Draw() {}


	/// <summary>
	/// 衝突時処理
	/// </summary>
	/// <param name="collider">衝突相手</param>
	inline virtual void OnCollision(BaseCollider* collider) {
		object->OnCollision(collider);
	}

	/// <summary>
	/// 形状タイプを取得
	/// </summary>
	/// <returns>形状タイプ</returns>
	inline CollisionShapeType GetShapeType() { return shapeType; }

	/// <summary>
	/// 座標を取得
	/// </summary>
	/// <returns></returns>
	inline const Position& GetPosition() { return position; }

	/// <summary>
	/// 識別情報を取得
	/// </summary>
	/// <returns>識別情報</returns>
	inline const char* GetTag() { return tag; }

	/// <summary>
	/// 識別情報を設定
	/// </summary>
	/// <param name="tag">識別情報</param>
	inline void SetTag(const char* tag) { 
		this->tag = tag;
	}

protected: // メンバ変数
	// オブジェクト
	BaseObject* object;
	// 識別情報
	const char* tag;
	// 座標
	Position position;
	// 形状タイプ
	CollisionShapeType shapeType = SHAPE_UNKNOWN;
};