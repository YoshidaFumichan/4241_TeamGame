#include "SceneManager.h"
#include "BaseScene.h"

SceneManager* SceneManager::GetInstance()
{
	// �C���X�^���X��錾
	static SceneManager instance;
	return &instance;
}

void SceneManager::Initialize(BaseScene* scene)
{
	// �V�[����ݒ�
	this->scene = scene;
	// ����������
	scene->Initialize();
}

// �X�V����
void SceneManager::Update() { scene->Update(); }

// �`�揈��
void SceneManager::Draw() { scene->Draw(); }

void SceneManager::Finalize()
{
	//�V�[���I������
	scene->Finalize();
}

void SceneManager::ChangeScene()
{
	if (this->nextScene != nullptr) {
		// �I������
		scene->Finalize();
		// ���̃V�[����ݒ�
		scene = nextScene;
		// ����������
		scene->Initialize();
		// nextScene��nullptr�ɂ���
		nextScene = nullptr;
	}
}