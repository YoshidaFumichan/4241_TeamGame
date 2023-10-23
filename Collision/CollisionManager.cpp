#include "CollisionManager.h"

#include "Collision.h"
#include "CollisionPrimitive.h"
#include "assert.h"

CollisionManager* CollisionManager::GetInstance() {
	static CollisionManager instance;
	return &instance;
}

void CollisionManager::CheckAllCollisions() {
	std::forward_list<BaseCollider*>::iterator itA;
	std::forward_list<BaseCollider*>::iterator itB;

	// 全ての組み合わせについて総当りチェック
	itA = colliders.begin();
	for (; itA != colliders.end(); ++itA) {
		itB = itA;
		++itB;
		for (; itB != colliders.end(); ++itB) {
			BaseCollider* colA = *itA;
			BaseCollider* colB = *itB;
			// ともに球
			if (colA->GetShapeType() == COLLISIONSHAPE_SPHERE &&
				colB->GetShapeType() == COLLISIONSHAPE_SPHERE) {
				Sphere* SphereA = new Sphere((SphereCollider*)colA);
				Sphere* SphereB = new Sphere((SphereCollider*)colB);
				if (Collision::SphereToSphere(*SphereA, *SphereB)) {
					colA->OnCollision(colB);
					colB->OnCollision(colA);
				}
			}
			// 球と四角
			else if (colA->GetShapeType() == COLLISIONSHAPE_SPHERE &&
				colB->GetShapeType() == COLLISIONSHAPE_BOX) {
				Sphere* sphere = new Sphere((SphereCollider*)colA);
				Box* box = new Box((BoxCollider*)colB);
				if (Collision::SphereToBox(*sphere, *box)) {
					colA->OnCollision(colB);
					colB->OnCollision(colA);
				}
			}
			// 四角と球
			else if (colA->GetShapeType() == COLLISIONSHAPE_BOX &&
				colB->GetShapeType() == COLLISIONSHAPE_SPHERE) {
				Box* box = new Box((BoxCollider*)colA);
				Sphere* sphere = new Sphere((SphereCollider*)colB);
				if (Collision::SphereToBox(*sphere, *box)) {
					colA->OnCollision(colB);
					colB->OnCollision(colA);
				}
			}
		}
	}
}