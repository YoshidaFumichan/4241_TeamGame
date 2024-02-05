#pragma once

/// <summary>
/// �m�[�c���
/// </summary>
class Notes {
public: // �ÓI�����o�֐�
	/// <summary>
	/// �ÓI����������
	/// </summary>
	static void StaticInitialize();

private: // �ÓI�����o�ϐ�
	// �T�E���h�G�t�F�N�g
	static int SoundEffect;
	// �L�[�摜�̃n���h��
	static int notesHandle[2];
public: // �����o�֐�
	/// <summary>
	/// ����������
	/// </summary>
	void Initialize(const int& type, const int& StartTime);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();


	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���͏����m�F
	/// </summary>
	inline void CheckInput();

public: // �����o�ϐ�
	// �^�C�v
	int type;
	int hit = 0;
	// �X�^�[�g�^�C��
	int StartTime = 0;
	// �G���h�^�C��
	int EndTime = 0;
	// �J�n�t���O
	bool StartFlag;
	// �I���t���O
	bool EndFlag;
	// ���݂̃m�[�c
	bool nowNotes;
};