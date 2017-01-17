//
// Created by Sanhu Li on 12/10/16.
//

#include <cstdio>
#include <random>
#include <cstring>
#include "dump.h"

class DumpException{};

class QueryTooLongException: public DumpException{};

static std::random_device rd;

void fill_random_sequence(char *buf, array_size len) {
    using namespace std;
    for (int i = 0; i < len; ++i) {
        buf[i] = acc_alphabet[rd() % ACCSEQ_ALPHABET_SIZE];
    }
}

void mutate(char *buf, array_size len, int num) {
    for (int i = 0; i < num; ++i) {
        buf[rd() % len] = acc_alphabet[rd() % ACCSEQ_ALPHABET_SIZE];
    }
}

void dump_substr(char *buf, const char *src, array_size start, int copy_len) {
//    sprintf(buf, "%*s", copy_len, src + start);
    for (int i = 0; i < copy_len; ++i) {
        buf[i] = src[start + i];
    }
}

void qualities(char *buf, int len) {
//    char q_begin = '!';
//    char q_end = '~';
    char q_min = 'a';
    char q_max = 'z';
    for (int i = 0; i < len; ++i) {
        buf[i] = (char) (rd() % (q_max - q_min + 1)) + 'a';
    }
}

void
random_query_file(const char *seq, array_size s_len, int q_len, int num_mutations,
                  const char *out_file_name, int num_queries, int num_family, const int sid) {
    if (s_len < q_len) {
        throw new QueryTooLongException();
    }
    const array_size st_pos_max = s_len - q_len + 1;
    array_size starts[num_family];
    for (int i = 0; i < num_family; ++i) {
        starts[i] = rd() % st_pos_max;
    }

    char *query = new char[q_len + 1];
    char *buf = new char[q_len + 1];
    char res[100], res2[100];
    int qid = 0;
    sprintf(res, "%s.res", out_file_name);
    sprintf(res2, "%s.old.res", out_file_name);
    FILE *out = fopen(out_file_name, "w");
    FILE *res_out = fopen(res, "w");
    FILE *res2_out = fopen(res2, "w");
    for (int i = 0; i < num_family; ++i) {
        dump_substr(query, seq, starts[i], q_len);
        fprintf(out, "@%d:0\n%s\n", i, query);
        fprintf(res2_out, "@%d:0\n%ld\n", i, starts[i]);
		fprintf(res_out, "* %d %d\n%ld\n", sid, qid++, starts[i]);
        qualities(buf, q_len);
        buf[q_len] = 0;
        fprintf(out, "+\n%s\n", buf);
        for (int j = 0; j < num_queries - 1; ++j) {
            strcpy(buf, query);
            mutate(buf, q_len, num_mutations);
            fprintf(out, "@%d:%d\n%s\n", i, j + 1, buf);
            qualities(buf, q_len);
            buf[q_len] = 0;
            fprintf(out, "+\n%s\n", buf);
			fprintf(res_out, "* %d %d\n%ld\n", sid, qid++, starts[i]);
        }
    }
    delete[] query;
    delete[] buf;
	fflush(out);
	fflush(res_out);
	fflush(res2_out);
    fclose(out);
    fclose(res_out);
    fclose(res2_out);
}

char *
random_sequence_file(array_size s_len, array_size s_num, const char *out_file_name, int &seq_id) {
    FILE *out = fopen(out_file_name, "w");
    int sid = 0;
    char *seq = new char[s_len + 1];
//    char *res = new char[s_len + 1];
    for (array_size i = 0; i < s_num; ++i, ++sid) {
        fill_random_sequence(seq, s_len);
        seq[s_len] = 0;
        fprintf(out, ">%ld\n", i);
        fprintf(out, seq);
        fprintf(out, "\n");
    }
    fclose(out);
//    strcpy(res, seq);
    seq_id = sid - 1;
    return seq;
}
