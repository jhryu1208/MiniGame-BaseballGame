#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	int iNumber[9] = {};

	// 1 ~ 9 까지 숫자를 설정한다.
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	srand((unsigned int)time(0));

	// 설정된 숫자를 섞어준다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	//cout << " * * * " << endl;
	cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl;

	int iStrike = 0, iBall = 0;
	int input[3];

	while (true)
	{
		cout << " 1 ~ 9 사이의 숫자중 숫자 3개를 입력하세요( 0: 종료 ) :";
		cin >> input[0] >> input[1] >> input[2];

		if (input[0] == 0 || input[1] == 0 || input[2] == 0)
			break;
		else if (input[0] < 0 || input[0]>9 || input[1] < 0 || input[1]>9 || input[2] < 0 || input[2]>9)
		{
			cout << " 잘못된 숫자를 입력하였습니다" << endl;
			continue;
		}
		else if (input[0] == input[1] || input[0] == input[1] || input[1] == input[2])
		{
			cout << " 중복된 숫자를 입력하였습니다" << endl;
			continue;
		}

		// 매번 Strike와 Ball의 수가 달라지기 때문에 0으로 초기화하고 다시 계산한다.
		iStrike = iBall = 0;

		// i for문은 맞춰야 할 숫자의 인덱스를 구한다.
		for (int i = 0; i < 3; ++i)
		{
			// j for문은 입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; ++j)
			{
				// i가 0일때 j는 0~2까지 반복하게 된다. 맞춰야할 숫자의
				// 첫번째 값과 입력받은 숫자의 첫번쨰, 두번째, 세번째를 차례대로 비교하여
				// 같은 값이 있는지를 찾아낸다.
				if (iNumber[i] == input[j])
				{
					// 값이 같은것이 있을 경우 Strike 아니면 Ball 이므로 자리가 같은지를 체크해본다.
					// i와 j는 현재 맞춰야할 숫자의 인덱스와 입력받은 숫자의 인덱스이고 두값이 같으므로 이 인덱스가 곧 위치가 된다.
					// 인덱스가 서로 같을 경우는 자리까지 같다는 의미이므로 Strike를 증가시키고,
					// 그게 아니라면 자리가 다르다는 의미이므로 Ball을 증가하게 한다.
					if (i == j)
						++iStrike;
					else
						++iBall;

					// 입력받은 숫자와 맞춰야할 숫자를 비교할 때 같은 수가 있으면,
					// 이 뒤로는 더이상 같은 수가 없으므로 다음 맞춰야할 숫자로
					// 바로 비교하면 된다. 그래서 break를 해서 j for문을 빠져나가고
					// ++i가 되게하여 다음 맞춰야할 숫자와 다시 비교하게 한다.
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			cout << "숫자를 모두 맞췄습니다" << endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
		{
			cout << "Out" << endl;
		}
		else
			cout << iStrike << "Strike" << iBall << "Ball" << endl;
	}

	return 0;