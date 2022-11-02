#include "raylib.h"


Vector2 OppositeVector2(Vector2 v) {
  return (Vector2) {
    .x = -1 * v.x,
    .y = -1 * v.y,
  };
}


Vector2 AddVector2(Vector2 v1, Vector2 v2) {
  return (Vector2){
    .x = v1.x + v2.x,
    .y = v1.y + v2.y,
  };
}


Vector2 SubtractVector2(Vector2 v1, Vector2 v2) {
  return AddVector2(v1, OppositeVector2(v2));
}


Vector2 ScaleVector2(Vector2 v, float scalar) {
  return (Vector2){
    .x = v.x * scalar,
    .y = v.y * scalar,
  };
}


const Vector2 Vector2Half(Vector2 v) {
  return (Vector2){
    .x = v.x / 2,
    .y = v.y / 2,
  };
}


Vector2 CenterTexture2D(Vector2 windowSize, Texture2D texture) {
  return SubtractVector2(
    Vector2Half(windowSize),
    Vector2Half((Vector2){ texture.width, texture.height })
  );
}

