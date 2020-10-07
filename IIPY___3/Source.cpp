#include<iostream>
#include<Windows.h>
#include<winbase.h>
#include<powrprof.h>
#pragma comment(lib, "PowrProf.lib")
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//AC power - переменный ток
	SYSTEM_POWER_STATUS status;
	while (1) {
		if (!GetSystemPowerStatus(&status)) {
			cout << GetLastError() << endl;
		}
		else {

			cout << "Режим питания:";
			int powerMode = status.ACLineStatus;
			if (powerMode == 0) {
				cout << "питание от аккумулятора" << endl;
			}
			else if (powerMode == 1) {
				cout << "питание от сети" << endl;
			}
			else {
				cout << "Unknown status" << endl;
			}
			////////////////////////////////////
			cout << "Уровень заряда батареи(%):";
			int life = status.BatteryLifePercent;
			cout << life << "%" << endl;
			////////////////////////////////////
			cout << "Текущий режим энергосбережения:";
			int energyStatus = status.SystemStatusFlag;
			if (energyStatus == 0) {
				cout << "Режим энергосбережения выключен." << endl;
			}
			else if (energyStatus == 1) {
				cout << "Экономия заряда батареи включена. По возможности экономьте энергию." << endl;
			}
			////////////////////////////////////
			//вывести время работы акк - ро(без подключения к сети питания(без зарядки)
			cout << "Время работы аккумулятора:";
			unsigned long int batteryLifeSeconds = status.BatteryLifeTime;
			if (batteryLifeSeconds) {
				cout << "Аккумулятор будет работать - " << batteryLifeSeconds / 3600 <<
					"h:" << batteryLifeSeconds % 3600 / 60 << "min:" << batteryLifeSeconds % 3600 % 60 <<
					"sec" << endl;
			}
			else {
				cout << "Количество секунд неизвестно || устройство подключено к источнику питания" << endl;
			}

		}
		Sleep(777);
		Sleep(777);

		cout << "Выберите режим:\n1-спящий режим\n2-режим гибернации\n3-выход\n";
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