

public class BenchmarkTest {
    public static void main(String[] args) throws Exception {
        int [] messages = {10,100,1000,10000,100000};
        for (int k=0;k<messages.length;k++){
            long producerStart = System.currentTimeMillis();
            SimpleProducer.main("test","localhost:9092",messages[k]);
            long producerEnd = System.currentTimeMillis();
            System.out.printf("%d message is produced in %.3f ms\n",messages[k],(producerEnd-producerStart)/1000.0);

            long consumerStart = System.currentTimeMillis();
            SimpleConsumer.main("test","localhost:9092");
            long consumerEnd = System.currentTimeMillis();
            System.out.printf("%d message is consumed in %.3f ms\n",messages[k],(consumerEnd-consumerStart)/1000.0);

        }

    }
}
