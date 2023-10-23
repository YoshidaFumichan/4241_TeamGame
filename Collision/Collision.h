#pragma once

class Sphere;
class Box;

/// <summary>
/// �Փ˔���N���X
/// </summary>
class Collision {
public: // �T�u�N���X
	struct Line {
		int s_x;	// �n�_X
		int s_y;	// �n�_Y
		int e_x;	// �I�_X
		int e_y;	// �I�_Y
	};

public: // �ÓI�����o�֐�
	/// <summary>
	/// ���Ƌ��̏Փ˔���
	/// </summary>
	/// <param name="sphereA">��A</param>
	/// <param name="sphereB">��B</param>
	/// <returns>�Փ˂��Ă邩</returns>
	static const bool& SphereToSphere(const Sphere& sphereA, const Sphere& sphereB);

	/// <summary>
	/// ���Ɛ��̏Փ˔���
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="line">��</param>
	/// <returns>�Փ˂��Ă邩</returns>
	static const bool& SphereToLine(const Sphere& sphere, const Line& line);

	/// <summary>
	/// ���Ǝl�p�̏Փ˔���
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="box">�l�p</param>
	/// <returns>�Փ˂��Ă邩</returns>
	static const bool& SphereToBox(const Sphere& sphere, const Box& box);

	/// <summary>
	/// �l�p�Ǝl�p
	/// </summary>
	/// <param name="boxA">�l�pA</param>
	/// <param name="boxB">�l�pB</param>
	/// <returns>�Փ˂��Ă�</returns>
	//static const bool& BoxToBox(const Box& boxA, const Box& boxB);

};