#ifndef ASSET_H
#define ASSET_H

#include "raylib.h"

char* GetAssetDirPath();
char* GetAssetFullPath(char* assetFullPath, const char* assetPath);

Texture2D LoadTextureAsset(char* assetPath);
Image     LoadImageAsset  (char* assetPath);

void UnloadTextureAssets();

void UnloadAssets();

#endif
