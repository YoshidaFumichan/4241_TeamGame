#include "BaseObject.h"
#include "BaseCollider.h"
#include "CollisionManager.h"

#include <DxLib.h>

BaseObject::~BaseObject() {
	// �R���C�_�[��nullptr�łȂ��Ȃ�
	if (collider != nullptr) {
		// �Փ˃}�l�[�W���[����R���C�_�[���폜
		CollisionManager::GetInstance()->RemoveCollider(collider);
		collider = nullptr;
	}
}

inline void BaseObject::Update() {
	if (collider) {
		// �R���C�_�[�̍X�V����
		collider->Update();
	}
}

inline void BaseObject::Draw() {
	DrawGraph(position.x - sizeX / 2, position.y - sizeY / 2, 
		graphicHandle, true);
}

void BaseObject::UnsetCollider() {
	// �R���C�_�[��nullptr�łȂ��Ȃ�
	if (collider != nullptr) {
		// �Փ˃}�l�[�W���[����R���C�_�[���폜
		CollisionManager::GetInstance()->RemoveCollider(collider);
		delete(collider);
		collider = nullptr;
	}
}

void BaseObject::SetCollider(BaseCollider* collider) {
	this->collider = collider;
	this->collider->SetObject(this);
	// �Փ˃}�l�[�W���[�ɃR���C�_�[��ǉ�
	CollisionManager::GetInstance()->AddCollider(collider);
}