// (C) 2023 Token Studios
#pragma once

/** @brief Vector struct */
typedef struct {
    int size;
    int offset;
    void **ptr;
} Vec;

/**
 * @brief Create a new vector
 * @param element_size Size of each element
 * @return Pointer to the new vector
 */
Vec *new_vec(int element_size);

/**
 * @brief Get an element from a vector
 * @param vec Vector to get from
 * @param index Index of element to get
 * @return Pointer to the element
 */
void *vec_gets(const Vec *vec, int index);

/**
 * @brief Put an element into a vector
 * @param vec Vector to put into
 * @param ptr Pointer to the element to put
 * @return Pointer to the element
 */
void *vec_puts(Vec *vec, const void *ptr);

/**
 * @brief Delete an element from a vector
 * @param vec Vector to delete from
 * @param index Index of element to delete
 */
void vec_delete(Vec *vec, int index);