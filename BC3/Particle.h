#pragma once
#include <string>
#include "RandomGenerator.h"

class Particle 
{
private:
	double c1 = 1;
	double c2 = 1;
	double r1 = 0.5;
	double r2 = 0.5;
	double w = 1;

	double maxV = 0.0001;

	RandomGenerator* Vgenerator = nullptr;
	
	void pbestInit();
	void VInit();
	void Xinit();
	
	void computeV(const Particle* gbest);
	void computeX();
	
	void clearParticle();

	double getXValue(int i) const;
	bool setValues(double **source, double *dest);

	int getSize() const;

protected:
	double* pbest = nullptr;
	double pbestFitness = 0;

	double** X = nullptr;
	double* V = nullptr;
	int size = 0;

	virtual void normalize() = 0;
	virtual double getFitness() const = 0;
	virtual bool setX() = 0;
	
	void setStartingX();

	void init();
	bool checkFitness(Particle* gbest);

public:
	Particle();
	Particle(double c1,double c2, double r1, double r2, double w, int size, RandomGenerator* Vgenerator);
	~Particle();

	void Vprint() const;	
	void pbestPrint() const;
	void Xprint() const;

	bool compute(Particle* gbest);
	
	void setc1c2(double c1, double c2);
	void setr1r2(double r1, double r2);
	void setw(double w);
	void setSize(int size);
	void setMaxV(double maxV);

	virtual std::string getName() const = 0;
	virtual std::string getAlgorithmName() const = 0;

	double getC1() const;
	double getC2() const;
	double getR1() const;
	double getR2() const;
	double getW() const;

	void reinit();
};

