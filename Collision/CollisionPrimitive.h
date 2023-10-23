#pragma once

class SphereCollider;
class BoxCollider;


/// <summary>
/// 球
/// </summary>
struct Sphere {
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="sphere">コライダー</param>
	Sphere(SphereCollider* sphere);

	int x;	// X座標
	int y;	// Y座標
	int r;	// 半径
};


/// <summary>
/// 線
/// </summary>
struct Line {
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Line(const int& s_x, const int& s_y,
		const int& e_x, const int& e_y);

	int s_x;	// 始点X
	int s_y;	// 始点Y
	int e_x;	// 終点X
	int e_y;	// 終点Y
};

/// <summary>
/// 四角
/// </summary>
struct Box {
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="sphere"></param>
	Box(BoxCollider* box);

	int x;		// X座標
	int y;		// Y座標
	int sizeX;	// 横幅
	int sizeY;	// 縦幅
};