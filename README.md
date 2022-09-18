# notfine
#https://hackaday.io/rattinp
Some time ago they installed a speed control radar on the road to my work, which is 10 km from the city, the municipality located the device where there are no longer homes or schools, which in some way added to the lack of reducers of speed, the limit of 45Kmts/h and the scarce signaling, has turned it, at least in my case, into a kind of booby trap.

Personally, I have always been in favor of this type of control and this text is not intended to discourage their use or promote a discussion about the relevance of places, or to advocate any anti-system discourse.

Specifically, I need a solution that would put me on alert when arriving in this area so as not to become a perpetual collaborator of the municipality and a flagrant transgressor of traffic regulations. The use of radar detection devices is considered illegal in some places, so it was totally discarded, opting for the use of geographic coordinates obtained from a low-cost GPS module with integrated antenna from the firm V KEL, vk2828u7g5lf that I acquired for US$11.=

Of course, there are applications that perform this task, but all of them entail the need to keep them active, as well as enable certain configurations on the phone, which is not always possible and can lead to forgetfulness.

The solution should be totally unattended, starting to work with the ignition of the car, so you choose to connect it to the cigarette lighter socket, it should also show sound and light alerts in the style of a traffic light. The blue color would indicate that the vehicle is outside the radar zone, while the yellow would start to pick up accompanied by a vibration when the distance to the radar was less than 500 meters, finally the red would do so at distances less than 200 meters.

I used an arduino nano clone, the GPS module, and a Neopixel led, for the program I slightly modified an example from the TinyGPs++ library.

The accuracy of the module in motion is not very good and it takes a few seconds on initial startup, however, for this application where the margin of error can be high without changing the end result, it works perfectly. 
