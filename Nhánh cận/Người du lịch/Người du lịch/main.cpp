//
//  main.cpp
//  Người du lịch
//
//  Created by Võ Đức Quân
//  23-04-2020
//


#include <bits/stdc++.h>
using namespace std;

const int a = 200;
int maxE = 10000;
int C[a][a];
int maxC = a * maxE;
int X[a+1]; //X đểthử các khảnăng
int T[a]; //T[i] đểlưu chi phí đi từ X[1] đến X[i]
int BestWay[a+1];  //, BestWay để ghi nhận nghiệm
bool FREE[a];  //Free để đánh dấu, Free[i]= True nếu chưa đi qua tp i
int N, M;
int minSpending;  //Chi phí hành trình tối ưu

void input(){
    int a, b;
    cin >> N;
    cin >> M;
    // Khởi tạo ma trận chứa bộ chi phí giữa các điểm
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if(i == j)
                C[i][j] = 0;
            else C[i][j]= maxC;
        }
    }
    // Nhập bộ chi phí
    for (int k = 1; k <= M; k++){
        cin >> a;
        cin >> b;
        cin >> C[a][b]; // Nhập giá trị đi từ thành phố a đến thành phố b;
    }
}
void init(){
    for (int i = 1; i <= N; i++)
        FREE[i] = true;
    FREE[1] = false; //Các thành phố là chưa đi qua ngoại trừ thành phố 1
    X[1] = 1; //xuat phat tu thanh pho 1
    T[1] = 0; //Chi phí tại thành phố xuất phát là 0
    minSpending = maxC;
}

void output(){
    if (minSpending == maxC)
        cout << "Không có phương án tối ưu" <<endl;
    else{
        cout << "Quãng đường cần đi ngắn nhất là: " << minSpending << endl;
        cout << "Chu trình đường đi tối ưu là: ";
        for (int i = 1; i <= N; i++){
            if (i == N) cout << BestWay[i] << "->" << "1" <<endl;
            else cout << BestWay [i] << "->";
        }
    }
}
void Try(int i){ //Thử các cách chọn X[i]
    for (int j = 2; j<= N; j++){ // Thử các thành phố từ 2 đến N
        if (FREE[j]){ // Nếu gặp thành phố chưa đi qua
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j]; // Chi phí bằng chi phí trước cộng chi phí đường đi trực tiếp
            if (T[i] < minSpending){
                FREE[j] = false; //Đánh dấu thành phố vừa thử
                if (i == N){
                    if ( ( T[N] + C[X[N]][1] ) < minSpending ){
                        for ( int i = 0; i <= N; i++ )  // Cập nhật BestConfig
                            BestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }
                } else Try(i+1); //  Tìm các khả năng chọn x[i+1]
                FREE[j] = true;  // Bỏ đánh dấu
            }
        }
    }
}
int main(){
    input();
    init();
    Try(2);
    output();
}
