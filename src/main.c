#include <stdio.h>
#include <stdbool.h>

#include "raylib.h"

#include "project.h"
#include "sprite.h"
#include "asset.h"
#include "vector_extra.h"

#define OK  0
#define ERR 1


int main() {

  // @NOTE(gr3yknigh1): Project initialization
  const ProjectConfiguration config = {
    .windowTitle  = "C Raylib Platformer",
    .windowSize   = {
      .x = 800,
      .y = 600,
    },
    .targetFPS    = 60,
    .clearColor   = WHITE,
    .isFullscreen = true,

    .physics = {
      .gravityForce     = 500,
      .gravityDirection = { 0, 1 }
    },
  };

  InitWindow(
    config.windowSize.x,
    config.windowSize.y,
    config.windowTitle
    );
  SetTargetFPS(config.targetFPS);
  SetWindowState(FLAG_WINDOW_MAXIMIZED);

  if (config.isFullscreen) {
    ToggleFullscreenC(config);
  }

  TraceLog(LOG_INFO, "Project initialized successfully");

  const Vector2 windowCenter = GetWindowCenter(config);


  // @NOTE(gr3yknigh1): Scene initialization
  SpritePool spritePool = InitSpritePool(2);
  Texture sdudeTexture = LoadTextureAsset("sprites/sdude.png");
  int sdudeSpeed = 800;
  Sprite sdudeSprite = CreateSpriteT(windowCenter, &sdudeTexture, 0);
  AddSprite2Pool(
    &spritePool,
    sdudeSprite
    );


  // @NOTE(gr3yknigh1): Game loop
  while (!WindowShouldClose()) {
    float ft = GetFrameTime();

    // @NOTE(gr3yknigh1) Input Handling
    if (IsKeyDown(KEY_RIGHT)) {
      sdudeSprite.position.x += sdudeSpeed * ft;
    } else if (IsKeyDown(KEY_LEFT)) {
      sdudeSprite.position.x -= sdudeSpeed * ft;
    }


    // @NOTE(gr3yknigh1): Apply physics
    sdudeSprite.position = AddVector2(
      sdudeSprite.position,
      ScaleVector2(
        config.physics.gravityDirection,
        config.physics.gravityForce * ft
        )
      );


    // @NOTE(gr3yknigh1): Rendering
    BeginDrawing();
      ClearBackground(config.clearColor);
      DrawSprite(sdudeSprite);
      // DrawTexture(*sdudeSprite.texture, sdudeSprite.position.x, sdudeSprite.position.y, WHITE);
      // DrawSpritePool(&spritePool);
    EndDrawing();
  }

  CloseWindow();

  return OK;
}
