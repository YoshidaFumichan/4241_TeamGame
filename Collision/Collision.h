#pragma once

class Sphere;
class Box;

/// <summary>
/// 衝突判定クラス
/// </summary>
class Collision {
public: // サブクラス
	struct Line {
		int s_x;	// 始点X
		int s_y;	// 始点Y
		int e_x;	// 終点X
		int e_y;	// 終点Y
	};

public: // 静的メンバ関数
	/// <summary>
	/// 球と球の衝突判定
	/// </summary>
	/// <param name="sphereA">球A</param>
	/// <param name="sphereB">球B</param>
	/// <returns>衝突してるか</returns>
	static const bool& SphereToSphere(const Sphere& sphereA, const Sphere& sphereB);

	/// <summary>
	/// 球と線の衝突判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="line">線</param>
	/// <returns>衝突してるか</returns>
	static const bool& SphereToLine(const Sphere& sphere, const Line& line);

	/// <summary>
	/// 球と四角の衝突判定
	/// </summary>
	/// <param name="sphere">球</param>
	/// <param name="box">四角</param>
	/// <returns>衝突してるか</returns>
	static const bool& SphereToBox(const Sphere& sphere, const Box& box);

	/// <summary>
	/// 四角と四角
	/// </summary>
	/// <param name="boxA">四角A</param>
	/// <param name="boxB">四角B</param>
	/// <returns>衝突してる</returns>
	//static const bool& BoxToBox(const Box& boxA, const Box& boxB);

};