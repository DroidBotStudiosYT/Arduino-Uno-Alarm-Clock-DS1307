# Arduino-Uno-Alarm-Clock-DS1307

Welp, this is the official Arduino Uno DS1307 alarm clock v0.1, I will be updating this occasionally, probably every month

# What you need to do

Navagate to the Code folder, there you will find 2 (currently) files, the first one, SetTime, will be you setting up your DS1307 RTC module, and you will find another file in the Circuit Wiring folder which includes a screenshot of how the DS1307 should be connected to the Arduino Uno.
Next, you have to navagate in the Code folder to the ReadTimeTest sketch, which is what you will need in order to make the DS1307 RTC module display the time and date correctly on the Serial Monitor, by clicking Tools then Serial Monitor (on macOS).
For the complete alarm clock which I will be updating occasionally, the code is in the Advanced 1 folder, and just download the zip and you should be able to use the code by navagating to Finder, where ever you downloaded the zip file then click the zip file, open the folder, navagate Advanced 1, then alarmclock full.ino

# Components and Where to Buy them

Arduino Uno Rev3 - https://store.arduino.cc/usa/arduino-uno-rev3 

or just searching it on amazon - https://www.amazon.com/s?k=arduino+uno+r3&ref=nb_sb_noss_2

Jumper Wires - Male to Female - https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_3?crid=23I032A6EL13Q&dchild=1&keywords=male+to+female+jumper+wires&qid=1594099

DS1307 RTC - https://www.amazon.com/Diymore-AT24C32-Arduino-Without-Battery/dp/B01IXXACD0/ref=sr_1_9?crid=1FL5B7655JPE8&dchild=1&keywords=ds1307+real+time+clock+module&qid=1594099800&sprefix=ds1307+%2Caps%2C210&sr=8-9

DS1307 Tiny RTC - https://www.newegg.com/p/1FS-000H-00R45?item=9SIA7BF2K28048&nm_mc=knc-googleadwords&cm_mmc=knc-googleadwords-_-eco%20gadgets-_-elekool-_-9SIA7BF2K28048&source=region

830 tie points breadboard - https://www.amazon.com/BB830-Solderless-Plug-BreadBoard-tie-Points/dp/B0040Z4QN8/ref=sr_1_5?crid=2S1TJIN8AOGDF&dchild=1&keywords=830+tie+point+breadboard&qid=1594147839&sprefix=830+tie%2Caps%2C212&sr=8-5

I recommend this breadboard, because it has good connections, the wires are really easy to plug in, and get out, also, try avoiding cheap ELEGOO breadboards (they are crap)

Potentiometer - https://www.amazon.com/Linear-Rotary-Potentiometer-JST-XH2-54-Connector/dp/B071X4DKV7/ref=sr_1_3?dchild=1&keywords=potentiometer+10k&qid=1594147967&sr=8-3

You will only be using one 10k potentiometer

Liquid Crystal Display Module - https://www.amazon.com/KEYESTUDIO-Display-Arduino-Raspberry-Stm32/dp/B0177XQE7K/ref=sr_1_2?crid=1UQMXMWGBCOYN&dchild=1&keywords=liquid+crystal+display+arduino&qid=1594148023&sprefix=liquid+crystal+display+%2Caps%2C210&sr=8-2

Push Buttons - https://www.amazon.com/co-rode-tacto-Interruptor-bot%C3%B3n-100-unidades/dp/B00W0YUV1W/ref=sr_1_3?crid=WCIJQPEHHIGN&dchild=1&keywords=arduino+push+button&qid=1594148075&sprefix=arduino+push+%2Caps%2C206&sr=8-3

This link is to a 100 push button pack, which I have myself, and later when you get more advanced, you will have to be able to have more push buttons, even matrix keypads.

Resistors - https://www.amazon.com/Elegoo-Values-Resistor-Assortment-Compliant/dp/B072BL2VX1/ref=sr_1_3?dchild=1&keywords=arduino+resistors&qid=1594148174&sr=8-3

This is a kit of assorted resistors, you will be needing way more resistors as you get into more advanced projects, I recommended ELEGOO's stuff this time because their resistors aren't as crappy as the breadboards.

# What you should expect

For the first SetTime sketch, after you run it, just open your Serial Monitor and you should see 2 lines of text, one of them is for the time on your PC, if you don't click on the trouble-shooting folder above and go to "SetTime error" or just open ONE issue on github.

Now, the second ReadTime sketch, same thing, open your Serial Monitor and you should get a pretty clear result of the time, updating itself each second. If not, it would either say check your circuitry, or it could tell you to run the SetTime sketch again, which is what you should run first.


