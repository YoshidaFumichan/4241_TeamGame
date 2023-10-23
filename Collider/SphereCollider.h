#pragma once
#include "BaseCollider.h"

/// <summary>
/// ‹…ƒRƒ‰ƒCƒ_[
/// </summary>
class SphereCollider :
	public BaseCollider {
public: // ƒƒ“ƒoŠÖ”
	/// <summary>
	/// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	/// </summary>
	/// <param name="radius">”¼Œa</param>
	SphereCollider(const int& radius);

	/// <summary>
	/// •`‰æˆ—
	/// </summary>
	inline void Draw() override;

	/// <summary>
	/// ”¼Œa‚ğæ“¾
	/// </summary>
	/// <returns>”¼Œa</returns>
	inline const int& GetRadius() { return radius; }

	/// <summary>
	/// ”¼Œa‚ğİ’è
	/// </summary>
	/// <param name="radius">”¼Œa</param>
	inline void SetRadius(const int& radius) { this->radius = radius; }

private: // ƒƒ“ƒo•Ï”
	// ”¼Œa
	int radius;
};

