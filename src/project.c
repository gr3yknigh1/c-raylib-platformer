#include "raylib.h"
#include "project.h"


const Vector2 GetWindowCenter(ProjectConfiguration config) {
  const Vector2 window_center = { config.windowSize.x / 2, config.windowSize.y / 2 };
  return window_center;
}


void ToggleFullscreenC(ProjectConfiguration config) {
  if (IsWindowFullscreen()) {
    SetWindowSize(
      config.windowSize.x,
      config.windowSize.y
      );
    ToggleFullscreen();
  } else {
    int monitor = GetCurrentMonitor();
    SetWindowSize(
      GetMonitorWidth(monitor),
      GetMonitorHeight(monitor)
      );

    ToggleFullscreen();
  }
}

