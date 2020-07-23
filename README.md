# kafka-benchmark

Bu projede farklı programlama dillerinin Kafka'da mesajın üretilmesinde ve mesajın tüketilmesinde etkisine bakılmaya çalışılmıştır. Bu kıyaslama ise süre üzerinden yapılmaktadır.

Benchmark testi, localhost'ta yapılmıştır. Aynı bilgisayar ile yapılmış her benchmark testi için çıktılar aşağıda verilmiştir:

## Java
https://mvnrepository.com/artifact/org.apache.kafka kütüphanesi projeye maven ile eklenmiştir.
```
log4j:WARN No appenders could be found for logger (org.apache.kafka.clients.producer.ProducerConfig).
log4j:WARN Please initialize the log4j system properly.
log4j:WARN See http://logging.apache.org/log4j/1.2/faq.html#noconfig for more info.
10 message is produced in 0.518 ms
10 message is consumed in 0.111 ms
100 message is produced in 0.021 ms
100 message is consumed in 0.034 ms
1000 message is produced in 0.029 ms
1000 message is consumed in 0.039 ms
10000 message is produced in 0.054 ms
10000 message is consumed in 0.031 ms
100000 message is produced in 0.232 ms
100000 message is consumed in 0.023 ms
 
Process finished with exit code 0
```

## Python
Bu projenin çalışabilmesi için python-kafka kütüphanesi gerekmektedir. Pip3 paket yönetici ile kolayca indirilebilir.
```
10  message is produced in  440  ms
10  message is consumed in  654  ms
100  message is produced in  145  ms
100  message is consumed in  259  ms
1000  message is produced in  185  ms
1000  message is consumed in  245  ms
10000  message is produced in  400  ms
10000  message is consumed in  456  ms
100000  message is produced in  2863  ms
100000  message is consumed in  1209  ms
```

## C++
Bu projenin çalışabilmesi için cppkafka ve librdkafka kütüphanesinin kurulması gerekmektedir. Bu kütüphaneler github'da açık kaynak olarak paylaşılmıştır.
```
10 message is produced in: 0.104 ms
10 message is consumed in: 3.054 ms
100 message is produced in: 1.022 ms
100 message is consumed in: 3.031 ms
1000 message is produced in: 10.175 ms
1000 message is consumed in: 3.161 ms
10000 message is produced in: 102.003 ms
10000 message is consumed in: 4.215 ms
100000 message is produced in: 1018.185 ms
100000 message is consumed in: 12.470 ms
```
