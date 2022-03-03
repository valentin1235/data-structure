#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "radixsort.h"

int compare_sort_key(const void* v1, const void* v2) {
    const short* i1 = v1;
    const short* i2 = v2;

    return *i1 - *i2;
}

void radix_sort_test(void)
{
    student_t students[7];
    int i;

    students[0].age = 22;
    students[0].grade = 1;
    strncpy(students[0].name, "peter", 10);

    students[1].age = 22;
    students[1].grade = 3;
    strncpy(students[1].name, "heechul", 10);

    students[2].age = 25;
    students[2].grade = 3;
    strncpy(students[2].name, "alex", 10);

    students[3].age = 21;
    students[3].grade = 2;
    strncpy(students[3].name, "corden", 10);

    students[4].age = 26;
    students[4].grade = 4;
    strncpy(students[4].name, "kane", 10);

    students[5].age = 24;
    students[5].grade = 4;
    strncpy(students[5].name, "ana", 10);

    students[6].age = 27;
    students[6].grade = 5;
    strncpy(students[6].name, "salah", 10);

    for (i = 0; i < 7; ++i) {
        const unsigned char age = students[i].age;
        const unsigned char grade = students[i].grade;
        students[i].sort_key = age << 8 | grade; /* 비트연산을 통해 radix sort key를 할당 */
    }

    qsort(students, 7, sizeof(student_t), compare_sort_key); /* sort_key를 기준으로 qsort */

    assert(strcmp(students[0].name, "corden") == 0);
    assert(strcmp(students[1].name, "peter") == 0);
    assert(strcmp(students[2].name, "heechul") == 0);
    assert(strcmp(students[3].name, "ana") == 0);
    assert(strcmp(students[4].name, "alex") == 0);
    assert(strcmp(students[5].name, "kane") == 0);
    assert(strcmp(students[6].name, "salah") == 0);
}
