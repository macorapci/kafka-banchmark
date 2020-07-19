from kafka import KafkaConsumer
from json import loads

def start(topicName, host, messageNum):
	consumer = KafkaConsumer(
		topicName,	
     		bootstrap_servers=[host],
     		auto_offset_reset='earliest',
     		enable_auto_commit=True,
     		group_id='my-group',
     		value_deserializer=lambda x: loads(x.decode('utf-8')))


	for message in consumer:
    		message = message.value
    		#print('message is {}'.format(message))
    		if(message==messageNum-1):
    			break;
	
	consumer.close()
	

