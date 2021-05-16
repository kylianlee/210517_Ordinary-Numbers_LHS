//
// Created by Kylian Lee on 2021/05/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ordinaryNum(81);

void calcOrdinaryNum();

int solution(long long num);

int main(){
  int caseNum;
  calcOrdinaryNum();
  cin >> caseNum;
  for (int i = 0; i < caseNum; ++i) {
    int num;
    cin >> num;
    cout << solution(num) << endl;
  }
}

void calcOrdinaryNum() {
  int k = 0;
  long long num;
  for (int i = 1; i <= 9; ++i) {
    num = i;
    for (int j = 0; j < 9; j++) {
      ordinaryNum[k++] = num;
      num = num * 10 + i;
    }
  }
  sort(ordinaryNum.begin(), ordinaryNum.end());
}

int solution(long long num) {
  int answer = 0;
  int size = ordinaryNum.size();
  for (int i = 0; i < size; ++i) {
    if(num >= ordinaryNum[i])
      ++answer;
    else
      break;
  }
  return answer;
}