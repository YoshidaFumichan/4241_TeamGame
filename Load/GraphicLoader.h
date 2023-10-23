#pragma once
#include <map>
#include <string>

/// <summary>
/// 画像読み込みクラス
/// </summary>
class GraphicLoader {
public: // 静的メンバ関数
	/// <summary>
	/// インスタンスを取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static GraphicLoader* GetInstance();

private:
	GraphicLoader() = default;
	GraphicLoader(const GraphicLoader&) = delete;
	~GraphicLoader() = default;
	GraphicLoader& operator=(const GraphicLoader&) = delete;

public: // メンバ関数
	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// グラフィックハンドルを取得
	/// </summary>
	/// <param name="graphName">グラフィックネーム</param>
	/// <returns>グラフィックナンバー</returns>
	const int& GetGraphHandle(const wchar_t* graphName);

	/// <summary>
	/// 連番画像のグラフィックハンドルを取得
	/// </summary>
	/// <param name="graphName">グラフィックネーム</param>
	/// <param name="graphHandleArray">取得する変数</param>
	/// <param name="arrayNum">要素数</param>
	void GetDivGraphHandle(const wchar_t* graphName, int* graphHandleArray, const unsigned int& arrayNum);

	/// <summary>
	/// グラフィックハンドルを設定
	/// </summary>
	/// <param name="graphName">グラフィックネーム</param>
	void LoadGraphHandle(const wchar_t* graphName);

	/// <summary>
	/// 連番画像のグラフィックハンドルを設定
	/// </summary>
	/// <param name="graphName">グラフィックネーム</param>
	/// <param name="allNum">要素数</param>
	/// <param name="XNum">横の要素数</param>
	/// <param name="YNum">縦の要素数</param>
	/// <param name="XSize">切り取りたい横幅</param>
	/// <param name="YSize">切り取りたい縦幅</param>
	void SetDivGraphHandle(const wchar_t* graphName, const unsigned int& allNum, const unsigned int& XNum,
		const unsigned int& YNum, const unsigned int& XSize, const unsigned int& YSize);

	/// <summary>
	/// 全削除
	/// </summary>
	void Clear();

private: // メンバ変数
	// 読み込んだ画像の連想配列
	std::map<const wchar_t*, int> graphHandles;
	std::map<const wchar_t*, int*> graphArraiyHandles;

};