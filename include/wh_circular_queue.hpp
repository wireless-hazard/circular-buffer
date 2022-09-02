#pragma once

#include <cstddef>
#include "esp_err.h"

namespace wh_queue
{
	
template <typename T, size_t L>
class CircularQueue{
public:
	inline CircularQueue(void): front(-1), back(-1){}
	/**
	@brief Returns the oldest value from the queue, removing it afterwords
	return T Returns the value from queue
	*/
	T deQueue(void) {
		if (isEmpty()) {return 0;}

		T element = internal_buffer[++front];
		
		if(front==back){
			front = -1;
			back = -1;
		}
		return element;
	}
	/**
	@brief Adds a value into the queue
	@param T **value** - value to be added to the queue
	@return **esp_err_t** - ESP_OK if successful, ESP_FAIL if queue is full.
	*/
	inline esp_err_t enQueue(T value) {
		if ((back+1) == L) return ESP_FAIL;
		back++;
		internal_buffer[back] = value;
		return ESP_OK;
	}
protected:
	/**
	@brief Returns true if the queue is empty
	*/
	inline bool isEmpty(void) const {return ((front==(-1)) && (back == (-1)));}
	T internal_buffer[L];
	int front;
	int back;
};

}