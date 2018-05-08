#include "mcs_lock.h"

namespace mySync {

    void mcs_lock::lock() {
        //to acquire the lock a thread atomically appends its own local node at the tail of the list returning tail's previous contents
        auto prior_node = tail.exchange(&local_node,
                                        std::memory_order_acquire);
        if (prior_node != nullptr) {
            local_node.locked = true;
            prior_node->next = &local_node;
            while (local_node.locked)
                /* Pause instruction to prevent excess processor bus usage */
                    asm volatile("pause\n": : :"memory");
        }
    }

    void mcs_lock::unlock() {
        //check whether this thread's local node’s next field is null
        if (local_node.next == nullptr) {
            //if so, then either:
            // 1. no other thread is contending for the lock
            // 2. there is a race condition with another thread about to
            //to distinguish between these cases atomic compare exchange the tail field
            //if the call succeeds, then no other thread is trying to acquire the lock, tail is set to nullptr, and unlock() returns
            mcs_node *p = &local_node;
            if (tail.compare_exchange_strong(p, nullptr,
                                             std::memory_order_release,
                                             std::memory_order_relaxed)) {
                return;
            }
            //otherwise, another thread is in the process of trying to acquire the lock, so spins waiting for it to finish
            while (local_node.next == nullptr) {};
        }
        local_node.next->locked = false;
        local_node.next = nullptr;
    }

    thread_local mcs_lock::mcs_node mcs_lock::local_node = mcs_lock::mcs_node{};

}