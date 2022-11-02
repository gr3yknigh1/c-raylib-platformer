#ifndef VECTOR_EXTRA_H
#define VECTOR_EXTRA_H

#include "raylib.h"

Vector2 OppositeVector2(Vector2 v);

Vector2 AddVector2(Vector2 v1, Vector2 v2);
Vector2 SubtractVector2(Vector2 v1, Vector2 vector2);
Vector2 ScaleVector2(Vector2 v, float scalar);

const Vector2 Vector2Half(Vector2 v);

Vector2 CenterTexture2D(Vector2 windowSize, Texture2D texture);

#endif // VECTOR_EXTRA_H
