#pragma once
#include "GraphicLoader.h"

class BaseCollider;

/// <summary>
/// ���N���X
/// </summary>
class BaseObject {
protected: // �T�u�N���X
	/// <summary>
	/// ���W���
	/// </summary>
	struct Position {
		int x;
		int y;
	};

public: // �����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BaseObject() {};

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~BaseObject();

	/// <summary>
	/// ����������
	/// </summary>
	inline virtual void Initialize() {};

	/// <summary>
	/// �I������
	/// </summary>
	virtual void Finalize() {};

	/// <summary>
	/// �X�V����
	/// </summary>
	inline virtual void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	inline virtual void Draw();

	/// <summary>
	/// �Փˎ�����
	/// </summary>
	/// <param name="collider">�Փˑ���</param>
	virtual void OnCollision(BaseCollider* collider) = 0;

	/// <summary>
	/// �R���C�_�[�̉���
	/// </summary>
	void UnsetCollider();

	/// <summary>
	/// ���W���擾
	/// </summary>
	/// <returns>���W</returns>
	inline const Position& GetPosition() { return position; }

	/// <summary>
	/// �O���t�B�b�N�i���o�[���擾
	/// </summary>
	/// <returns>�O���t�B�b�N�i���o�[</returns>
	inline const int& GetGraphicNum() { return graphicHandle; }

	/// <summary>
	/// ���W��ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	inline void SetPosition(const Position& position) { this->position = position; }

	/// <summary>
	/// �R���C�_�[��ݒ�
	/// </summary>
	/// <param name="collider">�R���C�_�[</param>
	void SetCollider(BaseCollider* collider);

	/// <summary>
	/// �O���t�B�b�N�i���o�[��ݒ�
	/// </summary>
	/// <param name="graphicNum">�O���t�B�b�N�i���o�[</param>
	inline void SetGraphicHandle(const int& graphicHandle) { this->graphicHandle = graphicHandle; }

protected: // �����o�ϐ�
	// ���W
	Position position;
	// �R���C�_�[
	BaseCollider* collider;
	// �摜�̃i���o�[
	int graphicHandle;
	// �傫��
	int sizeX;	// ����
	int sizeY;	// �c��
};