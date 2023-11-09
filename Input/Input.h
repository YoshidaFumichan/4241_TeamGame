#pragma once

/// <summary>
/// 入力クラス
/// </summary>
class Input
{
public: // 静的メンバ関数
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static Input* GetInstance();

private: // メンバ関数
	Input() = default;
	Input(const Input&) = delete;
	~Input() = default;
	Input& operator=(const Input&) = delete;

public: // メンバ関数
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 入力情報を取得
	/// 例：GetKey(KEYS_INPUT_SPACE)(スペースキー入力情報取得)
	/// </summary>
	/// <param name="num">キーナンバー</param>
	/// <returns>入力情報</returns>
	inline const char& GetKey(short num) { return keys[num]; }

	/// <summary>
	/// 1フレーム前の入力情報を取得
	/// 例：GetOldKey(KEYS_INPUT_SPACE)(1フレーム前のスペースキー入力情報取得)
	/// </summary>
	/// <param name="num">キーナンバー</param>
	/// <returns>1フレーム前の入力情報</returns>
	inline const char& GetOldKey(short num) { return oldkeys[num]; }

private: // メンバ変数
	// キーボード
	char keys[256];
	// 1フレーム前のキー入力
	char oldkeys[256];
};