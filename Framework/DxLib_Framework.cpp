#include "DxLib_Framework.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Input.h"
#include "GraphicLoader.h"

#include <DxLib.h>
#include <assert.h>

/// <summary>
/// �ÓI�����o�ϐ��̎���
/// </summary>
const wchar_t* DxLib_Framework::TITLE = L"���؂�ŗD��";
int DxLib_Framework::startTime = GetNowCount();

DxLib_Framework* DxLib_Framework::GetInstance() {
	// �C���X�^���X��錾
	static DxLib_Framework instance;
	return &instance;
}

void DxLib_Framework::Run()
{
	// ����������
	Initialize();
	// �Q�[�����[�v
	Loop();
	// �I������
	Finalize();
}

inline void DxLib_Framework::Initialize()
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0xFF);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { assert(0); }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// ���̓N���X�̃C���X�^���X���擾
	input = Input::GetInstance();

	// �V�[����������(�^�C�g���V�[��)
	SceneManager::GetInstance()->Initialize(new TitleScene());
}

inline void DxLib_Framework::Loop()
{
	while (1)
	{
		// ���͏��̍X�V����
		input->Update();

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene();

		// �X�V����
		SceneManager::GetInstance()->Update();

		// �`�揈��
		SceneManager::GetInstance()->Draw();

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
}

inline void DxLib_Framework::Finalize()
{
	// �I������
	SceneManager::GetInstance()->Finalize();
	GraphicLoader::GetInstance()->Finalize();


	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return;
}
