# Esp8266_WIFI_Clock

***Requirements***
  -Esp8266 (nodemcu in this example)
  -4 digit 7 segment display (common anode in this example)(For common cathode just change 1 to 0 and 0 to 1 in byte table[])
  -Shift register 74HC595
  -4 1K resistors

7 Segment digital clock with Nodemcu Esp8266.
Time information is collected from ntp server.
Wifi connection is necessary!

Pros:
  -Time will always automaticly update
  -No need to set the time

Cons:
  -Requires Wifi connection
  -Uses Wifi non-stop (always connectiong to ntp server, might use a lot of data)
  
***Cable Connections***
![ESP8266-with-74HC595-and-4-digit-7-segment](https://user-images.githubusercontent.com/78353929/218495901-1b226f0f-6e47-42d9-94e9-47ba7f039605.jpg)

![Wifi Clock - 0](https://user-images.githubusercontent.com/78353929/218497113-a199b295-1656-4a1d-8fef-9e1034c1f016.jpeg)

![Wifi Clock - 1](https://user-images.githubusercontent.com/78353929/218496933-c6550469-bbe8-45bf-84e2-9f9c7dfac0cf.jpeg)

![Wifi Clock - 2](https://user-images.githubusercontent.com/78353929/218496991-132a31cf-150e-4d6c-9ede-e49e9ca3026d.jpeg)


Thanks to https://microcontrollerslab.com/esp8266-74hc595-4-digit-7-segment-display/ for wiring and https://youtu.be/eBCFda5s6NQ for NTP connections.
