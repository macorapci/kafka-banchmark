#include <cppkafka/cppkafka.h>
#include "SimpleProducer.h"
#include "SimpleConsumer.h"
#include <iostream>

using namespace std;
using namespace cppkafka;

int main() {
	int messages[] = {10,100,1000,10000,100000};
	int messagesSize = *(&messages + 1) - messages;
	for(int k=0;k<messagesSize;k++){
		struct timespec producerStart, producerEnd, consumerStart, consumerEnd; 
		
    		clock_gettime(CLOCK_REALTIME, &producerStart);
		SimpleProducer simpleProducer;
		simpleProducer.start("test", "localhost:9092", messages[k]);
		clock_gettime(CLOCK_REALTIME, &producerEnd); 
		
		long producerSeconds = producerEnd.tv_sec - producerStart.tv_sec; 
    		long producerNs = producerEnd.tv_nsec - producerStart.tv_nsec; 
    		
    		if (producerStart.tv_nsec > producerEnd.tv_nsec) { // clock underflow 
		--producerSeconds; 
		producerNs += 1000000000; 
    		}
    		
    		printf("%d message is produced in: %.3f ms\n", messages[k], (double)producerSeconds + (double)producerNs/(double)1000000000); 
		
		clock_gettime(CLOCK_REALTIME, &consumerStart);
		SimpleConsumer simpleConsumer;
		simpleConsumer.start("test", "localhost:9092", messages[k]);
		clock_gettime(CLOCK_REALTIME, &consumerEnd); 
		
		long consumerSeconds = consumerEnd.tv_sec - consumerStart.tv_sec; 
    		long consumerNs = consumerEnd.tv_nsec - consumerStart.tv_nsec; 
    		
    		if (consumerStart.tv_nsec > consumerEnd.tv_nsec) { // clock underflow 
		--consumerSeconds; 
		consumerNs += 1000000000; 
    		}
    		
    		printf("%d message is consumed in: %.3f ms\n", messages[k], (double)consumerSeconds + (double)consumerNs/(double)1000000000); 
    		
    		
	}
	
}
