#pragma once
#include <map>
#include <string>

/// <summary>
/// �摜�ǂݍ��݃N���X
/// </summary>
class GraphicLoader {
public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X���擾
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static GraphicLoader* GetInstance();

private:
	GraphicLoader() = default;
	GraphicLoader(const GraphicLoader&) = delete;
	~GraphicLoader() = default;
	GraphicLoader& operator=(const GraphicLoader&) = delete;

public: // �����o�֐�
	/// <summary>
	/// �I������
	/// </summary>
	void Finalize();

	/// <summary>
	/// �O���t�B�b�N�n���h�����擾
	/// </summary>
	/// <param name="graphName">�O���t�B�b�N�l�[��</param>
	/// <returns>�O���t�B�b�N�i���o�[</returns>
	const int& GetGraphHandle(const wchar_t* graphName);

	/// <summary>
	/// �A�ԉ摜�̃O���t�B�b�N�n���h�����擾
	/// </summary>
	/// <param name="graphName">�O���t�B�b�N�l�[��</param>
	/// <param name="graphHandleArray">�擾����ϐ�</param>
	/// <param name="arrayNum">�v�f��</param>
	void GetDivGraphHandle(const wchar_t* graphName, int* graphHandleArray, const unsigned int& arrayNum);

	/// <summary>
	/// �O���t�B�b�N�n���h����ݒ�
	/// </summary>
	/// <param name="graphName">�O���t�B�b�N�l�[��</param>
	void LoadGraphHandle(const wchar_t* graphName);

	/// <summary>
	/// �A�ԉ摜�̃O���t�B�b�N�n���h����ݒ�
	/// </summary>
	/// <param name="graphName">�O���t�B�b�N�l�[��</param>
	/// <param name="allNum">�v�f��</param>
	/// <param name="XNum">���̗v�f��</param>
	/// <param name="YNum">�c�̗v�f��</param>
	/// <param name="XSize">�؂��肽������</param>
	/// <param name="YSize">�؂��肽���c��</param>
	void SetDivGraphHandle(const wchar_t* graphName, const unsigned int& allNum, const unsigned int& XNum,
		const unsigned int& YNum, const unsigned int& XSize, const unsigned int& YSize);

	/// <summary>
	/// �S�폜
	/// </summary>
	void Clear();

private: // �����o�ϐ�
	// �ǂݍ��񂾉摜�̘A�z�z��
	std::map<const wchar_t*, int> graphHandles;
	std::map<const wchar_t*, int*> graphArraiyHandles;

};