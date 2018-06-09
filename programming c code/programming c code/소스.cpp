#include <stdio.h>

int main() {
	int checknum = 15; //디버깅용 몇바퀴돌았는지(삭제필요함)
	const int mod = 123454321; //나눠줘야할 수
	long long int result = 0; //현재의 나머지
	long long int arr[15] = { 1, 2, 3, 4, 32, 123, 43, 2123, 432, 1234, 32123, 43212, 34321, 23432, 123432 };
	long long int rep1[15] = { 1234320, 2343210, 3432120, 4321230 , 3212340 , 1234320 , 4321230 , 2123430 , 4321230 , 1234320 , 3212340 , 4321230 , 3432120 , 2343210  , 1234320 };
	long long int tmp[15]; //^7을 해줄때 임시적으로 저장해줄 변수
	int i, j;
	int r = 1; //한바퀴 돌때 이전의 값을 찾아줄 변수
	int id; //저장할 개인의 고유 번호
	for (i = 0; i <= 14; i++) {
		result += arr[i]; //반복 시작전까지 더해줘서 나머지 만들기
	}
	//for (i = 1;i <= 65;i++) {
		for (j = 1; j <= 15; j++) {
			id = j;
			tmp[id] = (rep1[id - 1]) % mod;
			if ((j == 5) || (j == 7)) {
				result = ((arr[j - 1] + tmp[id] * 10) + result) % mod; //이 경우에는 십의자리를 더한다.
			}
			else if ((j == 6) || (j == 9)) {
				result = ((arr[j - 1] + tmp[id] * 100)  + result) % mod; //이 경우에는 백의자리를 더한다.
			}
			else if ((j == 8) || (j == 10)) {
				result = ((arr[j - 1] + tmp[id] * 1000)  + result) % mod; //이 경우에는 천의자리를 더한다.
			}
			else if ((j >= 11) && (j <= 14)) {
				result = ((arr[j - 1] + tmp[id] * 10000)  + result) % mod; //이 경우에는 만의자리를 더한다.
			}
			else if (j == 15) {
				result = ((arr[j - 1] + tmp[id] * 100000)  + result) % mod; //이 경우에는 십만자리를 더한다.
			}
			else {
				result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + 기존의 나머지
			}
			checknum++;
			printf("(%d, '=>', %lldL)\n", checknum, result);
		}
		for (j = 16; j <= 1000; j++) {
			id = j;
			tmp[id-(r*15)] = (((tmp[id -(r*15)] * 1000000 ) % mod + (rep1[j - (r * 15) -1] %mod))) %mod;
			if (((j%15) == 5) || ((j % 15) == 7)) {
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
				result = (arr[j - 1 - (r * 15)]+ tmp[id - (r * 15)] + result) % mod; //arr + rep + 기존의 나머지
			}
			checknum++;
			if (j % 15 == 0) {
				r++;
			}
			printf("(%d, '=>', %lldL)\n", checknum, result);
		}
		/*for (j = 1; j <= 15; j++) {
			id = j;
			tmp[id] = (rep1[id-1] * 1000000) % mod;
			result = (arr[j - 1] + tmp[id] + result) % mod; //arr + rep + 기존의 나머지	
			printf("%d\n", result);
		}*/
	//}
	return 0;
}	