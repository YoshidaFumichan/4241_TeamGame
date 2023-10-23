#pragma once

class BaseScene;

/// <summary>
/// シーンマネージャー
/// </summary>
class SceneManager
{
public: // 静的メンバ関数
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	static SceneManager* GetInstance();

public: // メンバ関数
	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="scene">最初のシーン</param>
	void Initialize(BaseScene* scene);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// 次のシーン設定
	/// </summary>
	/// <param name="nextScene">次のシーン</param>
	void SetNextScene(BaseScene* nextScene) { this->nextScene = nextScene; }

	/// <summary>
	/// シーン切り替え処理
	/// </summary>
	void ChangeScene();

private: // メンバ関数
	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	~SceneManager() = default;
	SceneManager& operator=(const SceneManager&) = delete;

private: // メンバ変数
	// シーン
	BaseScene* scene = nullptr;
	// ネクストシーン
	BaseScene* nextScene = nullptr;
};