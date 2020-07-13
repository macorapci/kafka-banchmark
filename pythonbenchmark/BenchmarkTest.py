import SimpleConsumer
import SimpleProducer
import time

for k in (10,100,1000,10000,100000):
	producerStart=int(round(time.time() * 1000))
	SimpleProducer.start(topicName='test', host='localhost:9092', messageNum=k)
	producerEnd=int(round(time.time() * 1000))
	print(k," message is produced in ",(producerEnd-producerStart)," ms")
	
	consumerStart=int(round(time.time() * 1000))
	SimpleConsumer.start(topicName='test', host='localhost:9092',messageNum=k)
	consumerEnd=int(round(time.time() * 1000))
	print(k," message is consumed in ",(consumerEnd-consumerStart)," ms")
	
