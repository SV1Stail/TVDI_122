#include <iostream>
using namespace std;
int main() {
  int pred = -1, counter = 0, next = 1, now = -1, counter_w = 0;
  while (std :: cin >> next && next && ++counter_w) {
    if (counter_w == 1){
      pred = next;
    }else if (counter_w == 2){
      now = next;
    }else{
    if (pred < now && now > next) counter++;
    pred = now;
    now = next;
    // std :: cout << "n: " << fib << "; "; 
    // std :: cout << "n_pred_pred: " << n_pred_pred << "; ";
    // std :: cout << "n_pred: " << n_pred << "; ";
    // std :: cout << "("<< counter << std :: endl ;
    }
  }
  cout << counter;
  return 0;
}
