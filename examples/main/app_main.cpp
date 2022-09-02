#include "stdio.h"

#include "wh_circular_queue.hpp"

extern "C" void app_main(){

	wh_queue::CircularQueue<float, 10> queue;

	queue.enQueue(25.5);
	queue.enQueue(25);
	queue.enQueue(20);
	queue.enQueue(5.5);
	printf("%f\n", queue.deQueue());
	printf("%f\n", queue.deQueue());
	queue.enQueue(0);
	queue.enQueue(0.5);
	printf("%f\n", queue.deQueue());
	printf("%f\n", queue.deQueue());
	printf("%f\n", queue.deQueue());
	printf("%f\n", queue.deQueue());
}