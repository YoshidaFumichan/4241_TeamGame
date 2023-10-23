#include "Input.h"

#include <Dxlib.h>

Input* Input::GetInstance() {
	// �C���X�^���X��錾
	static Input instance;
	return &instance;
}

void Input::Update() {
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (short i = 0; i < 256; i++) {
		oldkeys[i] = keys[i];
	}
	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}