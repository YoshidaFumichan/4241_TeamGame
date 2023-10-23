#pragma once
#include "BaseCollider.h"

#include <forward_list>

/// <summary>
/// �Փ˃}�l�[�W���[
/// </summary>
class CollisionManager{
public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CollisionManager* GetInstance();

private: 
	CollisionManager() = default;
	CollisionManager(const CollisionManager&) = delete;
	~CollisionManager() = default;
	CollisionManager& operator=(const CollisionManager&) = delete;

public:// �����o�֐�
	/// <summary>
	/// �R���C�_�[�̒ǉ�
	/// </summary>
	/// <param name="collider">�R���C�_�[</param>
	inline void AddCollider(BaseCollider* collider) {
		colliders.push_front(collider);
	}

	/// <summary>
	/// �R���C�_�[�̍폜
	/// </summary>
	/// <param name="collider">�R���C�_�[</param>
	inline void RemoveCollider(BaseCollider* collider) {
		colliders.remove(collider);
	}

	/// <summary>
	/// �S�Փ˔���
	/// </summary>
	void CheckAllCollisions();
private: // �����o�ϐ�
	// �R���C�_�[�̃��X�g
	std::forward_list<BaseCollider*> colliders;

};