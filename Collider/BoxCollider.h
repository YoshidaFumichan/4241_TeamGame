#pragma once
#include "BaseCollider.h"

/// <summary>
/// �l�p�R���C�_�[
/// </summary>
class BoxCollider :
	public BaseCollider {
public: // �����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BoxCollider(const int& sizeX, const int& sizeY);

	/// <summary>
	/// �`�揈��
	/// </summary>
	inline void Draw() override;

	/// <summary>
	/// �������擾
	/// </summary>
	/// <returns>����</returns>
	inline const int& GetSizeX() { return sizeX; }

	/// <summary>
	/// �c����ݒ�
	/// </summary>
	/// <returns>�c��</returns>
	inline const int& GetSizeY() { return sizeY; }

	/// <summary>
	/// ������ݒ�
	/// </summary>
	/// <param name="sizeX">����</param>
	inline void SetSizeX(const int& sizeX) { this->sizeX = sizeX; }

	/// <summary>
	/// �c����ݒ�
	/// </summary>
	/// <param name="sizeY">�c��</param>
	inline void SetSizeY(const int& sizeY) { this->sizeY = sizeY; }

private: // �����o�ϐ�
	int sizeX;	// ����
	int sizeY;	// �c��
};