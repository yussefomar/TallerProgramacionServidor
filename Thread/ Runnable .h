#ifndef  RUNNABLE _H
#define  RUNNABLE _H


#include <iostream>
#include <pthread.h>
#include <cassert>
#include <error.h>

using namespace std;

class Runnable {
public:
	virtual void* run() = 0;
	virtual ~Runnable() = 0;
};

