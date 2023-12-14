// (C) 2023 Token Studios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vec.h>

Vec *new_vec(const int element_size) {
    Vec *vec = malloc(sizeof(vec));
    vec->size = 0;
    vec->offset = element_size;
    return vec;
}

void *vec_gets(const Vec *vec, const int index) {
    return vec->ptr[index];
}

void *vec_puts(Vec *vec, const void *ptr) {
    vec->ptr = realloc(vec->ptr, (vec->size + 1) * sizeof(void*));
    vec->ptr[vec->size] = malloc(vec->offset);
    memmove(vec->ptr[vec->size], ptr, vec->offset);
    vec->size++;
    return vec->ptr[vec->size-1];
}

void vec_delete(Vec *vec, const int index) {
    void **newvec = malloc(sizeof(void*) * (vec->size - 1));
    int ct = 0;
    for (int i = 0; i < vec->size; i++) {
        if (i == index) {
            free(vec->ptr[i]);
            continue;
        }
        newvec[ct] = vec->ptr[i];
        ct++;
    }
    free(vec->ptr);
    vec->ptr = newvec;
    vec->size--;
}