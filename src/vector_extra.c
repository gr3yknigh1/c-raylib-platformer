#include "raylib.h"


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

