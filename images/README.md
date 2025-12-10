# DUIAlarmClock
Simple alarm clock made with an arduino and raspberry pi setup

Decided to make a small project since I was bored and felt like this would be pretty useful to me. It uses an LCD screen and 3 buttons hooked up to an arduino. ALL tools except the raspberry pi can be
found in the Super Starter Kit UNO R3 Project package. 

*insert picture of arduino and breadboard setup here*

The python script reads the data from the arduino. The left button decrements the timer by 10 seconds; the right increments it by 10 seconds. The far right button sets the alarm in 'activate' mode. When in
'activate' mode, the user clicks both the left and right buttons at the same time to start the timer. 

The python script requires serial, AudioSegment, and play imports in order to use!

The raspbery pi was a bit annoying to setup. I had one in storage that I bought a long time but never used since I didn't have an HDMI cable adapter for it. The SD card slot was also having issues with bootup, so
I had to boot the OS from a USB. The pi is also in low power mode since the pi didn't come with its original power supply adapter :p 

The pi is also connected via bluetooth to an alexa speaker since I don't have any sound modules for now...

Not much else to really say about the project. I'll maybe add some extra features if I come across any other dilemmas with it. 

The current alarm plays '1 for 1 Dimaggio', fire song, but feel free to use any song of your choosing. 
