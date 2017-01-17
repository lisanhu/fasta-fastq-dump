#include <iostream>
#include "global.h"
#include "dump.h"
#include "my_time.h"

using namespace std;

/// Normal human gene length 10-15K, vary from 0.2k-2500k, we choose 2500k here
/// For a three GB gene, we have 2500k * 1.2k = 3GB
//const array_size SEQ_LEN = 2500000;
const array_size SEQ_LEN = 2500000;
const array_size SEN_NUM = 1200;
//const int NUM_QUERIES = 8240796;
const int NUM_QUERIES = 10;
const int NUM_FAMILIES = 824080;
const int QUERY_LEN = 101;
const int NUM_MUTATIONS = 5;

struct config{
    array_size s_len, s_num;
    int q_len, q_num, f_num;
    int m_num;
};

config
init_config(array_size seq_len, array_size seq_num, int query_len, int query_num, int family_num,
            int mutation_num) {
    config cfg{seq_len, seq_num, query_len, query_num, family_num, mutation_num};
    return cfg;
}

//void generate_data(const int s_id, const int q_id, config cfg) {
//    char name[100];
//    sprintf(name, "sequence-%d.fa", s_id);
//    cout << "Begin generating reference sequence file " << name << endl;
//    double begin = get_wall_time();
//    char *seq = random_sequence_file(cfg.s_len, cfg.s_num, name, <#initializer#>);
//    cout << "Done building sequence file, time elapse: " << get_wall_time() - begin << "s" << endl;
//    sprintf(name, "query-%d-%d.fa", s_id, q_id);
//    cout << "Begin generating query file " << name << endl;
//    begin = get_wall_time();
//	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, name, cfg.q_num, cfg.f_num, 0);
//    cout << "Done generating query file, time elapse: " << get_wall_time() - begin << "s" << endl;
//    delete[] seq;
//}

int pow(int b, int p) {
    int result{1};
    for (int i = 0; i < p; ++i) {
        result *= b;
    }
    return result;
}

void get_my_test() {
	config cfg{2500, 12, QUERY_LEN, 412, 2, 5};
	int sid = 0;
	const char *seq = random_sequence_file(cfg.s_len, cfg.s_num, "sequence-1.fa", sid);
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-1-1.fq", cfg.q_num, cfg.f_num, sid);
	cfg = config{2500, 12, QUERY_LEN, 4120, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-1-2.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 41200, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-1-3.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 412000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-1-4.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 4120000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-1-5.fq", cfg.q_num, cfg.f_num, sid);


	cfg = {2500, 120, QUERY_LEN, 412, 2, 5};
	sid = 0;
	seq = random_sequence_file(cfg.s_len, cfg.s_num, "sequence-2.fa", sid);
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-2-1.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 4120, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-2-2.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 41200, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-2-3.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 412000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-2-4.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 4120000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-2-5.fq", cfg.q_num, cfg.f_num, sid);

	cfg = {2500, 1200, QUERY_LEN, 412, 2, 5};
	sid = 0;
	seq = random_sequence_file(cfg.s_len, cfg.s_num, "sequence-3.fa", sid);
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-3-1.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 4120, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-3-2.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 41200, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-3-3.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 412000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-3-4.fq", cfg.q_num, cfg.f_num, sid);
	cfg = {2500, 12, QUERY_LEN, 4120000, 2, 5};
	random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, "query-3-5.fq", cfg.q_num, cfg.f_num, sid);

}

int main(int argc, char *argv[]) {
    get_my_test();
//    char name[100];
//    for (int i = 0; i < 3; ++i) {
//        sprintf(name, "sequence-%d.fa", i);
//        cout << "Begin generating reference sequence file " << name << endl;
//        double begin = get_wall_time();
//        char *seq = random_sequence_file(SEQ_LEN, SEN_NUM / pow(10, i), name);
//        cout << "Done building sequence file, time elapse: " << get_wall_time() - begin << "s"
//             << endl;
//        cout << "Sequence file name: " << name << " seq_len=" << SEQ_LEN << " seq_num="
//             << SEN_NUM / pow(10, i) << endl;
//        for (int j = 0; j < 5; ++j) {
//            config cfg{SEQ_LEN, SEN_NUM / pow(10, i), QUERY_LEN, NUM_QUERIES,
//                       NUM_FAMILIES / pow(10, j), NUM_MUTATIONS};
//            sprintf(name, "query-%d-%d.fa", i, j);
//            cout << "Begin generating query file " << name << endl;
//            begin = get_wall_time();
//            random_query_file(seq, cfg.s_len, cfg.q_len, cfg.m_num, name, cfg.q_num, cfg.f_num);
//            cout << "Done generating query file, time elapse: " << get_wall_time() - begin << "s"
//                 << endl;
//            cout << "Query file name: " << name << " qry_len=" << QUERY_LEN << " qry_num="
//                 << NUM_QUERIES << " fml_num=" << NUM_FAMILIES / pow(10, j) << " num_mutations="
//                 << NUM_MUTATIONS << endl;
//        }
//        delete[] seq;
//
//        cout << "=======seperator========" << endl << endl;
//    }
}