// or if you need your Adafruit IO key.
#define IO_USERNAME "Tejashree_A"
#define IO_KEY "aio_puUq735wb2RIcVyasQ431TGtlwaD"

#define WIFI_SSID "Silky"
#define WIFI_PASS "Silky1611"
// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
