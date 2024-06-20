#include <iostream>

using namespace std;

class HotDogStand
{
public:
	HotDogStand(){
		id = 0;
		sold = 0;
	};
	HotDogStand(int _id, int _sold) {
		this->id = _id;
		this->sold = _sold;
		total_sold += _sold;
	};

	
	void JustSold() { //Indicates that you are selling hot dogs.
		cout<<"Stand "<<id<<" madesale.\n\n";
		this->sold++;
		total_sold++;
	}
	int GetTotalSold() {//Returns the value sold by all stands
		return total_sold;
	}
	int GetSold() {  //it returns the value sold by the stand.
		return this->sold;
	}

private:
	int id;   //unique id for that stand
	int sold; //total value specific to that stand
	static int total_sold; //total value for all stands
};

int HotDogStand::total_sold = 0;



int main() {


	HotDogStand h1(1,0);//Stand1 
	HotDogStand h2(2,0);//Stand2
	HotDogStand h3(3,0);//Stand3



	h1.JustSold();///Stand1
	h1.JustSold();

	h2.JustSold();///Stand2
	h2.JustSold();
	h2.JustSold();

	h3.JustSold();///Stand3
	h3.JustSold();
	h3.JustSold();
	h3.JustSold();
	
	cout << "Stand 1 sold " << h1.GetSold() << " hot dogs.\n";
	cout << "Stand 2 sold " << h2.GetSold() << " hot dogs.\n";
	cout << "Stand 3 sold " << h3.GetSold() << " hot dogs.\n";

	cout << "Total hot dogs sold:" << h1.GetTotalSold() << endl;
 
    return 0;
}
