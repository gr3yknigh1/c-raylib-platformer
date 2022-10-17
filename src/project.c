#include "raylib.h"
#include "project.h"


const Vector2 GetWindowCenter(ProjectConfiguration config) {
  const Vector2 window_center = { config.windowSize.x / 2, config.windowSize.y / 2 };
  return window_center;
}
