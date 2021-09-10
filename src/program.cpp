/**
* program.cpp
* circular doubly linked list te olusturulan algoritmaya ile veri kaydi
* Yaz okulu 1.Ogretim B grubu
* 1.odev
* 16/08/2020
* Bugrahan Erk Vural
*/

#include "CircularDoublyLinkedList.h"
#include <string>
#include <fstream>
#include <sstream>

int gcd(int a, int b);
int gmod(int a, int b);
int intToAscii(int number);

int main()
{
	CircularDoublyLinkedList* sayilar = new CircularDoublyLinkedList();
	int obeb=0;
	int sayi;
	int konum{};
	int temp{};
	int mod{};
	string sayiList;
	ifstream myFile;
	myFile.open("Sayilar.txt");
	while (getline(myFile, sayiList)) {		// get new line
		stringstream iss(sayiList);
		while (iss >> sayiList) {			//read line 
			sayi = stoi(sayiList);
			if(sayilar->count() > 0){ //ilk sayi icin
				for (konum = 1; konum <= sayilar->count(); konum++) {
					temp = sayilar->elementAt(konum);
					if (konum = sayilar->count() || gcd(sayi, temp) > obeb) {
						obeb = gcd(sayi, temp);
						mod = gmod(sayi, temp);
						if (mod != 0) //mod kadar soluna git dosya basina gelirse direk ekle
						{
							if (konum - mod > 0) {
								sayilar->insert(konum - mod, sayi);
							}
							else { sayilar->insert(0, sayi); }
						}
						else //bulundugumuz yerin bi sagina
						{
							sayilar->insert(konum + 1, sayi);
						}
						break;
					}
				}//obeb olmazsa dosya sonuna kadar hareket et,sona geldi bulamadi sonla gir					
			}
			else {//ilk sayi icin
				sayilar->add(sayi);
				temp = sayi;
			}
			//cout << *sayilar << endl;
		}
		
		cout << "sifre: ";
		for (konum = 1; konum <= sayilar->count(); konum++) {
			char s = intToAscii(sayilar->elementAt(konum));
			cout << s ;
		}
		cout << endl << endl;
		
		//cout << *sayilar << endl;
		sayilar->clear();
	}
	delete sayilar;
	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
int gmod(int a, int b)
{
	int mod{};
	if (a > b && b!=0) { mod =  a % b; }
	else if(b>a && a != 0) { mod = b % a; }
	else { mod = 0; }
	return mod;
}
int intToAscii(int number) {
	return '0' + number - 48;
}