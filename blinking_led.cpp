#include "mraa.hpp"
#include <iostream>
#include <unistd.h>

int main() {
	// create a GPIO object from MRAA
	mraa::Gpio* d_pin = new mraa::Gpio(13, true, false);
	d_pin->dir(mraa::DIR_OUT);

	//trigger the script that updates the cloud.
	system("/home/root/update_cloud.sh");

	// loop forever toggling the on board LED every second
	for (;;) {
		d_pin->write(1);
		sleep(1);
		d_pin->write(0);
		sleep(2);
	}

	return 0;
}
