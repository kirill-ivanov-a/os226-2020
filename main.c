#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int retCode;

int echo(int argc, char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		printf("%s%c", argv[i], i == argc - 1 ? '\n' : ' ');
	}
	return argc - 1;
}

int retcode(int argc, char* argv[]) {
	printf("%d\n", retCode);
	return 0;
}

int main(int argc, char* argv[]) {
	char input[BUFFER_SIZE];
	char* tokenBuf = NULL;
	char* argBuf = NULL;
	argv[BUFFER_SIZE];
	argc = 0;
	while (fgets(input, BUFFER_SIZE, stdin))
	{
		char* token = strtok_r(input, "\n;", &tokenBuf);
		while (token != NULL)
		{
			argc = 0;
			char* arg = strtok_r(token, " ", &argBuf);
			while (arg != NULL)
			{
				argv[argc++] = arg;
				arg = strtok_r(NULL, " ", &argBuf);
			}
			if (!strcmp(argv[0], "echo"))
				retCode = echo(argc, argv);
			else if (!strcmp(argv[0], "retcode"))
				retCode = retcode(argc, argv);
			else if (!strcmp(argv[0], "exit"))
				break;
			else
			{
				printf("%s\n", "wrong command");
				retCode = -1;
			}
			token = strtok_r(NULL, "\n;", &tokenBuf);
		}
		if (!strcmp(argv[0], "exit"))
			break;
	}
	return 0;
}
