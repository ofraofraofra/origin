#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>
#include <future>
#include <functional>
#include <type_traits>
#include "safe_queue.h"

class thread_pool {
public:
    thread_pool(size_t num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] { this->work(); });
        }
    }

    ~thread_pool() {
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();
        for (std::thread& worker : workers) {
            worker.join();
        }
    }

    template <typename F, typename... Args>
    auto submit(F&& f, Args&&... args)
        -> std::future<typename std::invoke_result<F, Args...>::type> {
        using return_type = typename std::invoke_result<F, Args...>::type;
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
            );
        std::future<return_type> result = task->get_future();
        task_queue.push([task]() { (*task)(); });
        cv.notify_one();
        return result;
    }

private:
    std::vector<std::thread> workers;
    safe_queue<std::function<void()>> task_queue;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

    void work() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return stop || !task_queue.empty(); });
                if (stop && task_queue.empty()) {
                    return;
                }
                task_queue.pop(task);
            }
            task();
        }
    }
};

#endif
