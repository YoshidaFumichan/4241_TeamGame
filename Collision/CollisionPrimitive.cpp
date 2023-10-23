#include "CollisionPrimitive.h"
#include "SphereCollider.h"
#include "BoxCollider.h"

Sphere::Sphere(SphereCollider* sphere) {
	// À•W‚ðÝ’è
	this->x = sphere->GetPosition().x;
	this->y = sphere->GetPosition().y;
	// ”¼Œa
	this->r = sphere->GetRadius();
}

Line::Line(const int& s_x, const int& s_y,
	const int& e_x, const int& e_y) {
	this->s_x = s_x;
	this->s_y = s_y;
	this->e_x = e_x;
	this->e_y = e_y;
}

Box::Box(BoxCollider* box) {
	this->x = box->GetPosition().x;
	this->y = box->GetPosition().y;
	this->sizeX = box->GetSizeX();
	this->sizeY = box->GetSizeY();
}
