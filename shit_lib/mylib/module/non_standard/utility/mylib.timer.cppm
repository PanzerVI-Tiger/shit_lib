module;

#include <Windows.h>

#ifdef __INTELLISENSE__

#include <thread>
#include <iostream>
#include <functional>

#endif

export module mylib.timer;

#ifndef __INTELLISENSE__

import std.core;

#endif

export namespace mylib {
    
    class end_timer {
    public:
        end_timer(std::function<void(long long _duration)> _callback) noexcept : callback{ _callback } {
            FILETIME ftKernalTimeStart;
            FILETIME ftUserTimeStart;
            FILETIME ftDummy;
            GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftKernalTimeStart, &ftUserTimeStart);
            userStarTime = ftUserTimeStart;
        }
        
        end_timer() : end_timer(
            [](long long _duration){
                std::cout << "Timer expired after " << _duration / 1e7  << " seconds" << std::endl;
            }
        ) {}

        ~end_timer() noexcept {
            tick();
        }

        [[msvc::noinline]]
        void tick() noexcept {
            FILETIME ftKernalTimeNow;
            FILETIME ftUserTimeNow;
            FILETIME ftDummy;
            GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftKernalTimeNow, &ftUserTimeNow);
            long long eplasedTimer{
                ((static_cast<long long>(ftUserTimeNow.  dwLowDateTime ) - userStarTime.  dwLowDateTime )  +
                ((static_cast<long long>(ftUserTimeNow.  dwHighDateTime) - userStarTime.  dwHighDateTime) << 32)) +
                ((static_cast<long long>(ftKernalTimeNow.dwLowDateTime)  - kernalStarTime.dwLowDateTime)   +
                ((static_cast<long long>(ftKernalTimeNow.dwHighDateTime) - kernalStarTime.dwHighDateTime) << 32))
            };
            callback(eplasedTimer);
        }

    private:
        FILETIME                                 userStarTime;
        FILETIME                                 kernalStarTime;
        std::function<void(long long _duration)> callback;
    };

    class timer {
    public:
        timer(size_t duration, std::function<void()> callback) noexcept : 
            timerThread{
                [&] {
                    while (true) {
                        std::this_thread::sleep_for(
                            static_cast<std::chrono::steady_clock::duration>(duration)
                        );
                        callback();
                    }
                }
            } {}

        ~timer() {
            timerThread.detach();
        }
    
    private:
        std::thread timerThread;
    };
}
