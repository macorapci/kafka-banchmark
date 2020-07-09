import java.util.Properties;
import java.util.Arrays;
import org.apache.kafka.clients.consumer.KafkaConsumer;
import org.apache.kafka.clients.consumer.ConsumerRecords;
import org.apache.kafka.clients.consumer.ConsumerRecord;

public class SimpleConsumer {
    public static void main(String topicName, String host) throws Exception {
        Properties props = new Properties();
        props.put("bootstrap.servers", host);
        props.put("group.id", "test");
        props.put("enable.auto.commit", "true");
        props.put("auto.commit.interval.ms", "1000");
        props.put("session.timeout.ms", "30000");
        props.put("key.deserializer",
                "org.apache.kafka.common.serialization.StringDeserializer");
        props.put("value.deserializer",
                "org.apache.kafka.common.serialization.StringDeserializer");
        KafkaConsumer<String, String> consumer = new KafkaConsumer
                <String, String>(props);

        //Kafka Consumer subscribes list of topics here.
        consumer.subscribe(Arrays.asList(topicName));

        //print the topic name
        //System.out.println("Subscribed to topic " + topicName);

        consumer.seekToBeginning(consumer.assignment());
        ConsumerRecords<String, String> records=consumer.poll(Long.MAX_VALUE);
        for (ConsumerRecord<String, String> record : records){
            //System.out.printf("offset = %d, key = %s, value = %s",record.offset(), record.key(), record.value());
        }
        consumer.commitSync();
        consumer.close();
    }
}
