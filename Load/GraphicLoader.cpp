#include "GraphicLoader.h"
#include <assert.h>
#include <DxLib.h>

GraphicLoader* GraphicLoader::GetInstance() {
	// インスタンスを宣言
	static GraphicLoader instance;
	return &instance;
}

void GraphicLoader::Finalize() {
	for (auto& num : graphArraiyHandles) {
		free(num.second);
	}
	Clear();
}

const int& GraphicLoader::GetGraphHandle(const wchar_t* graphName) {
	if (!graphHandles[graphName]) {
		assert(0);
	}
	return graphHandles[graphName];
}

void GraphicLoader::GetDivGraphHandle(const wchar_t* graphName, int* array, const unsigned int& arrayNum) {
	if (!this->graphArraiyHandles[graphName]) {
		assert(0);
	}
	// 
	for (int i = 0; i < arrayNum; i++) {
		array[i] = this->graphArraiyHandles[graphName][i];
	}
}

void GraphicLoader::LoadGraphHandle(const wchar_t* graphName) {
	if (!graphHandles[graphName]) {
		graphHandles[graphName] = LoadGraph(graphName);
	}
}

void GraphicLoader::SetDivGraphHandle(const wchar_t* graphName, const unsigned int& allNum, const unsigned int& XNum,
	const unsigned int& YNum, const unsigned int& XSize, const unsigned int& YSize) {
	if (!graphArraiyHandles[graphName]) {
		graphArraiyHandles[graphName] = (int*)malloc(sizeof(int) * allNum);
		LoadDivGraph(graphName, allNum,
			XNum, YNum, XSize, YSize, graphArraiyHandles[graphName]);
	}
}

void GraphicLoader::Clear() {
	graphHandles.clear();
	graphArraiyHandles.clear();
}


