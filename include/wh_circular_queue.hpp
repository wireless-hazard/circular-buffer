#pragma once

#include <cstddef>

namespace wh_queue
{
	
template <typename T, size_t L>
class CircularQueue{
public:
	inline CircularQueue(void): front(-1), back(-1){
	}
	T deQueue(void) {return internal_buffer[++front];}
	inline void enQueue(T value) {internal_buffer[++back] = value;}
protected:
	T internal_buffer[L];
	int front;
	int back;
};

}