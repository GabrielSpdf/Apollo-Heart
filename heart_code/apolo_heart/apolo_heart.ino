#include "Adafruit_NeoPixel.h"  // Library for controlling NeoPixel LEDs
#include <ros.h>                // ROS (Robot Operating System) library
#include <std_msgs/UInt16.h>    // ROS standard message library for UInt16
#include "std_msgs/String.h"    // ROS standard message library for String

// Define constants
#define LED_PIN  5 			  // Digital pin connected to "DIN" of WS2812 module
#define NUM_LEDS 16 		  // Number of LEDs in the WS2812 module
#define BRIGHTNESS 255 		// LED brightness (0 to 255)

// Create a ROS string message
std_msgs::String str_msg;

// Create a ROS publisher
ros::Publisher chatter("chatter", &str_msg);

// Create a ROS node handle
ros::NodeHandle  nh;

// Variable to identify the position of the LED in the ring (0 to 15)
int i;                                         

// Create an instance of Adafruit_NeoPixel for controlling the LEDs
Adafruit_NeoPixel leds(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Structure to store RGB values and associated emotion
struct RGB{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	const char* emotion;
};

// Number of colors defined
const int NUM_COLORS = 24;

// Array to map colors to emotions
RGB colorMap[NUM_COLORS] = {
	{255, 255, 51, "serenity"},
	{230, 230, 30, "joy"},
	{204, 204, 0, "ecstasy"},
	{119, 221, 119, "acceptance"},
	{17, 170, 42, "trust"},
	{102, 204, 0, "admiration"},
	{102, 102, 0, "apprehension"},
	{76, 153, 0, "fear"},
	{0, 255, 0, "terror"},
	{153, 204, 255, "distraction"},
	{51, 153, 255, "surprise"},
	{0, 102, 204, "amazement"},
	{102, 102, 255, "pensiveness"},
	{0, 0, 255, "sadness"},
	{0, 0, 153, "grief"},
	{255, 51, 255, "boredom"},
	{204, 0, 204, "disgust"},
	{102, 0, 102, "loathing"},
	{255, 102, 102, "annoyance"},
	{255, 51, 51, "anger"},
	{255, 0, 0, "rage"},
	{255, 215, 0, "interest"},
	{255, 165, 0, "anticipation"},
	{153, 76, 0, "vigilance"}
};

// Function to change the LED color based on the emotion
void change_color(const std_msgs::String& msg){
	for(int i = 0; i < NUM_COLORS; i++){
		if(strcmp(msg.data, colorMap[i].emotion) == 0){
			uint8_t r = colorMap[i].r;
			uint8_t g = colorMap[i].g;
			uint8_t b = colorMap[i].b;
      

      // Set the color for each LED in the ring
			for (int j = 0; j < NUM_LEDS; j++){
				leds.setPixelColor(j, leds.Color(r, g, b));
			}
      
      delay(3200);
			leds.show();
			delay(2000);
			return;
		}
	}
}

// Callback function for the ROS subscriber
void callback(const std_msgs::String& msg)
{	
	change_color(msg);
}

void setup(){
	Serial.begin(57600);   // Start serial communication
	nh.initNode();         // Initialize ROS node

  // Create a ROS subscriber to listen for emotion messages
	ros::Subscriber<std_msgs::String> sub("/utbots/display_emotions/emotion", callback);

	nh.subscribe(sub);   // Subscribe to the topic
	leds.begin();        // Initialize the LED strip
	leds.clear();        // Clear any previous LED colors
}

void loop(){
  // Set a default color for each LED in the ring
	for(i = 0; i < NUM_LEDS; i++){   
		leds.setPixelColor(i, leds.Color(10, 10, 10));
	}

	leds.show();      // Update the LED colors

	nh.spinOnce();    // Handle ROS communication
	delay(100);       // Wait for 100 milliseconds

  //change_color("rage");
  //delay(2000);
}

