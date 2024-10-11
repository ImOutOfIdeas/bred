#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>

typedef struct Vector Vector;

Vector *vector_create(size_t element_size);

void vector_append(Vector *vec, const void *element);

void vector_insert(Vector *vec, const void *element, size_t index);

void *vector_at(Vector *vec, size_t index);

size_t vector_size(Vector *vec);

void vector_free(Vector *vec);

#endif // __VECTOR_H__
