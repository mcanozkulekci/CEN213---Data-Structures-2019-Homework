#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class STRReverse{
private:
	int i,len;
	string str;
	char *strCopy;
	public:
		void getStr(){
			cout<<"\nStringi Giriniz: ";
			getline(cin,str);
			if(str == "-1"){
				exit(0);
			}

		}

		void dynamicStr(){
			len = str.length() + 1;
			strCopy=new char[len];
			strcpy(strCopy,str.c_str());
		}


		void reverseString(){
			cout<<"Reversed hali  :";

			for(i=str.length();i>0;i--){
				cout<<strCopy[i-1];
			}
			cout<<"\n\n";


		}



};




int main(){

	STRReverse rvs;

	cout<<"Çıkmak için -1 Giriniz:"<<endl;

	while(1){

		rvs.getStr();
		rvs.dynamicStr();
		rvs.reverseString();



	}






	return 0;
}