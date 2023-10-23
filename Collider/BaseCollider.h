#pragma once
#include "BaseObject.h"

#include "assert.h"
#include "ColliderTypes.h"

/// <summary>
/// �x�[�X�R���C�_�[
/// </summary>
class BaseCollider {
protected: // �T�u�N���X
	/// <summary>
	/// ���W���
	/// </summary>
	struct Position {
		int x;
		int y;
	};

public: // �����o�֐�
	friend class CollisionManager;
	BaseCollider() = default;
	virtual ~BaseCollider() = default;

	/// <summary>
	/// �I�u�W�F�N�g���擾
	/// </summary
	/// <returns>�I�u�W�F�N�g</returns>
	inline BaseObject* GetObject() {
		return object;
	}

	/// <summary>
	/// �I�u�W�F�N�g��ݒ�
	/// </summary>
	/// <param name="object">�I�u�W�F�N�g</param>
	inline void SetObject(BaseObject* object) {
		this->object = object;
	}

	/// <summary>
	/// �X�V����
	/// </summary>
	inline virtual void Update() {
		position.x = object->GetPosition().x;
		position.y = object->GetPosition().y;
	}

	/// <summary>
	/// �`�揈��
	/// </summary>
	inline virtual void Draw() {}


	/// <summary>
	/// �Փˎ�����
	/// </summary>
	/// <param name="collider">�Փˑ���</param>
	inline virtual void OnCollision(BaseCollider* collider) {
		object->OnCollision(collider);
	}

	/// <summary>
	/// �`��^�C�v���擾
	/// </summary>
	/// <returns>�`��^�C�v</returns>
	inline CollisionShapeType GetShapeType() { return shapeType; }

	/// <summary>
	/// ���W���擾
	/// </summary>
	/// <returns></returns>
	inline const Position& GetPosition() { return position; }

	/// <summary>
	/// ���ʏ����擾
	/// </summary>
	/// <returns>���ʏ��</returns>
	inline const char* GetTag() { return tag; }

	/// <summary>
	/// ���ʏ���ݒ�
	/// </summary>
	/// <param name="tag">���ʏ��</param>
	inline void SetTag(const char* tag) { 
		this->tag = tag;
	}

protected: // �����o�ϐ�
	// �I�u�W�F�N�g
	BaseObject* object;
	// ���ʏ��
	const char* tag;
	// ���W
	Position position;
	// �`��^�C�v
	CollisionShapeType shapeType = SHAPE_UNKNOWN;
};