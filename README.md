## Details

We embarked on this project to have access control and tracking over equipment at the CoMotion MakerSpace @ University of Washington. For this we use Fabman, a SaaS/Hardware as a Service which gives us authentication and authorization over equipment in the MakerSpace. Being a MakerSpace in the university, a lot of the equipment we use are hand-me-downs from industry. Though possible for the smaller machines, we didn't feel comfortable passing so many watts through the Fabman Bridge for some of our equipment (specifically our massive red Universal laser cutter), and instead wanted to use a USB solution where we could programmatically control a USB port and thus the communication between the user and the equipment.

Enter this hacked USB switch which an Arduino acts as an interface to:
![Arduino, USB Switch](media/arduino_switch.jpg?raw=true "Arduino, USB Switch")

Using the on-board relay of the Fabman bridge, we're able to determine whether or not access has been granted to the equipment. Our requirements are as follows:
* When access isn't granted, we ensure the USB switch is switched to a port that's disconnected from the equipment. 
* If access is granted, the USB switch is switched to the port with the equipment attached and the user is able to use the machine.

With the way we setup the hardware connections, the code to ensure the switch is on the correct port is remarkably simple and elegant:
![Code Sample](media/code_sample.png?raw=true "Code Sample")
if the relay and the led aren't the same value, we press the button, which makes them the same value. This occurs whenever the state of the relay (which is controlled by the Fabman bridge), changes.

## Guide
# TODO