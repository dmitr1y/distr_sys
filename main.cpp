
#include "Exp/Exp.h"


#define N_THREAD 8
#define N_REPEATS 1
#define N_OPERATIONS 100000
#define MAX_NUBER 10000

int main() {
    using Time = std::chrono::high_resolution_clock;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    long sum = 0;
    for (int i = 0; i < N_REPEATS; ++i) {
        Exp exp(MAX_NUBER, N_OPERATIONS, N_THREAD);

        auto t0 = Time::now();

        exp.testMSQueue();

        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ms d = std::chrono::duration_cast<ms>(fs);
        sum += d.count();
    }

    std::cout << std::endl << "average time:  " << sum / N_REPEATS << " ms for " << N_THREAD << " threads" << std::endl;

    return 0;
}