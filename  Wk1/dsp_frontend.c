#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE        0
#define FALSE       1
#define OUTPUT_FILENAME_DEFAULT ("output.wav")

int main(int argc, char* argv[]) {
    /* Parse command line (skip executable name) */
    argc--;
    argv++;

    char *input_file;
    char *output_file;

    if (argc == 0)
    {
    /* Print usage information */
    printf("Usage: dsp_frontend -i <input_filename> -o <output_filename>\n");
    }

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-i") == TRUE) {
            input_file = malloc(strlen(argv[i + 1] + 1) * sizeof(char));
            strcpy(input_file, argv[i + 1]); 
        } else if ((strcmp(argv[i], "-o") == TRUE)) {
            output_file = malloc(strlen(argv[i + 1] + 1) * sizeof(char));
            strcpy(output_file, argv[i + 1]);
        }
    }

    if (strlen(output_file) == 0 ){
        output_file = malloc(strlen(OUTPUT_FILENAME_DEFAULT) * sizeof(char));
        strcpy(output_file, OUTPUT_FILENAME_DEFAULT);
    }

    printf("input filename: %s\n", input_file);
    printf("output filename: %s\n", output_file);

    return 0;
}