# Apollo Heart - Emotion-Based LED Display Using ROS and NeoPixel

This repository contains code to control a WS2812 (NeoPixel) LED ring based on emotion messages received via ROS (Robot Operating System). The project uses the Adafruit NeoPixel library for LED manipulation and integrates ROS communication to receive and process emotion messages. Additionally, the project is designed to work in conjunction with the [Display Emotions](https://github.com/UtBotsAtHome-UTFPR/display_emotions) project to develop the representation of emotions for the Apollo robot from the [LASER](https://laser.dainf.ct.utfpr.edu.br/doku.php) lab.

[Leia esta página em Português](https://github.com/GabrielSpdf/Apollo-Heart/blob/main/README.md)

---

## *Table of Contents*

1. [Features](#-features)
2. [Dependencies](#-dependencies)
3. [Usage](#-usage)
4. [Demonstration](#-demonstration)
5. [Possible Improvements](#-possible-improvements)


## *🔵 Features*
- **WS2812 LED Control**: Configures and controls a ring of 16 WS2812 LEDs.
- **ROS Integration**: Receives emotion messages through ROS and changes the LED colors according to the received emotion.
- **Emotion-to-Color Mapping**: Defines a mapping of 24 emotions to specific RGB colors based on the [Plutchik's wheel of emotions](https://www.6seconds.org/2022/03/13/plutchik-wheel-emotions/).

## *🟡 Dependencies*
- **Adafruit NeoPixel Library** - [Documentation](https://github.com/adafruit/Adafruit_NeoPixel)
- **ROS (Robot Operating System)** - [Documentation](https://www.ros.org/)
- **rosserial_arduino** - [Documentation](http://wiki.ros.org/rosserial_arduino)

## *🟢 Usage*

### Install the program in your workspace

```
Clone the repository
https://github.com/GabrielSpdf/apollo_heart.git
```

### Launch the emotion node
```
roslaunch display_emotions display_emotions.launch
```

### Start the program on the Arduino 
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
> [!NOTE]
> Replace **/dev/ttyACM0** with the USB port where your device is connected.

### Publish a message to the /emotion topic
```
rostopic pub /utbots/display_emotions/emotion std_msgs/String "data: 'joy'"
```

## *🟣 Demonstration*

Below is a demonstration of the project using the emotions **TRUST** and **RAGE**, respectively:

<div style="display: flex; flex-direction: row; justify-content: center;">
  <div style="margin: 10px; text-align: center;">
    <img src="assets/video1.gif" alt="" width="500" height="300"/>
    <img src="assets/video0.gif" alt="" width="500" height="300"/>
  </div>
</div>

## *🔴 Possible Improvements*
### Synchronization
When the robot's face changes color, the heart color should follow this change.

### Pulse color while waiting for an action
To improve the appearance and the idea of the heart in a resting state, it would be ideal to add a color pulse to the heart, similar to a real heartbeat.

### Transition between colors of the same spectrum
It is essential that, just as the robot's face transitions between colors according to the [Plutchik's wheel of emotions](https://www.6seconds.org/2022/03/13/plutchik-wheel-emotions/), the heart should also transition between colors.

> [!NOTE]
> In the project folder, there is a file called **for_future**, which was left as a basis for implementing the color transitions.
