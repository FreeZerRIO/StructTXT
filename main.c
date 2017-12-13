//
//  main.c
//  Struct
//
//  Created by Алексей Баринов on 10.12.2017.
//  Copyright © 2017 Era Company. All rights reserved.
//

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
        printf("FILE NOT FOUND \n\n");
        return 0;
    }
    while (fread(&pack, sizeof(struct Box), 1, file)) {
        printf("%d %s %f\n", pack.a, pack.str, pack.b);
    }
    fseek(file, 0, SEEK_SET);   /* go to the end of file */
    fseek(file, 0, SEEK_END);   /* get the size in byte */
    long size = ftell(file);
    
    printf("\n\n FILE SIZE IS %ld BYTES \n\n", size);
    fclose(file);
    return 0;
}
