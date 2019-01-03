#include "utils.h"
#include "test1.h"

A_stm prog() {

    // a := 5+3; b := (print(a, a-1), 10*a); print(b)

    return A_CompoundStm(
        A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),                            // a := 5+3
        A_CompoundStm(
            A_AssignStm("b", A_EseqExp(A_PrintStm(                                              // b := (print
                A_PairExpList(
                    A_IdExp("a"), A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1)))    // (a, a-1)
                )
            ),
            A_OpExp(A_NumExp(10), A_mul, A_IdExp("a")))),                                       // 10*a
            A_PrintStm(A_LastExpList(A_IdExp("b")))));                                          // print b
}

int maxargs(A_stm stm) {

    switch(stm->kind) {
        case A_compoundStm:
            return max(maxargs(stm->u.compound.stm1), maxargs(stm->u.compound.stm2));
            break;
        case A_assignStm:
            return maxargs_exp(stm->u.assign.exp);
            break;
        case A_printStm:
            return itemsCount(stm->u.print.exps);
    }
}

int maxargs_exp(A_exp exp) {
    if (exp->kind == A_opExp) {
        return max(maxargs_exp(exp->u.op.left), maxargs_exp(exp->u.op.right));
    } else if (exp->kind == A_eseqExp) {
        return max(maxargs_exp(exp->u.eseq.exp), maxargs(exp->u.eseq.stm));
    }
}

int max(int a, int b) {
    return a > b ? a : b;    
}

int itemsCount(A_expList exps) {
    if (exps->kind == A_pairExpList) {
        return itemsCount(exps->u.pair.tail) + 1;
    }

    return 1;
}