#pragma once

class SphereCollider;
class BoxCollider;


/// <summary>
/// ��
/// </summary>
struct Sphere {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="sphere">�R���C�_�[</param>
	Sphere(SphereCollider* sphere);

	int x;	// X���W
	int y;	// Y���W
	int r;	// ���a
};


/// <summary>
/// ��
/// </summary>
struct Line {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Line(const int& s_x, const int& s_y,
		const int& e_x, const int& e_y);

	int s_x;	// �n�_X
	int s_y;	// �n�_Y
	int e_x;	// �I�_X
	int e_y;	// �I�_Y
};

/// <summary>
/// �l�p
/// </summary>
struct Box {
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="sphere"></param>
	Box(BoxCollider* box);

	int x;		// X���W
	int y;		// Y���W
	int sizeX;	// ����
	int sizeY;	// �c��
};