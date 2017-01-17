//
// Created by Sanhu Li on 12/10/16.
//

#ifndef ACCSEQ_DUMP_H
#define ACCSEQ_DUMP_H

#include "global.h"


char *
random_sequence_file(array_size s_len, array_size s_num, const char *out_file_name, int &seq_id);
void random_query_file(const char *seq, array_size s_len, int q_len, int num_mutations,
					   const char *out_file_name, int num_queries, int num_family, const int sid);


#endif //ACCSEQ_DUMP_H
