#ifndef TWO_CRYSTAL_BALLS_H
#define TWO_CRYSTAL_BALLS_H

#include <stdbool.h>
#include <stddef.h>

// Given an array of booleans representing floors where true means the ball breaks,
// find the first index where the ball breaks. You have exactly 2 balls.
// Returns the index of the first breaking point, or -1 if no breaking point exists.
int two_crystal_balls(const bool *breaks, size_t len);

#endif // TWO_CRYSTAL_BALLS_H
