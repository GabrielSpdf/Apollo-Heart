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
    ECSTASY,

    ACCEPTANCE,
    TRUST,    
    ADMIRATION,

    APPREHENSION,
    FEAR,
    TERROR,     

    DISTRACTION,
    SURPRISE,
    AMAZEMENT,  

    PENSIVENESS,
    SADNESS,
    GRIEF,

    BOREDOM,
    DISGUST,
    LOATHING,

    ANNOYANCE,  
    ANGER,
    RAGE,

    INTEREST,
    ANTICIPATION, 
    VIGILANCE,

    NUM_COLORS
};

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};



RGB colorMap[NUM_COLORS] = {
    {255, 255, 51},  // SERENITY
    {230, 230, 30},   // JOY
    {204, 204, 0},    // ECSTASY

    {119, 221, 119},  // ACCEPTANCE
    {17, 170, 42},    // TRUST
    {102, 204, 0},    // ADMIRATION

    {102, 102, 0},     // APPREHENSION
    {76, 153, 0},    // FEAR
    {0, 255, 0},    // TERROR

    {153, 204, 255},  // DISTRACTION
    {51, 153, 255},    // SURPRISE
    {0, 102, 204},    // AMAZEMENT

    {102, 102, 255},   // PENSIVENESS
    {0, 0, 255},      // SADNESS
    {0, 0, 153},    // GRIEF

    {255, 51, 255},    // BOREDOM
    {204, 0, 204},    // DISGUST
    {102, 0, 102},     //LOATHING

    {255, 102, 102},    // ANNOYANCE
    {255, 51, 51},      // ANGER
    {255, 0, 0},      // RAGE

    {255, 215, 0},    // INTEREST
    {255, 165, 0},     // ANTICIPATION
    {153, 76, 0}      // VIGILANCE
};





void callback(){}

//ros::Subscriber sub = nh.subscribe("/utbots/display_emotions/emotion", 1000);
//ros::Subscriber<std_msgs::UInt16> face_sub();

//String -> Enum

void change_color(String emotionName){
    
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(1,2,3));
    } 
    leds.show(); 
    delay(1000);
}

// callback to read emotion request
void callback(const std_msgs::String &msg)
{
  emotion_name = msg.data;
  Serial.println(emotion_name);

  if (emotion_name == "annoyance")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ANNOYANCE].r,colorMap[ANNOYANCE].g,colorMap[ANNOYANCE].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_annoyance")
  {
  }
  else if (emotion_name == "anger")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ANGER].r,colorMap[ANGER].g,colorMap[ANGER].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "rage")
  {
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[RAGE].r,colorMap[RAGE].g,colorMap[RAGE].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "interest")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[INTEREST].r,colorMap[INTEREST].g,colorMap[INTEREST].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_interest")
  {
  }
  else if (emotion_name == "anticipation")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ANTICIPATION].r,colorMap[ANTICIPATION].g,colorMap[ANTICIPATION].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "vigilance")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[VIGILANCE].r,colorMap[VIGILANCE].g,colorMap[VIGILANCE].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "boredom")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[BOREDOM].r,colorMap[BOREDOM].g,colorMap[BOREDOM].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_boredom")
  {
  }
  else if (emotion_name == "disgust")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[DISGUST].r,colorMap[DISGUST].g,colorMap[DISGUST].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "loathing")
  {
    
    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[LOATHING].r,colorMap[LOATHING].g,colorMap[LOATHING].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "apprehension")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[APPREHENSION].r,colorMap[APPREHENSION].g,colorMap[APPREHENSION].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_apprehension")
  {
  }
  else if (emotion_name == "fear")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[FEAR].r,colorMap[FEAR].g,colorMap[FEAR].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "terror")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[TERROR].r,colorMap[TERROR].g,colorMap[TERROR].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "serenity")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[SERENITY].r,colorMap[SERENITY].g,colorMap[SERENITY].b));
    } 
    leds.show(); 
    delay(1000);
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

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ECSTASY].r,colorMap[ECSTASY].g,colorMap[ECSTASY].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "pensiveness")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[PENSIVENESS].r,colorMap[PENSIVENESS].g,colorMap[PENSIVENESS].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_pensiveness")
  {
  }
  else if (emotion_name == "sadness")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[SADNESS].r,colorMap[SADNESS].g,colorMap[SADNESS].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "grief")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[GRIEF].r,colorMap[GRIEF].g,colorMap[GRIEF].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "distraction")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[DISTRACTION].r,colorMap[DISTRACTION].g,colorMap[DISTRACTION].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "much_distraction")
  {
  }
  else if (emotion_name == "surprise")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[SURPRISE].r,colorMap[SURPRISE].g,colorMap[SURPRISE].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "amazement")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[AMAZEMENT].r,colorMap[AMAZEMENT].g,colorMap[AMAZEMENT].b));
    } 
    leds.show(); 
    delay(1000);
  }
  else if (emotion_name == "acceptance")
  {

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ACCEPTANCE].r,colorMap[ACCEPTANCE].g,colorMap[ACCEPTANCE].b));
    } 
    leds.show(); 
    delay(1000);
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

    for(i = 0; i < NUM_LEDS; i++) {   
      leds.setPixelColor(i, leds.Color(colorMap[ADMIRATION].r,colorMap[ADMIRATION].g,colorMap[ADMIRATION].b));
    } 
    leds.show(); 
    delay(1000);
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
  