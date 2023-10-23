#pragma once
#include "BaseCollider.h"

#include <forward_list>

/// <summary>
/// 衝突マネージャー
/// </summary>
class CollisionManager{
public: // 静的メンバ関数
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static CollisionManager* GetInstance();

private: 
	CollisionManager() = default;
	CollisionManager(const CollisionManager&) = delete;
	~CollisionManager() = default;
	CollisionManager& operator=(const CollisionManager&) = delete;

public:// メンバ関数
	/// <summary>
	/// コライダーの追加
	/// </summary>
	/// <param name="collider">コライダー</param>
	inline void AddCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	/// <summary>
	/// コライダーの削除
	/// </summary>
	/// <param name="collider">コライダー</param>
	inline void RemoveCollider(BaseCollider* collider) {
		colliders.remove(collider);
	}

	/// <summary>
	/// 全衝突判定
	/// </summary>
	void CheckAllCollisions();
private: // メンバ変数
	// コライダーのリスト
	std::forward_list<BaseCollider*> colliders;

};