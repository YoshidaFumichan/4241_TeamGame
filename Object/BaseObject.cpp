#include "BaseObject.h"
#include "BaseCollider.h"
#include "CollisionManager.h"

#include <DxLib.h>

BaseObject::~BaseObject() {
	// コライダーがnullptrでないなら
	if (collider != nullptr) {
		// 衝突マネージャーからコライダーを削除
		CollisionManager::GetInstance()->RemoveCollider(collider);
		collider = nullptr;
	}
}

inline void BaseObject::Update() {
	if (collider) {
		// コライダーの更新処理
		collider->Update();
	}
}

inline void BaseObject::Draw() {
	DrawGraph(position.x - sizeX / 2, position.y - sizeY / 2, 
		graphicHandle, true);
}

void BaseObject::UnsetCollider() {
	// コライダーがnullptrでないなら
	if (collider != nullptr) {
		// 衝突マネージャーからコライダーを削除
		CollisionManager::GetInstance()->RemoveCollider(collider);
		delete(collider);
		collider = nullptr;
	}
}

void BaseObject::SetCollider(BaseCollider* collider) {
	this->collider = collider;
	this->collider->SetObject(this);
	// 衝突マネージャーにコライダーを追加
	CollisionManager::GetInstance()->AddCollider(collider);
}