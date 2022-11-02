#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"


typedef struct Sprite {
  Vector2   position;
  Texture2D* texture;
  int layerId;
} Sprite;


typedef struct SpritePool {
  Sprite* sprites;
  int count;
  int capacity;
} SpritePool;


const SpritePool InitSpritePool(int capacity);

const Sprite CreateSprite(Vector2 position, char* textureAssetPath, int layerId);
const Sprite CreateSpriteT(Vector2 position, Texture2D* texture, int layerId);


const int AddSprite2Pool(SpritePool* spritePool, Sprite sprite);
const int AddSprite2PoolC(
  SpritePool* spritePool, Vector2 position, Texture2D* texture, int layerId);
const int AddSprite2PoolCA(
  SpritePool* spritePool, Vector2 position, char* textureAssetPath, int layerId);


const Sprite GetSpriteFromPool(SpritePool* spritePool, int index);

void DrawSprite(Sprite sprite);
void DrawSpritePool(SpritePool* spritePool);

#endif // SPRITE_H
