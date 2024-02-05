#pragma once

/// <summary>
/// ノーツ一個分
/// </summary>
class Notes {
public: // 静的メンバ関数
	/// <summary>
	/// 静的初期化処理
	/// </summary>
	static void StaticInitialize();

private: // 静的メンバ変数
	// サウンドエフェクト
	static int SoundEffect;
	// キー画像のハンドル
	static int notesHandle[2];
public: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize(const int& type, const int& StartTime);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();


	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 入力情報を確認
	/// </summary>
	inline void CheckInput();

public: // メンバ変数
	// タイプ
	int type;
	int hit = 0;
	// スタートタイム
	int StartTime = 0;
	// エンドタイム
	int EndTime = 0;
	// 開始フラグ
	bool StartFlag;
	// 終了フラグ
	bool EndFlag;
	// 現在のノーツ
	bool nowNotes;
};