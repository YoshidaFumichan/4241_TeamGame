#include "Collision.h"
#include "BaseCollider.h"
#include "CollisionPrimitive.h"

#include <Math.h>
#include <DxLib.h>

const bool& Collision::SphereToSphere(const Sphere& sphereA, const Sphere& sphereB) {
	// X座標 - X座標 
	int dx = sphereA.x - sphereB.x;
	// Y座標 - Y座標 
	int dy = sphereA.y - sphereB.y;
	// 
	int d = dx * dx + dy * dy;
	// 
	float Contacr = sqrtf(d);
	// 衝突してるか
	if (Contacr <= (sphereA.r + sphereB.r)) {
		return true;
	}
	return false;
}

const bool& Collision::SphereToLine(const Sphere& sphere, const Line& line) {
	// 円の中心と線の始点ベクトル 
	// 円の中心と線の始点ベクトル
	VECTOR c_to_s = { sphere.x - line.s_x, sphere.y - line.s_y, 1 };
	// 円の中心と線の終点ベクトル
	VECTOR c_to_e = { sphere.x - line.e_x, sphere.y - line.e_y, 1 };
	// 線の始点と終点ベクトル
	VECTOR s_to_e = { line.e_x - line.s_x, line.e_y - line.s_y, 1 };
	// 始点と終点のベクトル正規化
	VECTOR normal_s_to_e;
	DxLib::VectorNormalize(&normal_s_to_e, &s_to_e);
	// 距離
	float distance = c_to_s.x * normal_s_to_e.y - normal_s_to_e.x * c_to_s.y;

	// 判定
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
	// 線
	Line line;
	line = { box.x - box.sizeX / 2,box.y - box.sizeY / 2,
		box.x - box.sizeX / 2,box.y + box.sizeY / 2, };
	DrawLine(box.x - box.sizeX / 2, box.y - box.sizeY / 2,
		box.x - box.sizeX / 2, box.y + box.sizeY / 2,
		GetColor(0, 0, 0));
	// 球と左横線の衝突
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x + box.sizeX / 2,box.y - box.sizeY / 2,
		box.x + box.sizeX / 2,box.y + box.sizeY / 2, };
	// 球と右横線の衝突
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x - box.sizeX / 2,box.y - box.sizeY / 2,
		box.x + box.sizeX / 2,box.y - box.sizeY / 2, };
	// 球と上縦線の衝突
	if (SphereToLine(sphere, line)) {
		return true;
	}
	line = { box.x - box.sizeX / 2,box.y + box.sizeY / 2,
		box.x + box.sizeX / 2,box.y + box.sizeY / 2, };
	// 球と下縦線の衝突
	if (SphereToLine(sphere, line)) {
		return true;
	}
	return false;
}

//const bool& Collision::BoxToBox(const Box& boxA, const Box& boxB) {
//	return false;
//}
