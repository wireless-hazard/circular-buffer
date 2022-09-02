#include "stdio.h"
#include <cstdlib>
#include "assert.h"

#include "wh_circular_queue.hpp"

extern "C" void app_main(){

	int buffer[150]{0};
	int buffer2[150]{0};


	wh_queue::CircularQueue<int, 10> queue;
	
	for (int i = 0; i < 150; i++)
	{
		buffer[i] = rand() % 100 + 1;
		esp_err_t err = queue.enQueue(buffer[i]);
		if(err!=ESP_OK)break;
		printf("Leitura %d\n", i);

	}
	for (int i = 0; i < 100; ++i)
	{
		printf("Expected: %d, Got: %d\n", buffer[i], queue.deQueue());
	}
	printf("ESSA FOI A PARTE 1\n");

	for (int i = 0; i < 10; i++)
	{
		buffer2[i] = rand() % 100 + 1;
		esp_err_t err = queue.enQueue(buffer2[i]);
		assert(err==ESP_OK);
	}
	printf("Part 2\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("Expected: %d, Got: %d\n", buffer2[i], queue.deQueue());
	}
}