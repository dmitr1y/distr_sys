
#include <vector>
#include <mutex>
#include <random>
#include "MCS/mcs_lock.h"

using mySync::mcs_lock;
static int N_THREAD = 128;
static int N_REPEATS = 10;
static int N_OPERATIONS = 100;

void func(int &counter, mcs_lock &mcsLock) {
    for (int i = 0; i < N_OPERATIONS; i++) {
        mcsLock.lock();
        counter++;
        mcsLock.unlock();
    }
}

void funcMutex(int &counter, std::mutex &mutexLock) {
    for (int i = 0; i < N_OPERATIONS; i++) {
        mutexLock.lock();
        counter++;
        mutexLock.unlock();

    }
}

int main() {
    long sum = 0, sumNS = 0;
    using Time = std::chrono::high_resolution_clock;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    for (int j = 0; j < N_REPEATS; ++j) {

        int counter = 0;
        mcs_lock mcsLock;
        std::vector<std::thread> thread_pool;
        auto t0 = Time::now();

        //testing field
        for (int i = 0; i < N_THREAD; ++i)
            thread_pool.emplace_back(func, std::ref(counter), std::ref(mcsLock));

        for (auto &thread : thread_pool)
            thread.join();
        //end of testing field
        auto t1 = Time::now();
        fsec fs = t1 - t0;
        ms d = std::chrono::duration_cast<ms>(fs);
        sum += d.count();
        sumNS += std::chrono::duration_cast<std::chrono::nanoseconds>(fs).count();
//        if (counter != N_THREAD)
//            return -1;
    }
    std::cout << std::endl << "average time:  " << sum / N_REPEATS << " ms ( " << sumNS / N_REPEATS << " ns)" << " for "
              << N_THREAD << " threads" << std::endl;

    return 0;
}

