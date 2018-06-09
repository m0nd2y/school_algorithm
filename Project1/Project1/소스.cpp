/*#include <stdio.h>
#include <stdlib.h>

int main() {
	long long int *arr = (long long int*)malloc(sizeof(long long int) * 100000000); //전체 문자열을 담을 배열
	int repeat[6] = { 1,2,3,4,3,2 }; //문자열을 직접 담아줄수 없으니 반복되는 부분만 배열로 정의
	long long int v[1000] = {}; //문제에 직접적으로 나와있는 V배열
	int i, j = 0;
	long long int sum = 0; //배열의 합을 입력할 임시변수
	int num = 1; //몇번째인지 표시해줄 변수
	for (i = 0; i <= 999; i++) {
		v[i] = 0;
	}


	i = 1;
	while (i <= 100000000 - 1) { //arr버퍼에 꽉차게 값을 담는다.
		arr[i] = repeat[j];
		j++;
		if (j == 6) {
			j = 0;
		}
		i++;
	}
	j = 1;
	while (j <= 100000000 - 1) {
		for (; j <= 100000000 - 1;) {
			sum += arr[j];
			v[num] *= 10;
			v[num] += arr[j];
			j++;
			if (num == sum) {
				printf("%d", v[num]);
				num++;
				break;
			}
		}
		printf("\n");
		sum = 0;
	}
	free(arr); //동적할당을 해제해준다.
}*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int tmp = 1;
	int *arr = (int*)malloc(sizeof(int) * 100000000); //전체 문자열을 담을 배열
	int repeat[6] = { 1,2,3,4,3,2 }; //문자열을 직접 담아줄수 없으니 반복되는 부분만 배열로 정의
	int v[1000] = {}; //문제에 직접적으로 나와있는 V배열
	int i, j = 0;
	int number = 0;
	int sum = 0; //배열의 합을 입력할 임시변수
	int num = 1; //몇번째인지 표시해줄 변수
	for (i = 0; i <= 999; i++) {
		v[i] = 0;
	}


	i = 1;
	while (i <= 100000000 - 1) { //arr버퍼에 꽉차게 값을 담는다.
		arr[i] = repeat[j];
		j++;
		if (j == 6) {
			j = 0;
		}
		i++;
	}
	j = 1;

	while (j <= 100000000 - 1) {
		for (; j <= 100000000 - 1;) {
			sum += arr[j];
			printf("%d", arr[j]);
			if (num == sum) {
				num++;
				j++;
				break;
			}
			j++;
		}
		number++;
		printf("\t\t\t\t%d", number);
		printf("\n");
		sum = 0;
	}
	free(arr); //동적할당을 해제해준다.
}