#ifndef SIMPLECONSUMER_H
#define SIMPLECONSUMER_H
class SimpleConsumer
{
public:
    SimpleConsumer();
    void start(std::string topicName, std::string host, int messageNum);
};
#endif
