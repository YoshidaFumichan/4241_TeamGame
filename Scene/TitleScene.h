#pragma once
#include "BaseScene.h"

/// <summary>
/// �^�C�g���V�[��
/// </summary>
class TitleScene :
	public BaseScene {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	~TitleScene();

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
};