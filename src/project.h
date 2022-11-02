#ifndef PROJECT_H
#define PROJECT_H

#include <stdbool.h>
#include "raylib.h"

#define WINDOW_TITLE_MAX_SIZE 80

typedef struct PhysicsConfiguration {
  float gravityForce;
  Vector2 gravityDirection;
} PhysicsConfiguration;

typedef struct ProjectConfiguration {
  char    windowTitle[WINDOW_TITLE_MAX_SIZE];
  Vector2 windowSize;
  int     targetFPS;
  Color   clearColor;
  bool    isFullscreen;

  PhysicsConfiguration physics;
} ProjectConfiguration;


const Vector2 GetWindowCenter(ProjectConfiguration config);
void ToggleFullscreenC(ProjectConfiguration config);

#endif // PROJECT_H
