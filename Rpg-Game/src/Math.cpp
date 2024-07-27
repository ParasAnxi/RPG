#include "Math.h"

Vector2f Math::NormalizeVector(Vector2f vec) {

    float magnitude = sqrt(vec.x * vec.x + vec.y * vec.y);
    Vector2f normalizedVec;
    normalizedVec.x = vec.x / magnitude;
    normalizedVec.y = vec.y / magnitude;
    return normalizedVec;

}

bool Math::CheckRectCollision(FloatRect rect1, FloatRect rect2)
{
    if (rect1.left + rect1.width > rect2.left &&
        rect2.left + rect1.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.top + rect1.height > rect2.top) {
        return true;
    }
    return false;
}
