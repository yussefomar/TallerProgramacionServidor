#include "communicatingThread.h"

void* communicatingThread::run() {
	cout << "Thread " << myID << " is running!" << endl;
	// increment s by million times
	for (int i = 0; i < 1000000; i++) s+=1;
	return 0;
}
