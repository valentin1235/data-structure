

#ifndef RADIXSORT_H
#define RADIXSORT_H

typedef struct {
    unsigned short sort_key;
    char name[10];
    unsigned char age;
    unsigned char grade;
} student_t;

int compare_sort_key(const void* v1, const void* v2);
void radix_sort_test(void);

#endif /* RADIXSORT_H */
