// fast campus 강의
// https://www.acmicpc.net/problem/7490
// 0

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int N;

void calculate(int n, int result, vector<char> v){
        
    if(n == N){                              // 입력한 값까지 모두 확인
        if(result == 0){                     // 그때의 result가 0이라면 출력
            for(int i=0 ; i< v.size() ; i++){
                printf("%c",v[i]);
            }
            printf("\n");
        }
        return;
    }
    
    // 공백 연산자
    vector<char> v1 = v;
    v1.push_back(' ');
    v1.push_back(n +1 +'0');                 // int형인 n+1을 char형으로 바꾸는 방법
    int result_space = result;
    if(v.size() > 2){                        // 입력받은 v의 크기가 2보다 작으면 처음 1만 입력됐을 때이다.
        int tmp = v.size()-2;                // 현재 수의 부호를 담고있는 index를 저장한다.
        if(v[tmp] == '+'){                   // 현재 수가 양수일 경우
            result_space = result- n + (10*n + (n+1));
            calculate(n+1, result_space, v1);
        }
        else if(v[tmp] == '-'){              // 현재 수가 음수일 경우
            result_space = result+ n - (10*n + (n+1));
            calculate(n+1, result_space, v1);
        }
    }
    else{                                    // 현재 수가 1이므로, result로 12를 넘겨준다.
        calculate(n+1, 12, v1);
    }
    
    // '+' 연산자
    vector<char> v2 = v;
    v2.push_back('+');
    v2.push_back(n +1 +'0');
    calculate(n+1, result + n+1, v2);
  
    // '-' 연산자
    vector<char> v3 = v;
    v3.push_back('-');
    v3.push_back(n +1 +'0');
    calculate(n+1, result - n-1, v3);
}


int main(){
    int test_case;
    scanf("%d",&test_case);
    
    while(test_case){
        scanf("%d",&N);
        vector<char> v;
        v.push_back('1');
        
        calculate(1, 1, v);                   // 초기에 1을 넣어두고 시작한다.
        printf("\n");
        
        test_case--;
    }

    
    return 0;
}