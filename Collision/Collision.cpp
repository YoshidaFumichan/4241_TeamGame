#include "Collision.h"
#include "BaseCollider.h"
#include "CollisionPrimitive.h"

#include <Math.h>
#include <DxLib.h>

const bool& Collision::SphereToSphere(const Sphere& sphereA, const Sphere& sphereB) {
	// X���W - X���W 
	int dx = sphereA.x - sphereB.x;
	// Y���W - Y���W 
	int dy = sphereA.y - sphereB.y;
	// 
	int d = dx * dx + dy * dy;
	// 
	float Contacr = sqrtf(d);
	// �Փ˂��Ă邩
	if (Contacr <= (sphereA.r + sphereB.r)) {
		return true;
	}
	return false;
}

const bool& Collision::SphereToLine(const Sphere& sphere, const Line& line) {
	// �~�̒��S�Ɛ��̎n�_�x�N�g�� 
	// �~�̒��S�Ɛ��̎n�_�x�N�g��
	VECTOR c_to_s = { sphere.x - line.s_x, sphere.y - line.s_y, 1 };
	// �~�̒��S�Ɛ��̏I�_�x�N�g��
	VECTOR c_to_e = { sphere.x - line.e_x, sphere.y - line.e_y, 1 };
	// ���̎n�_�ƏI�_�x�N�g��
	VECTOR s_to_e = { line.e_x - line.s_x, line.e_y - line.s_y, 1 };
	// �n�_�ƏI�_�̃x�N�g�����K��
	VECTOR normal_s_to_e;
	DxLib::VectorNormalize(&normal_s_to_e, &s_to_e);
	// ����
	float distance = c_to_s.x * normal_s_to_e.y - normal_s_to_e.x * c_to_s.y;

	// ����
	if (fabs(distance) < sphere.r) {
		float dot1 = c_to_s.x * s_to_e.x + c_to_s.y * s_to_e.y;
		float dot2 = c_to_e.x * s_to_e.x + c_to_e.y * s_to_e.y;
		if (dot1 * dot2 <= 0.0f) {
			return true;
		}
	}
	return false;
}

const bool& Collision::SphereToBox(const Sphere& sphere, const Box& box) {
	// ��
	Line line;
	line = { box.x - box.sizeX / 2,box.y - box.sizeY / 2,
		box.x - box.sizeX / 2,box.y + box.sizeY / 2, };
	DrawLine(box.x - box.sizeX / 2, box.y - box.sizeY / 2,
		box.x - box.sizeX / 2, box.y + box.sizeY / 2,
		GetColor(0, 0, 0));
	// ���ƍ������̏Փ�
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x + box.sizeX / 2,box.y - box.sizeY / 2,
		box.x + box.sizeX / 2,box.y + box.sizeY / 2, };
	// ���ƉE�����̏Փ�
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x - box.sizeX / 2,box.y - box.sizeY / 2,
		box.x + box.sizeX / 2,box.y - box.sizeY / 2, };
	// ���Ə�c���̏Փ�
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x - box.sizeX / 2,box.y + box.sizeY / 2,
		box.x + box.sizeX / 2,box.y + box.sizeY / 2, };
	// ���Ɖ��c���̏Փ�
	if (SphereToLine(sphere, line)) {
		return true;
	}
	return false;
}

//const bool& Collision::BoxToBox(const Box& boxA, const Box& boxB) {
//	return false;
//}
