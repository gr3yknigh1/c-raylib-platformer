#ifndef VECTOR_EXTRA_H
#define VECTOR_EXTRA_H

#include "raylib.h"


Vector2 SubtractVector2(Vector2 vector1, Vector2 vector2);

const Vector2 Vector2Half(Vector2 vector);

const Vector2 Texture2DSize(Texture2D texture);
Vector2 CenterTexture2D(Vector2 windowSize, Texture2D texture);

#endif // VECTOR_EXTRA_H
