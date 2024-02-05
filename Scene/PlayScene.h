#pragma once
#include "BaseScene.h"
#include "Notes.h"

class PlayScene :
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

private: // �����o�֐�
	/// <summary>
	/// �J�n���J�E���g�_�E��
	/// </summary>
	void StartCountDown();

	/// <summary>
	/// �m�[�c�̐�������
	/// </summary>
	void CreateNotes();

private: // �����o�ϐ�
	// �w�i�摜
	int BackGraph;
	// �J�E���g�X�^�[�g�^�C��
	int StartTime;
	// �X�^�[�g�J�E���g�_�E��
	short CountDown;
	// �J�E���g�_�E���p�摜
	int CountDownGraph[3];
	// �X�^�[�g�t���O
	bool StartFlag;
	// �G���h�t���O
	bool EndFlag;
	// ���؂肨������A�j���[�V����
	int CutOjiAnimation;
	// ���؂肨������摜
	int CutOjiGraph[3];
	// ���[�����A�j���[�V����
	int RamenAnimation;
	// ���[�����摜
	int RamenGraph[2];
	// �m�[�c
	Notes* notes[5];
	// �m�[�c�J�E���g
	int nowNotes = 0;
	int oldNotes = 0;
	int goodGraph;
	int missGraph;
	int life = 3;
	bool damageFlag = false;
	int score = 0;
	bool scoreFlag = false;
	int scoreHandle[10] = {};
	int scoreGraphHandle = 0;
	int endhit = 1;
	int cutNum = 0;
	int oldCutNum = 0;
	int lifeHandle = 0;
	int lifenoHandle = 0;
};