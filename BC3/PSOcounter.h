#pragma once
#include "Object.h"
#include "Dataset.h"
#include "ParticleFuzzyData.h"
#include "Counter.h"
#include "RandomGenerator.h"

class PSOcounter : public Counter
{
private:		
	void removeParticles();
	void particlesInit(Dataset data, int numberOfClusters, int m, double c1, double c2, double r1, double r2, double w, int K, MuInitializationMode muInitMode);
	
	void compute();

	RandomGenerator Vgenerator;
	RandomGenerator muGenerator;
	RandomGenerator centersGenerator;
	
protected:
	ParticleFuzzyData** particles = nullptr;
	ParticleFuzzyData* gbest = nullptr;
	int P;
	double maxV = -1;

	void count();

	bool wasSignificantChange() const override;

	void Xprint() const;
	void Vprint() const;
	void centersPrint() const;
	void dPrint() const;
	void pbestsPrint() const;
	void gbestPrint() const;
	void particlesJmPrint() const;
	void particlesPbestJmPrint() const;

	void setMaxV();

public:
	PSOcounter();
	PSOcounter(int seed1, int seed2, int seed3);
	~PSOcounter();

	void count(Dataset pdata, int numberOfClusters, int m, double c1, double c2, double r1, double r2, double w, int P, int K, MuInitializationMode muInitMode);
	void recount();

	void setCounter(Dataset pdata, int numberOfClusters, int m, double c1, double c2, double r1, double r2, double w, int P, int K, MuInitializationMode muInitMode);

	FuzzyData* getBest() const override;
		
	double getJm() const override;
	void printJm() const override;

	void setK(int K);
	void setMaxV(double maxV);
};

