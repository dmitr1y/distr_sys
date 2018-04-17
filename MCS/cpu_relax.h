//
// Created by dmitriy on 17.04.18.
//

#ifndef DISTR_SYS_CPU_RELAX_H
#define DISTR_SYS_CPU_RELAX_H

#include <xmmintrin.h>

//namespace sync {

    inline static void cpu_relax() {

#if (COMPILER == GCC || COMPILER == LLVM)
        asm volatile("pause\n": : :"memory");
#endif
    }

//}

#endif //DISTR_SYS_CPU_RELAX_H
