#ifndef DISTR_SYS_MCS_LOCK_H
#define DISTR_SYS_MCS_LOCK_H

#include <cstdint>
#include <cassert>
#include <atomic>
#include <thread>

#include <iostream>

namespace mySync {

    class mcs_lock {

        struct mcs_node {

            bool locked{true};

            mcs_node *next{nullptr};

        };

    public:

        void lock();

        void unlock();

    private:

        std::atomic<mcs_node *> tail{nullptr};

        static thread_local mcs_node local_node;

    };

}


#endif // DISTR_SYS_MCS_LOCK_H