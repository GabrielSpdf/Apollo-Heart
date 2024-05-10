#include "Adafruit_NeoPixel.h"
#include <ros.h>
#include <std_msgs/UInt16.h>
#include "std_msgs/String.h"
 
ros::NodeHandle  nh;

#define LED_PIN  5 			// Pino digital do "DIN" do módulo WS2812 
#define NUM_LEDS 16 		// Número de Leds do módulo Led WS2812
#define BRIGHTNESS 255 		// Intensidade do LED (0 até 255) 

int i;                                         // Variável que identifica a posição do LED no anel (0 até 15)   
String emotion_name;  

Adafruit_NeoPixel leds(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

enum Color {
    SERENITY,
    JOY,
    ACCEPTANCE,
    TRUST,
    ECSTASY,
    ADMIRATION,
    TERROR,
    FEAR,
    APPREHENSION,
    AMAZEMENT,
    SURPRISE,
    DISTRACTION,
    PENSIVENESS,
    SADNESS,
    BOREDOM,
    DISGUST,
    GRIEF,
    ANNOYANCE,
    ANGER,
    RAGE,
    INTEREST,
    ANTICIPATION,
    VIGILANCE,
    OPTIMISM,
    LOVE,
    SUBMISSION,
    AWE,
    DISAPPROVAL,
    REMORSE,
    CONTEMPT,
    AGGRESSIVENESS,
    NUM_COLORS
};

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

RGB colorMap[NUM_COLORS] = {
    {255, 223, 186},  // SERENITY
    {255, 255, 85},   // JOY
    {119, 221, 119},  // ACCEPTANCE
    {17, 170, 42},    // TRUST
    {255, 215, 0},    // ECSTASY
    {255, 165, 0},    // ADMIRATION
    {0, 255, 255},    // TERROR
    {0, 255, 127},    // FEAR
    {0, 139, 69},     // APPREHENSION
    {0, 255, 255},    // AMAZEMENT
    {0, 191, 255},    // SURPRISE
    {224, 255, 255},  // DISTRACTION
    {70, 130, 180},   // PENSIVENESS
    {0, 0, 255},      // SADNESS
    {139, 0, 139},    // BOREDOM
    {128, 0, 128},    // DISGUST
    {255, 0, 255},    // GRIEF
    {255, 140, 0},    // ANNOYANCE
    {255, 0, 0},      // ANGER
    {139, 0, 0},      // RAGE
    {255, 140, 0},    // INTEREST
    {255, 69, 0},     // ANTICIPATION
    {255, 0, 0},      // VIGILANCE
    {0, 0, 0},        //OPTIMISM
    {0, 0, 0},        //LOVE
    {0, 0, 0},        //SUBMISSION
    {0, 0, 0},        //AWE
    {0, 0, 0},        //DISAPPROVAL
    {0, 0, 0},        //REMORSE
    {0, 0, 0},        //CONTEMPT
    {0, 0, 0}         //AGGRESSIVENESS
};

void callback(){}

//ros::Subscriber sub = nh.subscribe("/utbots/display_emotions/emotion", 1000);
//ros::Subscriber<std_msgs::UInt16> face_sub();

void change_color(int color){
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[color].r,colorMap[color].g,colorMap[color].b));
    } 
    leds.show(); 
}

// callback to read emotion request
void callback(const std_msgs::String &msg)
{
  emotion_name = msg.data;
  Serial.println(emotion_name);

  if (emotion_name == "annoyance")
  {
  }
  else if (emotion_name == "much_annoyance")
  {
  }
  else if (emotion_name == "anger")
  {
  }
  else if (emotion_name == "rage")
  {
  }
  else if (emotion_name == "interest")
  {
  }
  else if (emotion_name == "much_interest")
  {
  }
  else if (emotion_name == "anticipation")
  {
  }
  else if (emotion_name == "vigilance")
  {
  }
  else if (emotion_name == "boredom")
  {
  }
  else if (emotion_name == "much_boredom")
  {
  }
  else if (emotion_name == "disgust")
  {
  }
  else if (emotion_name == "loathing")
  {
  }
  else if (emotion_name == "apprehension")
  {
  }
  else if (emotion_name == "much_apprehension")
  {
  }
  else if (emotion_name == "fear")
  {
  }
  else if (emotion_name == "terror")
  {
  }
  else if (emotion_name == "serenity")
  {
  }
  else if (emotion_name == "much_serenity")
  {
  }
  else if (emotion_name == "joy")
  {
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[JOY].r,colorMap[JOY].g,colorMap[JOY].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "ecstasy")
  {
  }
  else if (emotion_name == "pensiveness")
  {
  }
  else if (emotion_name == "much_pensiveness")
  {
  }
  else if (emotion_name == "sadness")
  {
  }
  else if (emotion_name == "grief")
  {
  }
  else if (emotion_name == "distraction")
  {
  }
  else if (emotion_name == "much_distraction")
  {
  }
  else if (emotion_name == "surprise")
  {
  }
  else if (emotion_name == "amazement")
  {
  }
  else if (emotion_name == "acceptance")
  {
  }
  else if (emotion_name == "much_acceptance")
  {
  }
  else if (emotion_name == "trust")
  {
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[TRUST].r,colorMap[TRUST].g,colorMap[TRUST].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "admiration")
  {
  }
  else if (emotion_name == "idle")
  {
  }
  else{

  }
}

void setup() {
  Serial.begin(57600);
  nh.initNode();
  ros::Subscriber<std_msgs::String> sub("/utbots/display_emotions/emotion", callback);
  nh.subscribe(sub);
  leds.begin(); 
  leds.clear(); 
}

void loop() {
  /*for(int color = SERENITY; color < NUM_COLORS; color++){ 
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[color].r,colorMap[color].g,colorMap[color].b));
    } 
    leds.show();   
    delay(10000);
  }*/
  for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(10, 10, 10));
  }

  leds.show();   

  nh.spinOnce();
  delay(100);
} 
  
