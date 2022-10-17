#ifndef PROJECT_H
#define PROJECT_H

#include "raylib.h"

#define WINDOW_TITLE_MAX_SIZE 80

typedef struct ProjectConfiguration {
  char    windowTitle[WINDOW_TITLE_MAX_SIZE];
  Vector2 windowSize;
  int     targetFPS;

  Color   clearColor;
} ProjectConfiguration;


const Vector2 GetWindowCenter(ProjectConfiguration config);

#endif // PROJECT_H
