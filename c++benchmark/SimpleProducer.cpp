#include <cppkafka/cppkafka.h>
#include "SimpleProducer.h"
 
using namespace std;
using namespace cppkafka;

void SimpleProducer::start(std::string topicName, std::string host, int messageNum) {
    // Create the config
    Configuration config = {
        { "metadata.broker.list", host }
    };

    // Create the producer
    Producer producer(config);

    // Produce a message!
    for(int k=0;k<messageNum;k++){
    	std::string message = std::to_string(k);
    	producer.produce(MessageBuilder(topicName).partition(0).payload(message));
    	producer.flush();
    }
    //producer.close();
}

SimpleProducer::SimpleProducer(){
	//
}
