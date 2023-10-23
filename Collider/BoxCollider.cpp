#include "BoxCollider.h"

#include <DxLib.h>
BoxCollider::BoxCollider(const int& sizeX, const int& sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	shapeType = COLLISIONSHAPE_BOX;
}

inline void BoxCollider::Draw() {
	DrawBox(position.x - sizeX / 2, position.y - sizeY / 2,
		position.x + sizeX / 2, position.y + sizeY / 2,
		GetColor(0xff, 0xff, 0xff), false);
}
