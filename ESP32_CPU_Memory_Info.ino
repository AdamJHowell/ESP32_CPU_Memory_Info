/*
The chipId portion is based on the GetChipID example sketch which is installed in the Arduino IDE once ESP32 board support is added.
*/

unsigned long lastPrint = 0;				// This is used to determine the time since last MQTT publish.
unsigned long printDelay = 20000;		// The minimum time between loop() function stat publishing.
uint32_t chipId = 0;							// Holds the CPU ID, e.g. 12734324.
const int LED_PIN_1 = 2;					// Set this to the GPIO of the first LED.
const int LED_PIN_2 = 16;					// Set this to the GPIO of the second LED.  If the board has only one LED, set this to the value of LED_PIN_1


void setup()
{
	// This delay gives me time to open the serial console after reflashing.
	delay( 500 );

	Serial.begin( 115200 );
	if( !Serial )
		delay( 1000 );
	Serial.setDebugOutput( true );
	Serial.println();

	Serial.println( "The setup() function has begun." );
	Serial.printf( "Stats will be printed every %lu millisecond.\n", printDelay );

	// Enable the LEDs and turn them on.
	pinMode( LED_PIN_1, OUTPUT );
	digitalWrite( LED_PIN_1, HIGH );
	// pinMode( LED_PIN_2, OUTPUT );
	// digitalWrite( LED_PIN_2, HIGH );

	printStats();

	Serial.println( "The setup() function has completed.\n" );
} // End of setup() function.


void printStats()
{
	Serial.print( "Source file: " );
	Serial.println( __FILE__ );

	for( int i = 0; i < 17; i = i + 8 )
	{
		chipId |= ( ( ESP.getEfuseMac() >> (40 - i) ) & 0xff ) << i;
	}

	// Most of the ESP.get* functions are defined in esp.h for the appropriate ESP32 chip.
	Serial.printf( "ESP32 Chip model: %s\n", ESP.getChipModel() );
	Serial.printf( "  Revision: %d\n", ESP.getChipRevision() );
	Serial.printf( "  Core count: %d\n", ESP.getChipCores() );
	Serial.printf( "  Chip ID: %u\n", chipId );
	Serial.print( "  Frequency: " );
  Serial.println( ESP.getCpuFreqMHz() );
	Serial.printf( "  Cycle count: %u\n", ESP.getCycleCount() );
	Serial.printf( "  SDK version: %s\n", ESP.getSdkVersion() );

	Serial.println( "Heap: " );
	Serial.printf( "  Total: %u\n", ESP.getHeapSize() );
	Serial.printf( "  Used: %u\n", ESP.getHeapSize() - ESP.getFreeHeap() );
	Serial.printf( "  Free: %u\n", ESP.getFreeHeap() );
	Serial.printf( "  Largest block: %u\n", ESP.getMaxAllocHeap() );
	Serial.printf( "  Minimum free since boot: %u\n", ESP.getMinFreeHeap() );

	Serial.println( "Flash: " );
	Serial.printf( "  Total: %u\n", ESP.getFlashChipSize() );
	Serial.printf( "  Speed: %u\n", ESP.getFlashChipSpeed() );

	// None of the boards I tried supported these functions.
	//Serial.println( "?Magic? Flash: " );
	//Serial.printf( "  Total: %u\n", ESP.magicFlashChipSize() );
	//Serial.printf( "  Speed: %u\n", ESP.magicFlashChipSpeed() );

	Serial.println( "Sketch: " );
	Serial.printf( "  Size: %u\n", ESP.getSketchSize() );
	Serial.printf( "  Free: %u\n", ESP.getFreeSketchSpace() );

	if( psramFound() )
	{
		Serial.println( "PSRAM: " );
		Serial.printf( "  Total: %u\n", ESP.getPsramSize() );
		Serial.printf( "  Used: %u\n", ESP.getPsramSize() - ESP.getFreePsram() );
		Serial.printf( "  Free: %u\n", ESP.getFreePsram() );
		Serial.printf( "  Largest block: %u\n", ESP.getMaxAllocPsram() );
		Serial.printf( "  Minimum free since boot: %u\n", ESP.getMinFreePsram() );
	}
	else
		Serial.println( "This device lacks PSRAM." );
} // End of printStats() function.


void loop()
{
	unsigned long currentTime = millis();
	if( currentTime - lastPrint >= printDelay )
	{
		printStats();
		lastPrint = millis();
		Serial.print( "Next printout in " );
		Serial.print( printDelay / 1000 );
		Serial.println( " seconds.\n\n" );
	}
} // End of loop() function.
