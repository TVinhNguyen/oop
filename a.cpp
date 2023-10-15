//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//    ofstream myfile; myfile.open("example.txt", ios::app);; // Khai báo m?t d?i tu?ng ofstream d? ghi d? li?u ra t?p tin
//     // M? t?p tin d? ghi d? li?u vào ? ch? d? n?i
//
//    if (myfile.is_open()) // Ki?m tra xem t?p tin dã du?c m? thành công hay không
//    {
//        myfile << "Hello, world!" << endl; // Ghi d? li?u ra t?p tin ? cu?i t?p tin
//        myfile.close(); // Ðóng t?p tin sau khi ghi xong
//        cout << "Data written to file successfully." << endl;
//    }
//    else
//    {
//        cout << "Unable to open file." << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
string data[100][5];
int main()
{

	int x= 0 , y = 0;
	string line,res =  "",token;
	ifstream myfile ("xi_mang.inp");
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			stringstream ss(line);
			cout << line << endl;
			while (ss >> token) {
				if(token != ",")  {
					res += token;
					res += " ";
				}
				 else {
				 	data[x][y] = res;
					res ="";
					y += 1;
				} 
 			}
 			x += 1; y= 0 ;
		}
	}
	for(int i = 0 ; i < x; i++) {
		for (int j = 0 ; j < 5; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
cout << x; 
    return 0;
}

