
# Apollo Heart - Emotion-Based LED Display Using ROS and NeoPixel

Este repositório contém um código para controlar um anel de LEDs WS2812 (NeoPixel) com base em mensagens de emoções recebidas via ROS (Robot Operating System). O projeto utiliza a biblioteca Adafruit NeoPixel para manipulação dos LEDs e integra a comunicação ROS para receber e processar as mensagens de emoções. Ademais, o projeto foi criado para trabalhar em conjunto com o projeto [Display Emotions](https://github.com/UtBotsAtHome-UTFPR/display_emotions) a fim de desenvolver a representação das emoções do robô Apollo do laboratório [LASER](https://laser.dainf.ct.utfpr.edu.br/doku.php).


[Read this page in English](https://github.com/GabrielSpdf/Apollo-Heart/blob/main/README-EN.md)

---

## *Sumário*

1. [Funcionalidades](#-funcionalidades)
2. [Dependências](#-dependências)
3. [Como Usar](#-como-usar)
4. [Demonstração](#-demonstração)
5. [Possíveis Melhorias](#-possíveis-melhorias)


## *🔵 Funcionalidades*
- **Controle de LEDs WS2812**: Configura e controla um anel de 16 LEDs WS2812.
- **Integração com ROS**: Recebe mensagens de emoções através do ROS e altera as cores dos LEDs conforme a emoção recebida.
- **Mapeamento de Emoções para Cores**: Define um mapeamento de 24 emoções para cores RGB específicas baseadas na [roda das emoções de Plutchik](https://www.6seconds.org/2022/03/13/plutchik-wheel-emotions/).

## *🟡 Dependências*
- **Adafruit NeoPixel Library** - [Documentação](https://github.com/adafruit/Adafruit_NeoPixel)
- **ROS (Robot Operating System)** - [Documentação](https://www.ros.org/)
- **rosserial_arduino** - [Documentação](http://wiki.ros.org/rosserial_arduino)

## *🟢 Como Usar*

### Instale o programa no seu workspace
```
Clone o repositório
https://github.com/GabrielSpdf/Apollo-Heart.git
```

### Lance o nó das emoções 
```
roslaunch display_emotions display_emotions.launch
```

### Inicie o programa no arduino 
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
> [!NOTE]
> Substitua **/dev/ttyACM0** pela porta USB onde seu dispositivo está conectado.

### Publique uma mensagem no tópico /emotion
```
rostopic pub /utbots/display_emotions/emotion std_msgs/String "data: 'joy'"
```

## *🟣 Demonstração*

A seguir está a demonstração do uso do projeto com as emoções **TRUST** e **RAGE**, respectivamente:

<div style="display: flex; flex-direction: row; justify-content: center;">
  <div style="margin: 10px; text-align: center;">
    <img src="assets/video1.gif" alt="" width="500" height="300"/>
    <img src="assets/video0.gif" alt="" width="500" height="300"/>
  </div>
</div>

## *🔴 Possíveis Melhorias*
### Sincronização
No momento em que a face do robô muda de cor, a cor do coração deveria acompanhar essa mudança.

### Pulsar cor enquanto espera alguma ação
A fim de melhorar a aparência e a ideia do coração em estado de repouso, seria ideal adicionar uma pulsação da cor do coração tal como o coração na realidade.

### Transição entre as cores do mesmo espectro
É imprescindível que, tal como a face do robô transiciona entre as cores de acordo com a [roda das emoções de Plutchik](https://www.6seconds.org/2022/03/13/plutchik-wheel-emotions/), o coração deveria também transicionar entre as cores.

> [!NOTE]
> Na pasta do projeto, existe um arquivo chamado **for_future**, o qual foi deixado como base para implementar a transição entre as cores.

