#include <cppkafka/cppkafka.h>
#include "SimpleConsumer.h"
#include <iostream>
 
using namespace std;
using namespace cppkafka;

void SimpleConsumer::start(std::string topicName, std::string host, int messageNum) {
    // Create the config
    Configuration config = {
        { "metadata.broker.list", host },
        { "group.id", "my_group" },
        { "enable.auto.commit", true }
    };

    Consumer consumer(config);
    consumer.subscribe({ topicName });
    int count=0;

    while (messageNum>count) {
        // Try to consume a message
        Message msg = consumer.poll();
        if (msg) {
            // If we managed to get a message
            if (msg.get_error()) {
                // Ignore EOF notifications from rdkafka
                if (!msg.is_eof()) {
                    cout << "[+] Received error notification: " << msg.get_error() << endl;
                }
            }
            else {
                // Print the key (if any)
                if (msg.get_key()) {
                    //cout << msg.get_key() << " -> ";
                }
                // Print the payload
                //cout << msg.get_payload() << endl;
                // Now commit the message
                consumer.commit(msg);
                count++;
            }
        }
    }
}

SimpleConsumer::SimpleConsumer(){
	//
}
