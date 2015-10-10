#include "TopOpt.h"
#include <stdio.h>
#include <memory>

void PressEnterToContinue()
{
	int c;
	printf("Press ENTER to continue... ");
	fflush(stdout);
	do c = getchar(); while ((c != '\n') && (c != EOF));
}

int main() {
	const auto eX = 120;
	const auto eY = 40;
	const auto volFrac = .5;
	const auto penal = 3.0;
	const auto rmin = 3.0;
	const auto maxChange = .01;

	
	
auto topOpt = std::make_unique<TopOpt>(eX,eY,volFrac,penal,rmin,maxChange);

double compliance, volume, change;
bool go = true;

while (go) {
	go = topOpt->step(compliance, volume, change, true);
}
topOpt->exportResults();
PressEnterToContinue();
return 0;
}

