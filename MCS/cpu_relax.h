//
// Created by dmitriy on 01.05.18.
//

#ifndef DISTR_SYS_CPU_RELAX_H
#define DISTR_SYS_CPU_RELAX_H

#include <xmmintrin.h>

namespace mySync {

    inline static void cpu_relax() {
        asm volatile("pause\n": : :"memory");
    }

}

#endif //DISTR_SYS_CPU_RELAX_H
