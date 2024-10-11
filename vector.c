#include "vector.h"
#include <string.h>
#include <stdio.h>

struct Vector {
	void *data;
	size_t size;
	size_t capacity;
	size_t element_size;
};

Vector *vector_create(size_t element_size) {
	Vector *vec = (Vector *)malloc(sizeof(Vector));
	if (NULL == vec) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}

	vec->size = 0;
	vec->capacity = 4;
	vec->element_size = element_size;
	vec->data = (void *)malloc(vec->capacity * element_size);

	if (NULL == vec->data) {
		fprintf(stderr, "Memory allocation failed\n");
		return NULL;
	}
	
	return vec;
}

// TODO: Should improve/add error handling
static void vector_resize(Vector *vec) {
	vec->capacity *= 2;
	vec->data = realloc(vec->data, vec->capacity * vec->element_size);
	if (NULL == vec->data) {
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
}

void vector_append(Vector *vec, const void *element) {
	if (vec->size >= vec->capacity) {
		vector_resize(vec);
	}
	memcpy((char *)vec->data + (vec->size * vec->element_size), element, vec->element_size);
	vec->size++;
}

void vector_insert(Vector *vec, const void *element, size_t index) {
	if (index > vec->size) {
		fprintf(stderr, "Index out of bounds\n");
		return;
	}

	if (vec->size >= vec->capacity) {
		vector_resize(vec);
	}

	memmove((char *)vec->data + ((index + 1) * vec->element_size),
		(char *)vec->data + (index * vec->element_size),
		(vec->size - index) * vec->element_size);

	memcpy((char *)vec->data + (index * vec->element_size), element, vec->element_size);
	vec->size++;
}

void *vector_at(Vector *vec, size_t index) {
	if (index < vec->size) {
		return (char *)vec->data + (index * vec->element_size);
	}
	return NULL;
}

size_t vector_size(Vector *vec) {
	return vec->size;
}

void vector_free(Vector *vec) {
	free(vec->data);
	free(vec);
}
