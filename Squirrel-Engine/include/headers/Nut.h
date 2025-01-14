#pragma once
#include "EQueueOrder.h"
#include "NJob.h"

class Nut
{
public:
	Nut();
	void startScheduler();
	void stopScheduler();
	void pauseScheduler();
	void submitJob(NJob& job, EQueueOrder order);
private:
	void threadPoolProcess();
	NJob* threadPoolSchedular();
	void processLowOrder();
	void processHighOrder();

private:
	std::queue<NJob*> jobQueueLowOrder;
	std::queue<NJob*> jobQueueHighOrder;
	bool multithreded;
};
