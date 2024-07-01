# Emotion-Based LED Display Using ROS and NeoPixel

[Read this page in English](https://github.com/GabrielSpdf/Apollo-Heart/blob/main/README-EN.md?plain=1)
[Leia esta página em português](https://github.com/GabrielSpdf/Apollo-Heart/blob/main/README-PT.md?plain=1)

This repository contains code to control a WS2812 (NeoPixel) LED ring based on emotion messages received via ROS (Robot Operating System). The project uses the Adafruit NeoPixel library for LED manipulation and integrates ROS communication to receive and process emotion messages.

---

## *Table of Contents*

1. [Features](#-features)
2. [Dependencies](#-dependencies)
3. [How to Use](#-how-to-use)
4. [Demonstration](#-demonstration)
5. [Potential Improvements](#-potential-improvements)

## *🔵 Features*
- **WS2812 LED Control**: Configures and controls a ring of 16 WS2812 LEDs.
- **ROS Integration**: Receives emotion messages via ROS and changes the LED colors based on the received emotion.
- **Emotion-to-Color Mapping**: Defines a mapping of 24 emotions to specific RGB colors based on Plutchik's Wheel of Emotions.

## *🟡 Dependencies*
#### • Adafruit NeoPixel Library - [Documentation](https://github.com/adafruit/Adafruit_NeoPixel)
#### • ROS (Robot Operating System) - [Documentation](https://www.ros.org/)
#### • rosserial_arduino - [Documentation](http://wiki.ros.org/rosserial_arduino)

## *🟢 How to Use*

### Install the program in your workspace:

### Clone the repository
```
https://github.com/GabrielSpdf/apollo_heart.git
```

### Launch the emotion node:
```
roslaunch display_emotions display_emotions.launch
```

### Command to start the program on the Arduino:
```
rosrun rosserial_python serial_node.py /dev/ttyACM0
```
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

## *🔴 Potential Improvements*
### Synchronization
When the robot's face changes color, the heart's color should follow this change.

### Pulsing color while waiting for action
To improve the appearance and the idea of the heart in a resting state, it would be ideal to add a pulsing effect to the heart's color, similar to a real heart.

### Transition between colors of the same spectrum
It is essential that, just as the robot's face transitions between colors according to Plutchik's Wheel of Emotions, the heart should also transition between colors.

> [!NOTE]
> In the project folder, there is a file called **for_future**, which was left as a basis for implementing color transitions.
