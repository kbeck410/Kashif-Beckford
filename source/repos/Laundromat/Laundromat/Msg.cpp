#include "Msg.h"
#include <iostream>

using namespace std;

Msg::Msg() {

}
void Msg::add(string msg) {
	cout << msg << endl;
}
void Msg::add(string msg, int num) {
	cout << msg << endl;
	cout << msg + to_string(num) << endl;
}