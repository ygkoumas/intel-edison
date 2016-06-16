#include "mraa.hpp"
#include <iostream>
#include <unistd.h>

static volatile int counter = 0;
static volatile int recounter = 0;
char increased[10] = "increased";

// ISR, update the value of the counter
void interrupt(void * args) {
	++counter;
}

int main() {
	// create a GPIO object from MRAA
	mraa::Gpio d_pin(2);

	// set the pin as input
	d_pin.dir(mraa::DIR_IN);

	// set the ISR
	d_pin.isr(mraa::EDGE_BOTH, interrupt, NULL);

	// update the cloud
	for (;;) {
		std::cout << "press button value " << counter << std::endl;
		if (recounter != counter) {
			//trigger the script that updates the cloud.
			system("/home/root/update_cloud.sh");
			std::cout << increased << std::endl;
		}
		recounter=counter;

		sleep(5);
	}

	return mraa::SUCCESS;
}
