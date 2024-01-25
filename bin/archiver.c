#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void createArchive(const char* filename, const char** files, int numFiles) {
    FILE* archive = fopen(filename, "wb");
    if (archive == NULL) {
        printf("Error creating archive.\n");
        return;
    }

    for (int i = 0; i < numFiles; i++) {
        FILE* file = fopen(files[i], "rb");
        if (file == NULL) {
            printf("Error opening file: %s\n", files[i]);
            continue;
        }

        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        char* buffer = (char*)malloc(fileSize);
        if (buffer == NULL) {
            printf("Error allocating memory for file: %s\n", files[i]);
            fclose(file);
            continue;
        }

        fread(buffer, 1, fileSize, file);
        fclose(file);

        fwrite(&fileSize, sizeof(long), 1, archive); // Corrected fwrite call
        fwrite(buffer, 1, fileSize, archive);

        free(buffer);
    }

    fclose(archive);
}

void deleten(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {
    const int maxFiles = 128;
    const int maxFilenameLength = 128;
    char files[maxFiles][maxFilenameLength];
    strcpy(files[0], "file1.txt");
    strcpy(files[1], "file2.txt");

    int numFiles = 2;
    char archiveName[128] = "archive.tar";
    createArchive(archiveName, (const char**)files, numFiles);


    printf("Archive created: %s\n", archiveName);

    return 0;
}
