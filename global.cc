#include <cstdio>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstring>
#include "global.h"

const acc_ch_type * acc_alphabet = "ACGT";
const acc_ch_type *acc_full_alphabet = "$ACGT";

int get_ch_pos(acc_ch_type c) {
    for (int i = 0; i < ACCSEQ_ALPHABET_SIZE + 1; ++i) {
        if (acc_full_alphabet[i] == c) {
            return i;
        }
    }
    return -1;
}

long get_filesize(const char *file_name) {
    FILE * f = fopen(file_name, "r");
    fseek(f, 0, SEEK_END);
    return ftell(f);
}

void *read_file(const char *file_name, array_size file_size) {
    int fd = open(file_name, O_RDONLY);
    return mmap(NULL, (size_t) file_size, PROT_READ, MAP_PRIVATE, fd, 0);
}

void release_file(void *map_ptr, array_size file_size) {
    munmap(map_ptr, (size_t) file_size);
}

char *substr(const char *src, array_size start, array_size len) {
    char *res = new char[len + 1];
    strncpy(res, src + start, (size_t) len);
    res[len] = 0;
    return res;
}
