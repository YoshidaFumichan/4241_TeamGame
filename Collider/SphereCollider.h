#pragma once
#include "BaseCollider.h"

/// <summary>
/// ���R���C�_�[
/// </summary>
class SphereCollider :
	public BaseCollider {
public: // �����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="radius">���a</param>
	SphereCollider(const int& radius);

	/// <summary>
	/// �`�揈��
	/// </summary>
	inline void Draw() override;

	/// <summary>
	/// ���a���擾
	/// </summary>
	/// <returns>���a</returns>
	inline const int& GetRadius() { return radius; }

	/// <summary>
	/// ���a��ݒ�
	/// </summary>
	/// <param name="radius">���a</param>
	inline void SetRadius(const int& radius) { this->radius = radius; }

private: // �����o�ϐ�
	// ���a
	int radius;
};

