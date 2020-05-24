#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stdlib.h>
#include <stdint.h>

void free_triangle(size_t **triangle, uint8_t length);
size_t ** create_triangle(int8_t length);

#endif
