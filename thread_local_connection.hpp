#pragma once
#include <string>
#include <cassert>
#include <boost/noncopyable.hpp>
#include <boost/thread/tss.hpp>
#include <boost/thread/thread.hpp>
struct thread_local_connection : boost::noncopyable {
    thread_local_connection() = default;
    virtual ~thread_local_connection() {
        close();
    }
    bool init() {
        // todo some initiation operations
        return true;
    }
    void close() {
    }
    bool send(const std::string &data) {
        return true;
    }
};
boost::thread_specific_ptr<thread_local_connection>G_CONN_PTR;
thread_local_connection &get_conn() {
    auto *ptr = G_CONN_PTR.get();
    if (!ptr) {
        G_CONN_PTR.reset(new thread_local_connection);
        ptr = G_CONN_PTR.get();
        ptr->init();
    }
    return *ptr;
}