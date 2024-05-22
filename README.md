
# Estrutura do Repositório

- **[Introdução](#introdução)**
- **[Estrutura do Repositório](#estrutura-do-repositório)**
- **[Como Contribuir](#como-contribuir)**
- **[Licença](#licença)**

# Introdução

Este repositório é uma implementação do coração de um robô de serviço.🐙🦛

## Instalar o programa no seu workspace:
```
# Clonar o repositório
https://github.com/GabrielSpdf/apollo_heart.git
```

## Lancar o nó das emoções :
```
roslaunch display_emotions display_emotions.launch
```


## Comando para iniciar o programa no arduino:
```
rososrun rosserial_python serial_node.py /dev/ttyACM0
```
## Publicar uma mensagem no tópico /emotion

```
rostopic pub /utbots/display_emotions/emotion std_msgs/String "data: 'joy'"
```

![WhatsApp-Video-2024-05-09-at-14 35 03](https://github.com/GabrielSpdf/apollo_heart/assets/130702330/0273544b-651a-4dfd-982a-77544415cd19)
