// Author: Gustavo Policarpo
// Name: Array Replacement I
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1172

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int x[10];

int main()
{
    cin >> x[0];
    cin >> x[1];
    cin >> x[2];
    cin >> x[3];
    cin >> x[4];
    cin >> x[5];
    cin >> x[6];
    cin >> x[7];
    cin >> x[8];
    cin >> x[9];
 
    for( int i = 0 ; i < 10 ; i++ ){
        if(x[i] > 0){
            cout << "X[" << i << "]" << " = " << x[i] << endl;
        }else{
            cout << "X[" << i << "]" << " = " << 1 << endl;
        }
    }
 
return 0;
}
