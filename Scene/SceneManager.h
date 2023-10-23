#pragma once

class BaseScene;

/// <summary>
/// �V�[���}�l�[�W���[
/// </summary>
class SceneManager
{
public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	static SceneManager* GetInstance();

public: // �����o�֐�
	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="scene">�ŏ��̃V�[��</param>
	void Initialize(BaseScene* scene);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize();

	/// <summary>
	/// ���̃V�[���ݒ�
	/// </summary>
	/// <param name="nextScene">���̃V�[��</param>
	void SetNextScene(BaseScene* nextScene) { this->nextScene = nextScene; }

	/// <summary>
	/// �V�[���؂�ւ�����
	/// </summary>
	void ChangeScene();

private: // �����o�֐�
	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	~SceneManager() = default;
	SceneManager& operator=(const SceneManager&) = delete;

private: // �����o�ϐ�
	// �V�[��
	BaseScene* scene = nullptr;
	// �l�N�X�g�V�[��
	BaseScene* nextScene = nullptr;
};