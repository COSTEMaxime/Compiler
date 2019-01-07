#include "structs.h"

A_stm prog();

// Exercice 1
int maxargs(A_stm stm);
int maxargs_exp(A_exp exp);
int itemsCount(A_expList exps);

// Exercice 2
void interp(A_stm stm);

typedef struct table *Table_;
struct table {
    string id;
    int value;
    Table_ tail;
}

Table_ Table(string id, int value, Table_ tail);


int max(int a, int b);