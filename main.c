#include <stdio.h>
#include <stdlib.h>
struct Box {
    int a;
    char str[255];
    float b;
};

int main(int argc, char **argv) {
    struct Box pack;
    FILE *file = fopen(argv[1], "rb"); 
    
    if (file == NULL) {                 /* check if a file exists */
        printf("File not found \n\n");
        return 0;
    }
    while (fread(&pack, sizeof(struct Box), 1, file)) {
        printf("%d %s %f\n", pack.a, pack.str, pack.b);
    }
    fseek(file, 0, SEEK_SET);   /* go to the end of file */
    fseek(file, 0, SEEK_END);   /* get the size in byte */
    long size = ftell(file);
    
    printf("\n\n File size: %ld bytes\n", size);
    fclose(file);
    return 0;
}
