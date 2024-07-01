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
  int intensity;
};

// Number of colors defined
const int NUM_COLORS = 32;

// Array to map colors to emotions
RGB colorMap[NUM_COLORS] = {
	{254, 255, 191, "serenity", 0}, 
  {253, 255, 113, "much_serenity", 1},
	{252, 255, 1, "joy", 2},
	{255, 222, 1, "ecstasy", 3},

	{255, 255, 0, "acceptance", 0},
  {166, 255, 101, "much_acceptance", 1},
	{105, 248, 0, "trust", 2},
	{79, 186, 0, "admiration", 3},

	{182, 230, 194, "apprehension", 0},
  {78, 196, 108, "much_apprehension", 1},
	{17, 163, 55, "fear", 2},
	{0, 140, 36, "terror", 3},

	{197, 234, 247, "distraction", 0},
  {143, 215, 239, "much_distraction", 1},
	{1, 210, 255, "surprise", 2},
	{0, 184, 224, "amazement", 3},

	{190, 187, 243, "pensiveness", 0},
  {124, 119, 231, "much_pensiveness", 1},
	{103, 97, 227, "sadness", 2},
	{11, 0, 224, "grief", 3},

	{247, 197, 233, "boredom", 0},
  {255, 145, 225, "much_boredom", 1},
	{255, 1, 186, "disgust", 2},
	{216, 0, 158, "loathing", 3},

	{255, 194, 206, "annoyance", 0},
  {255, 101, 112, "much_annoyance", 1},
	{255, 1, 19, "anger", 2},
	{204, 52, 63, "rage", 3},
  
	{247, 185, 135, "interest", 0},
  {255, 162, 87, "much_interest", 1},
	{255, 128, 25, "anticipation", 2},
	{220, 98, 0, "vigilance", 3}
};

// Function to change the LED color based on the emotion
void change_color(const std_msgs::String& msg){
	for(i = 0; i < NUM_COLORS; i++){
		if(strcmp(msg.data, colorMap[i].emotion) == 0){
      int start = i - (i % 4);
      int until = start + colorMap[i].intensity;

      //for(int k = start; k < until; k++){
        uint8_t r = colorMap[i].r;
        uint8_t g = colorMap[i].g;
        uint8_t b = colorMap[i].b;      

        // Set the color for each LED in the ring
        for (int j = 0; j < NUM_LEDS; j++){
            leds.setPixelColor(j, leds.Color(r, g, b));
        }

        //delay(3000);
        leds.show();
        delay(1500);
      //}

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


