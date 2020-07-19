#ifndef SIMPLEPRODUCER_H
#define SIMPLEPRODUCER_H
class SimpleProducer
{
public:
    SimpleProducer();
    void start(std::string topicName, std::string host, int messageNum);
};
#endif
