//
// Created by Sanhu Li on 11/08/16.
//

#ifndef ACCSEQ_GLOBAL_H
#define ACCSEQ_GLOBAL_H

typedef long array_size;
#define ACCSEQ_ALPHABET_SIZE 4
typedef char acc_ch_type;

#include <vector>

extern const acc_ch_type * acc_alphabet;
extern const acc_ch_type * acc_full_alphabet;

int get_ch_pos(acc_ch_type c);

long get_filesize(const char *file_name);

void *read_file(const char *file_name, array_size file_size);

void release_file(void *map_ptr, array_size file_size);

char *substr(const char *src, array_size start, array_size len);

#endif //ACCSEQ_GLOBAL_H
