#include "stdio.h"

#include "raylib.h"

#include "project.h"
#include "sprite.h"
#include "asset.h"
#include "vector_extra.h"

#define OK  0
#define ERR 1


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

  const Texture2D sdudeTexture = LoadTextureAsset("sprites/sdude.png");
  const Sprite sdudeSprite = CreateSpriteT(windowCenter, &sdudeTexture, 0);
  AddSprite2Pool(
    &spritePool,
    sdudeSprite
    );

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(config.clearColor);
      DrawSpritePool(&spritePool);
    EndDrawing();
  }

  CloseWindow();

  return OK;
}
