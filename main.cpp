#include "DxLib_Framework.h"

/// <summary>
///  WindowsAPIのポインタ
/// </summary>
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	// フレームワークを宣言
	DxLib_Framework::GetInstance()->Run();
	return 0;
}