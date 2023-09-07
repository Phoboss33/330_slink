#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    int charCount = 0;
    int wordCount = 0;
    int stringCount = 0;
    int c = 0;

    int isWord = 0;
    int lExist = 0;
    int wExist = 0;
    int cExist = 0;

    if (argc < 2) {
        file = stdin;
    }
    else {
        file = fopen(argv[1], "r");
        if (file == NULL) {
            printf("Файл не найден");
            return 0;
        }
    }

    while ((c = fgetc(file)) != EOF) {
        if (argc == 2) {
            lExist = 1;
            cExist = 1;
            wExist = 1;

            if (c == '\n') {
                stringCount++;
            }


            if (c < 33) {
                isWord = 0;
            }
            else if (!isWord) {
                isWord = 1;
                wordCount++;
            }
                charCount++;
        }
        else {
            for (int i = 2;i < argc;i++) {
                if (strcmp(argv[i], "-l") == 0){
                    lExist = 1;
                    if (c == '\n') {
                        stringCount++;
                    }
                }
                if (strcmp(argv[i], "-w") == 0){
                    wExist = 1;
                    if (c < 33) {
                        isWord = 0;
                    } else if (!isWord) {
                        isWord = 1;
                        wordCount++;

                    }
                }
                if ((strcmp(argv[i], "-c") == 0)) {
                    cExist = 1;
                    charCount++;
                }

            }
        }

    }

    if (lExist)
        printf("Строк: %d\n", stringCount);
    if (wExist)
        printf("Слов: %d\n", wordCount);
    if (cExist)
        printf("Симв: %d\n", charCount);
    if (argc == 2)
        printf("%s\n",argv[1]);

    return 0;
}
