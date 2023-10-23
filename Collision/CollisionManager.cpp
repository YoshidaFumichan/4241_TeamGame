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

	// �S�Ă̑g�ݍ��킹�ɂ��đ�����`�F�b�N
	itA = colliders.begin();
	for (; itA != colliders.end(); ++itA) {
		itB = itA;
		++itB;
		for (; itB != colliders.end(); ++itB) {
			BaseCollider* colA = *itA;
			BaseCollider* colB = *itB;
			// �Ƃ��ɋ�
			if (colA->GetShapeType() == COLLISIONSHAPE_SPHERE &&
				colB->GetShapeType() == COLLISIONSHAPE_SPHERE) {
				Sphere* SphereA = new Sphere((SphereCollider*)colA);
				Sphere* SphereB = new Sphere((SphereCollider*)colB);
				if (Collision::SphereToSphere(*SphereA, *SphereB)) {
					colA->OnCollision(colB);
					colB->OnCollision(colA);
				}
			}
			// ���Ǝl�p
			else if (colA->GetShapeType() == COLLISIONSHAPE_SPHERE &&
				colB->GetShapeType() == COLLISIONSHAPE_BOX) {
				Sphere* sphere = new Sphere((SphereCollider*)colA);
				Box* box = new Box((BoxCollider*)colB);
				if (Collision::SphereToBox(*sphere, *box)) {
					colA->OnCollision(colB);
					colB->OnCollision(colA);
				}
			}
			// �l�p�Ƌ�
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