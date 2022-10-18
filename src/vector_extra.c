#include "raylib.h"


Vector2 SubtractVector2(Vector2 vector1, Vector2 vector2) {
  return (Vector2) {
    .x = vector1.x - vector2.x,
    .y = vector1.y - vector2.y,
  };
}


const Vector2 Vector2Half(Vector2 vector) {
  return (Vector2){
    .x = vector.x / 2,
    .y = vector.y / 2,
  };
}


const Vector2 Texture2DSize(Texture2D texture) {
  return (Vector2) {
    .x = texture.width,
    .y = texture.height,
  };
}


Vector2 CenterTexture2D(Vector2 windowSize, Texture2D texture) {
  return SubtractVector2(
    Vector2Half(windowSize),
    Vector2Half(Texture2DSize(texture))
  );
}

