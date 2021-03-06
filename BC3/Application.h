#pragma once
#include "Dataset.h"
#include "Attribute.h"
#include "Counter.h"
#include <random>
#include <string>
#include "RandomGenerator.h"
#include "CVI.h"

enum Algorithm : int { fcm = 0, pso = 1, fcmpso = 2, fa = 3, fafcm = 4};
enum class OutputType  { txt = 0, arff = 1 };

class Application
{
private:
	random_device rd;
	RandomGenerator parameterGenerator;

	Dataset *data = nullptr;
	int numberOfClusters = 0;
	int numberOfReplications = 1;
	int m = 2;
	int K = 1;
	CVI* cvi;

	bool isSetMinCHange = false;
	double minChange;

	string resultFolderName = "Results"; 
	string resultCVIFolderName = "ResultsCVI"; 
	string outputExtesion = "txt";
	char* title = "Title";
	bool fileOutputMode = true;
	bool fileCVIOutputMode = true;
	bool consoleCVIOutputMode = true;
	bool eachCVI = true;

	vector<Attribute*> objectClasses;
	vector<Attribute*> clusters;

	bool isSetFinalCriterion = false;
	FinalCriterion finalCriterion = FinalCriterion::maxIteration;

	MuInitializationMode muInitMode = MuInitializationMode::random;

	double c1 = 2;
	double c2 = 2;
	double r1 = -1;
	double r2 = -1;
	double maxV = -1;
	int w = 2;
	int Ppso = 10;
	int Pfa = 20;

	double t90 = 1.645;
	double t95 = 1.96;
	double t99 = 2.576;
	double actualT = t95;

	double alpha = -1;
	double beta = 1;
	double gamma = 1;
	
	void count(Counter* counter);
	FILE* openCVIFile(string resultCVIpath);

	string createFolderForOutput(string algName) const;
	string createFolderForCVIOutput(string algName) const;
	void resetClusterAttributes();
	int whichCenter(int whichObject, FuzzyData* fuzzyData) const;

	void clearObjectClasses();

	void clearClusterAttributes();
	
public:
	Application();
	~Application();		

	void count(Algorithm alg, int numberOfIteration);

	bool setM(int m);
	bool setC1(double c1);
	bool setC2(double c2);
	bool setR1(double r1);
	bool setR2(double r2);
	bool setW(double w);
	bool setSizeOfPopulationPSO(int size);
	bool setSizeOfPopulationFA(int size);
	bool setAlpha(double alpha);
	bool setBeta(double beta);
	bool setGamma(double gamma);
	bool setK(int K);
	bool setMaxV(double maxV);

	bool setData(const char* name);
	bool setNumberOfClusters(int number);
	bool setNumberOfReplications(int number);
	bool setConfidenceInterval(int value);

	bool setTitle(char* title);

	bool setFinalCriterion(FinalCriterion criterion);
	bool unsetFinalCriterion();
	bool setMinChange(double minCHange);
	bool unsetMinChange();
	bool setMuInitializationMode(MuInitializationMode mode);
	
	bool setTypeOfOutput(OutputType type);
	bool setClusterName(string name, int which);
	
	void setCVI(IndexEnum index);
	void setAllCVI();
	void unsetCVI(IndexEnum index);
	void unsetAllCVI();

	void setFileOutputMode();
	void unsetFileOutputMode();
	void setCVIFileOutputMode();
	void unsetCVIFileOutputMode();

	void setCVIConsoleOutputMode();
	void unsetCVIConsoleOutputMode();
	void setEachCVI();
	void unsetEachCVI();

	void saveToArff(const FuzzyData* fuzzyData, const char * filename, vector<Attribute*> attributes) const;
	void saveResultToFile(const FuzzyData* fuzzyData, int which, string resultPath);

	void assignClusters(FuzzyData* fuzzyData);	

	void dataObjectsPrint() const;
	void dataObjectsPrintWithClass() const;
};

