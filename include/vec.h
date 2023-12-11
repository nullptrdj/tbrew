// (C) 2023 Token Studios
#pragma once

typedef struct {
    int size;
    int offset;

    void **ptr;
} Vec;

Vec *new_vec(int element_size);
void *vec_gets(const Vec *vec, int index);
void *vec_puts(Vec *vec, const void *ptr);
void vec_delete(Vec *vec, int index);