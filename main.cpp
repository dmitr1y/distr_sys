#include <zconf.h>
#include <vector>
#include "MCS/mcs_lock.h"

using mySync::mcs_lock;
static int N_THREAD = 5000;
static int N_REPEATS = 10;

void func(int &counter, mcs_lock &mcsLock) {
    mcsLock.lock();
    counter++;
    mcsLock.unlock();
}

int main() {
    long sum = 0;
    using Time = std::chrono::high_resolution_clock;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    for (int j = 0; j < N_REPEATS; ++j) {

        int counter = 0;
        mcs_lock mcsLock;
        std::vector<std::thread> thread_pool;


        auto t0 = Time::now();

        for (int i = 0; i < N_THREAD; ++i)
            thread_pool.emplace_back(func, std::ref(counter), std::ref(mcsLock));

        for (auto &thread : thread_pool)
            thread.join();

        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ms d = std::chrono::duration_cast<ms>(fs);
        sum += d.count();

        if (counter != N_THREAD)
            return -1;
    }
    std::cout << std::endl << "average time:  " << sum / N_REPEATS << " ms for " << N_THREAD << " threads" << std::endl;

    return 0;
}

