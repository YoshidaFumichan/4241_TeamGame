#include "DxLib_Framework.h"

/// <summary>
///  WindowsAPI�̃|�C���^
/// </summary>
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	// �t���[�����[�N��錾
	DxLib_Framework::GetInstance()->Run();
	return 0;
}