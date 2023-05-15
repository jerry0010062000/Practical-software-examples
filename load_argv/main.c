#include <stdio.h>
#include <stdlib.h>

void showHelp() {
    printf("Program Usage:\n");
    printf("  ./program [option1] [option2] ... [optionN]\n");
    printf("\n");
    printf("Options:\n");
    printf("  -h, --help       Display this help message\n");
    printf("  -f, --file       Specify the input file\n");
    printf("  -o, --output     Specify the output file\n");
    printf("\n");
    // Add more options here as needed
}

void printFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Failed to open parameter file: %s\n", filePath);
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
    return;
}

void redirOutput(const char *filepath){
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }
    freopen("output.txt", "w", stdout);
    return;
}


int main(int argc, char *argv[]) {
    char *filePath = NULL, *outfile = NULL;
    int inputFlag = 0;
    // Check if the program was invoked with the help option
    if(argc > 1){
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                showHelp();
            }
            else if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0) {
                if(i < argc - 1 || strlen(argv[i+1]) > 0){
                    filePath = argv[i+1];
                    inputFlag = 1;
                    i++;
                    continue;
                }else{
                    showHelp();
                }
            }
            else if(strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0){
                if(i < argc - 1 || strlen(argv[i+1]) > 0){
                    outfile = argv[i]+1 ;
                    redirOutput(outfile);
                    i++;
                    continue;
                }
                else{
                    showHelp();
                }
            }
        }
    }
    
    //exec function
    if(inputFlag == 1){
        printFile(filePath);
    }else{
        printf("Here is test text!\n");
    }


    if(filePath != NULL){
        fclose(filePath);
    }
    if(outfile != NULL){
        fclose(outfile);
    }

    return 0;
}