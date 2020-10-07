#include<iostream>
#include<Windows.h>
#include<winbase.h>
#include<powrprof.h>
#pragma comment(lib, "PowrProf.lib")
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//AC power
	SYSTEM_POWER_STATUS status;
	while (1) {
		if (!GetSystemPowerStatus(&status)) {
			cout << GetLastError() << endl;
		}
		else {

			cout << "Power mode:";
			int powerMode = status.ACLineStatus;
			if (powerMode == 0) {
				cout << "battery powered" << endl;
			}
			else if (powerMode == 1) {
				cout << "AC power" << endl;
			}
			else {
				cout << "Unknown status" << endl;
			}
			////////////////////////////////////
			cout << "Battery level(%):";
			int life = status.BatteryLifePercent;
			cout << life << "%" << endl;
			////////////////////////////////////
			cout << "Current power saving mode:";
			int energyStatus = status.SystemStatusFlag;
			if (energyStatus == 0) {
				cout << "Power saving mode is disabled." << endl;
			}
			else if (energyStatus == 1) {
				cout << "Battery saving is enabled. Save energy whenever possible." << endl;
			}
			////////////////////////////////////
			
			cout << "Battery life:";
			unsigned long int batteryLifeSeconds = status.BatteryLifeTime;
			if (batteryLifeSeconds) {
				cout << "The battery will work - " << batteryLifeSeconds / 3600 <<
					"h:" << batteryLifeSeconds % 3600 / 60 << "min:" << batteryLifeSeconds % 3600 % 60 <<
					"sec" << endl;
			}
			else {
				cout << "The number of seconds is unknown || the device is connected to a power source" << endl;
			}

		}
		Sleep(777);
		Sleep(777);

		cout << "Choose mode:\n1-sleep mode\n2-hibernation mode\n3-exit\n";
		char a;
		a = getchar();
		if (a == '1') {
			SetSuspendState(TRUE,FALSE,FALSE);
		}
		else if (a == '2') {
			SetSuspendState(FALSE, FALSE, FALSE);
		}
		else if (a == '3') break;
		Sleep(777);
		Sleep(777);
		Sleep(777);
		Sleep(777);
		Sleep(777);
		system("cls");
	}
	return 0;
}