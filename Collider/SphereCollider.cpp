#include "SphereCollider.h"

#include <DxLib.h>

SphereCollider::SphereCollider(const int& radius) {
	this->radius = radius;
	shapeType = COLLISIONSHAPE_SPHERE;
}

inline void SphereCollider::Draw() {
	DrawCircle(position.x, position.y, radius, 
		GetColor(0xff, 0xff, 0xff), false);
}
