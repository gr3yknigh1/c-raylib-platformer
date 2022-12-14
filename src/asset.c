#include "raylib.h"
#include "stdio.h"


char* GetAssetDirPath() {
  return ASSETS_FOLDER_PATH;
}


char* GetAssetFullPath(char* assetFullPath, const char* assetPath) {
  // @TODO(gr3yknigh1) Make join function
  sprintf(assetFullPath, "%s%s", GetAssetDirPath(), assetPath);
  return assetFullPath;
}


const Texture2D LoadTextureAsset(char* assetPath) {
  char textureFullPath[FILENAME_MAX];
  Texture2D texture = LoadTexture(
    GetAssetFullPath(textureFullPath, assetPath)
    );
  return texture;
}


Image LoadImageAsset(char* assetPath) {
  char imageFullPath[FILENAME_MAX];
  Image image = LoadImage(
    GetAssetFullPath(imageFullPath, assetPath)
    );
  return image;
}
