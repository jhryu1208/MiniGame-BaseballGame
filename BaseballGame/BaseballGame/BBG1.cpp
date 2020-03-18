#include <iostream>
#include <time.h>

using namespace std;

enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

int main()
{
	//난수테이블 생성
	srand((unsigned int)time(0));

	int iPlayer, iAI;

	while (true)
	{
		cout << "1. 가위" << endl;
		cout << "2. 바위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 :" << endl;

		cin >> iPlayer;

		if (iPlayer<SRP_S || iPlayer>SRP_END)
		{
			cout << "잘못된 값을 입력하였습니다." << endl;
			//일시정지
			system("pause");
			//continue : 반복문의 시작점으로 이동시켜주는 기능
			continue;
		}

		else if (iPlayer == SRP_END)
			break;

		// 봇이 선택한다.
		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S:
			cout << "AI : 가위" << endl;
			break;

		case SRP_R:
			cout << "AI : 바위" << endl;
			break;

		case SRP_P:
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		/*
		if (iWin == 1 || iWin == -2)
			cout << "Player의 승리" << endl;
		else if (iWin == 0)
			cout << "비겼습니다" << endl;
		else
			cout << "AI의 승리" << endl;
		*/

		switch (iWin)
		{
		case 1:
		case -2:
			cout << "player의 승리" << endl;
			break;

		case 0:
			cout << "비겼습니다" << endl;
			break;

		default:
			cout << "AI의 승리" << endl;
			break;

		}
		// system("pause");
		// 이건 "계속하려면 아무 키나 누르십시오.." 라는 문구를 띄워주는 함수이다.
		// 이 함수를 통해서 프로그램을 잠시 멈추고, 시작하고 싶을때 시작할 수 있다.
		system("pause");
	}
	return 0;
}