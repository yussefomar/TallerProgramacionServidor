#include <iostream>

using namespace std;
//http://www.bogotobogo.com/cplusplus/multithreading_pthread.php al final explica esa forma(no llegue a probarlo
            //pero utiliza lo que explica antes.)
int main() {

	auto_ptr<communicatingThread> thread1(new communicatingThread(1));
	auto_ptr<communicatingThread> thread2(new communicatingThread(2));
	thread1->start();
	thread2->start();
	thread1->join();
	thread2->join();

	cout << "s = " << s << endl;
	return 0;
}
