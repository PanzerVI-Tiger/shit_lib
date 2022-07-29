module;

#include <Windows.h>

export module mylib.timer;

import std.core;


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
				 (long long(ftUserTimeNow.dwLowDateTime ) - starTime.dwLowDateTime ) +
				((long long(ftUserTimeNow.dwHighDateTime) - starTime.dwHighDateTime) << 32)
			};
			callback(eplasedTimer);
		}

	private:
		FILETIME							     starTime;
		std::function<void(long long _duration)> callback;
	};

	class timer {
	public:
		timer(size_t _duration, std::function<void()> _callback) noexcept : 
			duration{ _duration }, callback{ _callback }, timerThread{
				[&] {
					while (true) {
						std::this_thread::sleep_for(duration);
						callback();
					}
				}
			} {}

		~timer() {
			timerThread.detach();
		}
	
	private:
		std::function<void()>				  callback;
		std::thread							  timerThread;
		std::chrono::steady_clock::duration   duration;
	};
}
