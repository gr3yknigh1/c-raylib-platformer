#include "raylib.h"
#include "sprite.h"
#include "asset.h"


const SpritePool InitSpritePool(int capacity) {
  const SpritePool spritePool = {
    .sprites  = MemAlloc(capacity * sizeof(Sprite)),
    .count    = 0,
    .capacity = capacity,
  };
  return spritePool;
}


const Sprite CreateSprite(Vector2 position, char* textureAssetPath, int layerId) {
  return CreateSpriteT(
    position,
    LoadTextureAsset(textureAssetPath),
    layerId
    );
}


const Sprite CreateSpriteT(Vector2 position, Texture texture, int layerId) {
  const Sprite sprite = {
    .position = {
      .x = position.x,
      .y = position.y,
    },
    .texture = texture,
  };
  return sprite;
}


const int AddSprite2Pool(SpritePool* spritePool, Sprite sprite) {
  if (spritePool->count >= spritePool->capacity) {
    return -1;
  }
  spritePool->sprites[spritePool->count] = sprite;
  spritePool->count++;
  return spritePool->count;
}


const int AddSprite2PoolC(SpritePool* spritePool, Vector2 position, Texture2D texture, int layerId) {
  return AddSprite2Pool(
    spritePool,
    CreateSpriteT(position, texture, layerId)
  );
}


const int AddSprite2PoolCA(SpritePool* spritePool, Vector2 position, char* textureAssetPath, int layerId) {
  return AddSprite2Pool(
    spritePool,
    CreateSprite(position, textureAssetPath, layerId)
  );
}


const Sprite GetSpriteFromPool(SpritePool* spritePool, int index) {
  return spritePool->sprites[index];
}


void DrawSprite(Sprite sprite) {
  DrawTextureV(sprite.texture, sprite.position, WHITE);
}


void DrawSpritePool(SpritePool* spritePool) {
  for (int i = 0; i < spritePool->count; i++) {
    DrawSprite(spritePool->sprites[i]);
  }
}

