#include "bred.h"

void bred_enable_raw_mode() {
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void bred_disable_raw_mode() {
	struct termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int bred_open_file(char* buf, long size, char *filepath) {
	FILE* fptr = NULL;
	//long file_size = 0;

	fptr = fopen(filepath, "r");
	if (NULL == fptr) {
		perror("fopen");
		return errno;
	}

	//fseek(fptr, 0L, SEEK_END);
	//file_size = ftell(fptr);
	//rewind(fptr);
	
	fread(buf, size - 1, 1, fptr);
	if (ferror(fptr)) {
		perror("fread");
		return errno;
	}

	if (fclose(fptr)) {
		perror("fclose");
		return errno;
	}

	return 0;
}

void bred_set_cursor(unsigned int y, unsigned int x) {
	printf("\e[%d;%dH", y, x);
	fflush(stdout);
}

void bred_get_cursor(unsigned int *y, unsigned int *x) {
	char buf[16];
	int i = 0;

	// Poll for cursor position
	printf("e\[6n");
	fflush(stdout);

	// Save respose to buffer
	for (i = 0; i < sizeof(buf) - 1; i++) {
		read(STDIN_FILENO, &buf[i], 1);
		if (buf[i] == 'R') break;
	}
	buf[i] = 0; // Ensure null-termination
	
	sscanf(buf, "\e[%d;%dR", y, x);
}

void bred_clear() {
	printf("\e[2J\e[H");
}














