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
            FILETIME ftUserTimeStart;
            FILETIME ftDummy;
            GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftDummy, &ftUserTimeStart);
            starTime = ftUserTimeStart;
        }
        
        end_timer() : end_timer(
            [](long long _duration){
                std::cout << "Timer expired after " << _duration / 1e7  << " seconds" << std::endl;
            }
        ) {}

        ~end_timer() noexcept {
            tick();
        }

        void tick() noexcept {
            FILETIME ftUserTimeNow;
            FILETIME ftDummy;
            GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftDummy, &ftUserTimeNow);
            long long eplasedTimer{
                 (static_cast<long long>(ftUserTimeNow.dwLowDateTime ) - starTime.dwLowDateTime ) +
                ((static_cast<long long>(ftUserTimeNow.dwHighDateTime) - starTime.dwHighDateTime) << 32)
            };
            callback(eplasedTimer);
        }

    private:
        FILETIME                                 starTime;
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
