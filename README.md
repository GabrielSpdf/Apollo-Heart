
# Emotion-Based LED Display Using ROS and NeoPixel

Este repositório contém um código para controlar um anel de LEDs WS2812 (NeoPixel) com base em mensagens de emoções recebidas via ROS (Robot Operating System). O projeto utiliza a biblioteca Adafruit NeoPixel para manipulação dos LEDs e integra a comunicação ROS para receber e processar as mensagens de emoções. 

---

## *Sumário*

1. [Funcionalidades](#-funcionalidades)
2. [Dependências](#-dependências)
3. [Como Usar](#-como-usar)


## *🔵 Funcionalidades*
- **Controle de LEDs WS2812**: Configura e controla um anel de 16 LEDs WS2812.
- **Integração com ROS**: Recebe mensagens de emoções através do ROS e altera as cores dos LEDs conforme a emoção recebida.
- **Mapeamento de Emoções para Cores**: Define um mapeamento de 24 emoções para cores RGB específicas baseadas no Plutchik's Wheel of Emotions.

## *🟡 Dependências*
#### • Adafruit NeoPixel Library - [Documentação](https://github.com/adafruit/Adafruit_NeoPixel)
#### • ROS (Robot Operating System) - [Documentação](https://www.ros.org/)
#### • rosserial_arduino - [Documentação](http://wiki.ros.org/rosserial_arduino)

## *🟢 Como Usar*

### Instalar o programa no seu workspace:
```
# Clonar o repositório
https://github.com/GabrielSpdf/apollo_heart.git
```

### Lancar o nó das emoções :
```
roslaunch display_emotions display_emotions.launch
```

### Comando para iniciar o programa no arduino:
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
### Publicar uma mensagem no tópico /emotion

```
rostopic pub /utbots/display_emotions/emotion std_msgs/String "data: 'joy'"
```

## *🟣 Demonstração*

