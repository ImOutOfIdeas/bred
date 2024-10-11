#include <stdio.h>
#include <errno.h>

#include "bred.h"
#include "vector.h"

int main(int argc, char *argv[]) {
	Vector *vec = vector_create(sizeof(char));

	const char chars[] = {'h', 'e', 'l', 'l', 'o', ' ', 'o', 'r', 'l', 'd', '\n'};

	for (int i = 0; i < sizeof(chars); i++) {
		vector_append(vec, &chars[i]);
	}

	char w = 'w';

	vector_insert(vec, &w, 6);

	for (size_t i = 0; i < vector_size(vec); i++) {
		printf("%c ", *(char *)vector_at(vec, i));
	}
	printf("\n");

	return 0;

	/*
	if (argc != 2) {
		printf("BRUH");
		return 1;
	}

	char c;
	unsigned int y = 0, x = 0;

	char *buf = (char *)malloc(sizeof(char) * BUFSIZE);
	if (NULL == buf) {
		perror("malloc");
		return errno;
	}

	if (bred_open_file(buf, BUFSIZE - 1, argv[1])) {
		return errno;
	}

	bred_enable_raw_mode();

	bred_clear();
	
	printf("%s", buf);

	bred_set_cursor(y, x);
	
	while((c = getchar()) != 'q') {
		printf("%c", c);
		fflush(stdout);
	}

	bred_disable_raw_mode();

	return errno;
	*/
}
