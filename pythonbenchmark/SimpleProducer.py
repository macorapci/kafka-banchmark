from time import sleep
from json import dumps
from kafka import KafkaProducer

def start(topicName, host, messageNum):
	producer = KafkaProducer(bootstrap_servers=[host],
                         value_serializer=lambda x: dumps(x).encode('utf-8'))
                         
                         
	for k in range(messageNum):
		producer.send(topicName, k)
    
	producer.close()
	

