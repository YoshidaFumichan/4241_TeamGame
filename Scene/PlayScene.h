#pragma once
#include "BaseScene.h"
#include "Notes.h"

class PlayScene :
	public BaseScene {
private: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize()override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update()override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw()override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize()override;

private: // メンバ関数
	/// <summary>
	/// 開始時カウントダウン
	/// </summary>
	void StartCountDown();

	/// <summary>
	/// ノーツの生成処理
	/// </summary>
	void CreateNotes();

private: // メンバ変数
	// 背景画像
	int BackGraph;
	// カウントスタートタイム
	int StartTime;
	// スタートカウントダウン
	short CountDown;
	// カウントダウン用画像
	int CountDownGraph[3];
	// スタートフラグ
	bool StartFlag;
	// エンドフラグ
	bool EndFlag;
	// 湯切りおじさんアニメーション
	int CutOjiAnimation;
	// 湯切りおじさん画像
	int CutOjiGraph[3];
	// ラーメンアニメーション
	int RamenAnimation;
	// ラーメン画像
	int RamenGraph[2];
	// ノーツ
	Notes* notes[5];
	// ノーツカウント
	int nowNotes = 0;
	int oldNotes = 0;
	int goodGraph;
	int missGraph;
	int life = 3;
	bool damageFlag = false;
	int score = 0;
	bool scoreFlag = false;
	int scoreHandle[10] = {};
	int scoreGraphHandle = 0;
	int endhit = 1;
	int cutNum = 0;
	int oldCutNum = 0;
	int lifeHandle = 0;
	int lifenoHandle = 0;
};