
# ➜ Repositório do Entregavel Sprint 8 - IoT

## Objetivo
Este projeto tem como objetivo conectar o arduíno a um sensor magnético para monitorar se um Rack está ABERTO ou FECHADO - enviar essa informação via Internet
utilizando o protocolo MQTT (Message Queuing Telemetry Transport) para um servidor MQTT hospedado na Amazon Web Service (AWS) - exibir a informação 
em um cliente MQTT ([MQTT Dash](https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=en&gl=US)) instalado em um Smartphone, conforme imagem abaixo.

![Projeto 1](https://user-images.githubusercontent.com/78054160/106751642-3763f000-6608-11eb-835d-d35a99a629a1.png)


## Biblíotecas Utilizadas
- [PubSubClient](https://github.com/knolleary/pubsubclient) (cliente MQTT para o Arduino)
- [UIPEthernet](https://github.com/UIPEthernet/UIPEthernet) (conexão do ENC28J60 com o Arduino)
- SPI


## Materiais
- Arduino Uno
- Módulo Ethernet (ENC28J60)
- Sensor Magnético (MC-38)
- Jumpers
- Smartphone

## Circuito

![Projeto 2](https://user-images.githubusercontent.com/78054160/106751865-8f025b80-6608-11eb-964a-313256726413.png)

<b>Autor : <i>Lucas Butzge de Oliveira
  

