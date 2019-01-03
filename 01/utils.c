#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void *checked_malloc(size_t len) {
    void *p = malloc(len);
    if (!p) {
        fprintf(stderr,"\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

string String(char *source) {
    string new_string = checked_malloc(strlen(source)+1);
    strcpy(new_string, source);
    return new_string;
}

U_boolList U_BoolList(bool head, U_boolList tail) { 
    U_boolList list = checked_malloc(sizeof(*list));
    list->head = head;
    list->tail = tail;
    return list;
}