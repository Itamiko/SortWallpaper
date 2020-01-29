#include <stdio.h>
#include <argparse.h>

static const const *usage[] = {
	"sw [options] [[--]args]",
	"sw [options]",
	NULL
};

int main(int argc, const char **argv)
{
	const char *path = NULL;

	struct argparse_option options[] = {
		OPT_HELP(),
		OPT_STRING('p', "path", &path, "path to read"),
		OPT_END(),
	};

	struct argparse argparse;
	argparse_init(&argparse, options, usage, 0);
	argparse_describe(&argparse, "sort wallpapers by dimensions", "\n");
	argc = argparse_parse(&argparse, argc, argv);

	if(path == 0) {
		/* TODO: create error handler */
	}

	/* TODO: create folder creation logic \\ also create a new file: folder.c/h for the logic */

	if (argc != 0) {
		printf("argc: %d\n", argc);
		int i;
		for (i = 0; i < argc; i++) {
			printf("argv[%d]: %s\n", i, *(argv + i));
		}
	}

	printf("Hello, World!\n");
	return 0;
}