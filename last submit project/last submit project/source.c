#include <stdio.h>
#include <stdlib.h>

long long rep1[15] = { 1234320, 2343210, 3432120, 4321230 , 3212340 , 1234320 , 4321230 , 2123430 , 4321230 , 1234320 , 3212340 , 4321230 , 3432120 , 2343210  , 1234320 }; //16번째부터는 15개를 간격으로 앞부분이 반복됨
long long int result = 0; //현재의 나머지
long long int arr[15] = { 1, 2, 3, 4, 32, 123, 43, 2123, 432, 1234, 32123, 43212, 34321, 23432, 123432 }; //1~15번째의 반복되는 수 집합
long long int tmp[15]; //^7을 해줄때 임시적으로 저장해줄 변수

int main() {
	int checknum = 15; //디버깅용 몇바퀴돌았는지(삭제필요함)
	const int mod = 123454321; //나눠줘야할 수
	int i, j;
	int r = 1; //한바퀴 돌때 이전의 값을 찾아줄 변수
	int id; //저장할 개인의 고유 번호
	for (i = 0; i <= 14; i++) {
		result += arr[i]; //반복 시작전까지 더해줘서 나머지 세팅값 만들기
	}

	for (j = 1; j <= 15; j++) {
		id = j;
		tmp[id] = (rep1[id - 1]) % mod; //15번째부터 반복되는 집합을 순서대로 %mod 해준다. * 15
		if ((j == 5) || (j == 7)) {
			result = ((arr[j - 1] + tmp[id] * 10) + result) % mod; //이 경우에는 십의자리를 더한다.
		}
		else if ((j == 6) || (j == 9)) {
			result = ((arr[j - 1] + tmp[id] * 100) + result) % mod; //이 경우에는 백의자리를 더한다.
		}
		else if ((j == 8) || (j == 10)) {
			result = ((arr[j - 1] + tmp[id] * 1000) + result) % mod; //이 경우에는 천의자리를 더한다.
		}
		else if ((j >= 11) && (j <= 14)) {
			result = ((arr[j - 1] + tmp[id] * 10000) + result) % mod; //이 경우에는 만의자리를 더한다.
		}
		else if (j == 15) {
			result = ((arr[j - 1] + tmp[id] * 100000) + result) % mod; //이 경우에는 십만자리를 더한다.
		}
		else {
			result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + 기존의 나머지
		}
		checknum++;
	}
	for (j = 16; j <= 985; j++) {
		id = j;
		tmp[id - (r * 15)] = (((tmp[id - (r * 15)] * 1000000) % mod + (rep1[j - (r * 15) - 1] % mod))) % mod; //30번째부터는 앞에서 나누었던 값을 가지고와서 long long int 안에 들어가게한다.
		if (((j % 15) == 5) || ((j % 15) == 7)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 10) + result) % mod; //이 경우에는 십의자리를 더한다.
		}
		else if (((j % 15) == 6) || ((j % 15) == 9)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 100) + result) % mod; //이 경우에는 백의자리를 더한다.
		}
		else if (((j % 15) == 8) || ((j % 15) == 10)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 1000) + result) % mod; //이 경우에는 천의자리를 더한다.
		}
		else if (((j % 15) >= 11) && ((j % 15) <= 14)) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 10000) + result) % mod; //이 경우에는 만의자리를 더한다.
		}
		else if ((j % 15) == 0) {
			result = ((arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] * 100000) + result) % mod; //이 경우에는 십만자리를 더한다.
		}
		else {
			result = (arr[j - 1 - (r * 15)] + tmp[id - (r * 15)] + result) % mod; //arr + rep + 기존의 나머지
		}
		checknum++;
		if (j % 15 == 0) {
			r++;
		}
	}
	printf("(%d, '=>', %lld)\n", checknum, result);
	return 0;
}