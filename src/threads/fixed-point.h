#include <stdint.h>
#include "threads/thread.h"

#define Q (10)
#define F (1<<Q)
#define CONV_F(N) ((N)<<Q)
#define CONV_I(N) ((N)>>Q)
#define ADD(X,Y) ((X) + (Y))
#define ADD_N(X,Y) ((X) + (CONV_F(Y)))
#define SUB(X,Y) ((X) - (Y))
#define SUB_N(X,Y) ((X) - (CONV_F(Y)))
#define MUL(X,Y) (((int64_t) X)*(CONV_I(Y)))
#define MUL_N(X,Y) ((X)*(Y))
#define DIV(X,Y) ((((int64_t) X)<<Q)/(Y))
#define DIV_N(X,Y) ((X)/(Y))
#define CONV_N(N) (N >= 0 ? (CONV_I(ADD(N,(F)>>1))):(CONV_I(SUB(N,(F)>>1))))
#define LOAD_AVG(C59_60,C1_60,LA,RT) ADD(CONV_N(C59_60*LA), MUL_N(C1_60,RT))
#define RECENT_CPU(LA,RC,N) ADD_N(MUL(F - DIV(F,((LA<<1)+F)),RC), N)
#define PRIORITY(RC,N) ((PRI_MAX) - (RC>>(Q+2)) - (N << 1))