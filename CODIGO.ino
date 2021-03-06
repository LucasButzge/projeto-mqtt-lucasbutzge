//Monitoramento remoto com Arduino e protocolo MQTT

#include <PubSubClient.h>
#include <UIPEthernet.h>
#include <SPI.h>

//MacAdress 5E-67-04-0E-A6-2F
byte mac[] = {0x5E, 0x67, 0x04, 0x0E, 0xA6,0x2F}; //Define o endereço MAC que será utilizado
int pino2 =2;
bool mensagem; //Variavél utilizada para enviar as mensagens utilizando o cliente MQTT
bool estado_sensor;
EthernetClient client; //Inicia o cliente Ethernet
PubSubClient mqttClient(client); //Inicia o client MQTT

void setup() {

    
    pinMode (pino2,INPUT_PULLUP);
    Serial.begin(9600);
    
    Ethernet.begin(mac); //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    
    Serial.begin(9600); //Inicia o monitor Serial

    mqttClient.setServer("54.173.148.114",1883); //Define o IP e Porta TCP do Broker MQTT que vamos utilizar

    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP()); //Exibe no Monitor Serial as informações sobre o IP do Arduino

    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask()); //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino

    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP()); //Exibe no Monitor Serial as informações sobre o Gateway do Arduino

    Serial.println(""); //Exibe uma linha em branco


  }

void loop() {

    estado_sensor = digitalRead(pino2); //Efetua a leitura do pino 2 e guarda o valor obtido na variavel
 
    mqttClient.connect ("LucasButzge"); //Nome do client que será acessado remotamente

if (estado_sensor == 0){
    mensagem = mqttClient.publish("LucasButzge-t", "Fechado.");
    
    Serial.print("O estado do sensor e: ");
    Serial.println(estado_sensor);
    }

else {
    mensagem = mqttClient.publish("LucasButzge-t", "Aberto.");
    
    Serial.print("O estado do sensor e: ");
    Serial.println(estado_sensor);
    }
    
    mqttClient.loop();
    
}