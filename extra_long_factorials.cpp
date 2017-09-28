#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class BigInteger{
	private:
		vector<int> num;
	public:
		BigInteger();
		BigInteger(int n);
		BigInteger(vector<int> v);
		BigInteger& operator=(BigInteger b);
		void printNumber();
		BigInteger operator*(int mult);
	private:
		vector<int> reverse(vector<int> r);
};


BigInteger::BigInteger(){
	num.clear();
	num.push_back(0);
}

BigInteger::BigInteger(int n){
	num.clear();
	int nn = n;
	vector<int> reversed;
	while(nn/10){
		reversed.push_back(nn%10);
		nn/=10;
	}
	reversed.push_back(nn);
	num = reverse(reversed);

}

BigInteger::BigInteger(vector<int> v){
	num = v;
}

void BigInteger::printNumber(){
	for(int i=0;i<num.size();i++)
		cout<<num[i];
	cout<<endl;
}
vector<int> BigInteger::reverse(vector<int> r){
	vector<int> number;
	int size = r.size();
	for(int i=size-1;i>=0;i--)
		number.push_back(r[i]);
	return number;

}

BigInteger& BigInteger::operator=(BigInteger b){
	num.clear();
	num = b.num;
	return *this;
}


BigInteger BigInteger::operator*(int mult){
	vector<int> v = this->num;
	int carry = 0;
	for(int i=v.size()-1;i>=0;i--){
		v[i] *= mult;
		v[i] += carry;
		carry = v[i]/10;
		v[i] = v[i]%10;
		
		if(i==0 && carry){
			while(carry/10){
				v.insert(v.begin(),carry%10);
				carry/=10;
			}
			v.insert(v.begin(),carry%10);
			
		}
		
	}
	BigInteger result(v);
	return result;
}
int main(){
	int n;
	cin>>n;

	BigInteger num(1);
	for(int i=2;i<=n;i++){
		num = num*i;
	}
	num.printNumber();
	return 0;
}
