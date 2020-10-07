#include<iostream>
#include<Windows.h>
#include<winbase.h>
#include<powrprof.h>
#pragma comment(lib, "PowrProf.lib")
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	//AC power - ���������� ���
	SYSTEM_POWER_STATUS status;
	while (1) {
		if (!GetSystemPowerStatus(&status)) {
			cout << GetLastError() << endl;
		}
		else {

			cout << "����� �������:";
			int powerMode = status.ACLineStatus;
			if (powerMode == 0) {
				cout << "������� �� ������������" << endl;
			}
			else if (powerMode == 1) {
				cout << "������� �� ����" << endl;
			}
			else {
				cout << "Unknown status" << endl;
			}
			////////////////////////////////////
			cout << "������� ������ �������(%):";
			int life = status.BatteryLifePercent;
			cout << life << "%" << endl;
			////////////////////////////////////
			cout << "������� ����� ����������������:";
			int energyStatus = status.SystemStatusFlag;
			if (energyStatus == 0) {
				cout << "����� ���������������� ��������." << endl;
			}
			else if (energyStatus == 1) {
				cout << "�������� ������ ������� ��������. �� ����������� ��������� �������." << endl;
			}
			////////////////////////////////////
			//������� ����� ������ ��� - ��(��� ����������� � ���� �������(��� �������)
			cout << "����� ������ ������������:";
			unsigned long int batteryLifeSeconds = status.BatteryLifeTime;
			if (batteryLifeSeconds) {
				cout << "����������� ����� �������� - " << batteryLifeSeconds / 3600 <<
					"h:" << batteryLifeSeconds % 3600 / 60 << "min:" << batteryLifeSeconds % 3600 % 60 <<
					"sec" << endl;
			}
			else {
				cout << "���������� ������ ���������� || ���������� ���������� � ��������� �������" << endl;
			}

		}
		Sleep(777);
		Sleep(777);

		cout << "�������� �����:\n1-������ �����\n2-����� ����������\n3-�����\n";
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