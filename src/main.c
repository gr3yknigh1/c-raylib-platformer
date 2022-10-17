#include "stdio.h"
#include "raylib.h"

#define OK  0
#define ERR 1

#define WINDOW_TITLE_MAX_SIZE 80


typedef struct ProjectConfiguration {
  char    windowTitle[WINDOW_TITLE_MAX_SIZE];
  Vector2 windowSize;
  int     targetFPS;

  Color   clearColor;
} ProjectConfiguration;


typedef struct Sprite {
  Vector2   position;
  Texture2D texture;
  int layerId;
} Sprite;


typedef struct SpritePool {
  Sprite* sprites;
  int count;
  int capacity;
} SpritePool;


const SpritePool InitSpritePool(int capacity) {
  const SpritePool spritePool = {
    .sprites  = MemAlloc(capacity * sizeof(Sprite)),
    .count    = 0,
    .capacity = capacity,
  };
  return spritePool;
}


const Vector2 GetWindowCenter(ProjectConfiguration config) {
  const Vector2 window_center = { config.windowSize.x / 2, config.windowSize.y / 2 };
  return window_center;
}


char* GetAssetDirPath() {
  return ASSETS_FOLDER_PATH;
}

char* GetAssetFullPath(char* assetFullPath, const char* assetPath) {
  // TODO(gr3yknigh1): Make join function
  sprintf(assetFullPath, "%s%s", GetAssetDirPath(), assetPath);
  return assetFullPath;
}


Texture2D LoadTextureAsset(char* assetPath) {
  char textureFullPath[FILENAME_MAX];
  Texture2D texture = LoadTexture(
    GetAssetFullPath(textureFullPath, assetPath)
    );
  return texture;
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


const Sprite CreateSprite(Vector2 position, char* textureAssetPath, int layerId) {
  return CreateSpriteT(
    position,
    LoadTextureAsset(textureAssetPath),
    layerId
    );
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


Vector2 SubtractVector2(Vector2 vector1, Vector2 vector2) {
  Vector2 newVector = {
    .x = vector1.x - vector2.x,
    .y = vector1.y - vector2.y
  };
  return newVector;
}


const Vector2 Vector2Half(Vector2 vector) {
  const Vector2 vectorHalf = { vector.x / 2, vector.y / 2 };
  return vectorHalf;
}


const Vector2 Texture2DSize(Texture2D texture) {
  const Vector2 size = { texture.width, texture.height };
  return size;
}


Vector2 CenterTexture2D(Vector2 windowSize, Texture2D texture) {
  Vector2 centered = SubtractVector2(
    Vector2Half(windowSize),
    Vector2Half(Texture2DSize(texture))
  );
  return centered;
}


int main() {

  const ProjectConfiguration config = {
    .windowTitle = "C Raylib Platformer",
    .windowSize  = {
      .x = 800,
      .y = 600,
    },
    .targetFPS   = 60,
    .clearColor  = WHITE,
  };

  const Vector2 windowSize   = config.windowSize;
  const Vector2 windowCenter = GetWindowCenter(config);

  InitWindow(
    windowSize.x,
    windowSize.y,
    config.windowTitle
    );
  SetTargetFPS(config.targetFPS);

  SpritePool spritePool = InitSpritePool(2);

  {
    const Texture texture = LoadTextureAsset("test.png");
    const Vector2 position = CenterTexture2D(windowSize, texture);
    AddSprite2PoolC(&spritePool, position, texture, 0);
  }

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(config.clearColor);
      DrawSpritePool(&spritePool);
    EndDrawing();
  }

  CloseWindow();

  return OK;
}
