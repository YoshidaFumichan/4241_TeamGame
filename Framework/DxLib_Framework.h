#pragma once
#include <Dxlib.h>

#include "Input.h"
#include "SceneManager.h"

/// <summary>
/// �t���[�����[�N
/// </summary>
class DxLib_Framework
{
private: // �ÓI�����o�ϐ�
	// �E�B���h�E�̃^�C�g���ɕ\�����镶����
	static const wchar_t* TITLE;
	// �E�B���h�E����
	static const int WIN_WIDTH = 1280;
	// �E�B���h�E�c��
	static const int WIN_HEIGHT = 720;
	// �X�^�[�g���Ԏ擾
	static int startTime;
public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	static DxLib_Framework* GetInstance();

	/// <summary>
	/// �^�C�g�����擾
	/// </summary>
	/// <returns>�^�C�g��</returns>
	static const wchar_t* GetTITLE() { return TITLE; }

	/// <summary>
	/// �E�B���h�E�������擾
	/// </summary>
	/// <returns>�E�B���h�E����</returns>
	static const int& GetWIN_WIDTH() { return WIN_WIDTH; }

	/// <summary>
	/// �E�B���h�E�c�����擾
	/// </summary>
	/// <returns>�E�B���h�E�c��</returns>
	static const int& GetWIN_HEIGHT() { return WIN_HEIGHT; }

	/// <summary>
	/// �X�^�[�g���Ԃ��擾
	/// </summary>
	/// <returns>�X�^�[�g����</returns>
	static const int& GetStartCount() { return startTime; }

public: // �����o�֐�
	/// <summary>
	/// ���s����
	/// </summary>
	void Run();

private: // �����o�֐�
	/// <summary>
	/// ����������
	/// </summary>
	inline void Initialize();

	/// <summary>
	/// �Q�[�����[�v����
	/// </summary>
	inline void Loop();

	/// <summary>
	/// �I������
	/// </summary>
	inline void Finalize();

private: // �����o�ϐ�
	// ���͏��
	Input* input = nullptr;

};