#pragma once
#include "BaseScene.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class EndScene :
	public BaseScene {
private: // �����o�֐�
	/// <summary>
	/// ����������
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update()override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw()override;

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize()override;

private: // �����o�ϐ�
	// �w�i�摜
	int endGraph = 0;
};