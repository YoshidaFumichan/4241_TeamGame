#pragma once
#include "SceneManager.h"
#include "GraphicLoader.h"
#include "Input.h"

/// <summary>
/// ��ՃV�[��
/// </summary>
class BaseScene {
protected: // �ÓI�����o�ϐ�
	// ���̓N���X
	static SceneManager* sceneManager;
	static GraphicLoader* graphicLoader;
	static Input* input;

public: // �����o�֐�
	/// <summary>
	/// ����������
	/// </summary>
	inline virtual void Initialize() = 0;

	/// <summary>
	/// �X�V����
	/// </summary>
	inline virtual void Update() = 0;

	/// <summary>
	/// �`�揈��
	/// </summary>
	inline virtual void Draw() = 0;

	/// <summary>
	/// �I������
	/// </summary>
	inline virtual void Finalize() = 0;

protected: // �����o�ϐ�
	// �w�i����
	int bgm;
};