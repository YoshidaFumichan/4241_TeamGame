#pragma once
#include "BaseScene.h"
#include "BaseObject.h"

#include <list>

/// <summary>
/// �v���C�V�[��
/// </summary>
class PlayScene :
	public BaseScene {
public: // �����o�֐�
	/// <summary>
	/// 
	/// </summary>
	~PlayScene();

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

};