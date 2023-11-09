#pragma once

/// <summary>
/// ���̓N���X
/// </summary>
class Input
{
public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Input* GetInstance();

private: // �����o�֐�
	Input() = default;
	Input(const Input&) = delete;
	~Input() = default;
	Input& operator=(const Input&) = delete;

public: // �����o�֐�
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// ���͏����擾
	/// ��FGetKey(KEYS_INPUT_SPACE)(�X�y�[�X�L�[���͏��擾)
	/// </summary>
	/// <param name="num">�L�[�i���o�[</param>
	/// <returns>���͏��</returns>
	inline const char& GetKey(short num) { return keys[num]; }

	/// <summary>
	/// 1�t���[���O�̓��͏����擾
	/// ��FGetOldKey(KEYS_INPUT_SPACE)(1�t���[���O�̃X�y�[�X�L�[���͏��擾)
	/// </summary>
	/// <param name="num">�L�[�i���o�[</param>
	/// <returns>1�t���[���O�̓��͏��</returns>
	inline const char& GetOldKey(short num) { return oldkeys[num]; }

private: // �����o�ϐ�
	// �L�[�{�[�h
	char keys[256];
	// 1�t���[���O�̃L�[����
	char oldkeys[256];
};