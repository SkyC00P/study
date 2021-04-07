package net.skycoop;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.TimeoutException;

public class Tool {
    private static final String EXCHANGE_NAME = "cns.device";
    private static final String EXCHANGE_GLOBAL_NAME = "cns.global";

    public static void initMQ(String name) throws IOException, TimeoutException {
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("192.168.137.185");
        Connection connection = factory.newConnection();
        Channel channel = connection.createChannel();

        channel.exchangeDeclare(EXCHANGE_NAME, "topic");
        channel.exchangeDeclare(EXCHANGE_GLOBAL_NAME, "topic");
        String queueName = channel.queueDeclare().getQueue();

        channel.queueBind(queueName, EXCHANGE_NAME, String.format("cns.device.%s.#.req", name));
        channel.queueBind(queueName, EXCHANGE_GLOBAL_NAME, "cns.global.#.req");
        channel.queueBind(queueName, EXCHANGE_GLOBAL_NAME, "cns.global.#.common");

        DeliverCallback deliverCallback = (consumerTag, delivery) -> {
            String message = new String(delivery.getBody(), StandardCharsets.UTF_8);
            System.out.println(" [x] Received '" + delivery.getEnvelope().getRoutingKey() + "':'" + message + "'");
        };
        channel.basicConsume(queueName, true, deliverCallback, consumerTag -> { });

        String routingKey = String.format("cns.device.%s.info.common", name);
        channel.basicPublish(EXCHANGE_NAME, routingKey, null, name.getBytes(StandardCharsets.UTF_8));
    }
}
