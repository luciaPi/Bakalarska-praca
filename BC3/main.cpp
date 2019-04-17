#include <vld.h>
#include <vector>
#include "Application.h"
#include <iostream>
#include <string>
#include "RandomGenerator.h"

using namespace std;

int main() {		
	//const char* fileName = "vysky.txt";
	//const char* fileName = "fcmexample.txt";
	//const char* fileName = "iris.data";
	//const char* fileName = "parkinsons.data";
	const char* fileName = "glass_csv.csv";
	//const char* fileName = "wine.data";

	//string fileName = "";
	//getline(cin, fileName);
	int numberOfReplication = 1;
	//cin >> numberOfIteration;
	
	/*std::random_device rd;
	RandomGenerator rn(rd(),0,1);
	for (int n = 0; n < 10; ++n) {
		std::cout << rn.nextRandom() << ' ';
	} cout << endl;
	RandomGenerator rn2(rd(),1,2);
	for (int n = 0; n < 10; ++n) {
		std::cout << rn2.nextRandom() << ' ';
	} cout << endl;*/

	Application counter;
	counter.setNumberOfClusters(3);
	//counter.setData(fileName.c_str());
	counter.setData(fileName);

	counter.setMuInitializationMode(MuInitializationMode::fcmPlusPlus);

	counter.setNumberOfReplications(numberOfReplication);
	counter.count(Algorithm::fcm,100);
	counter.count(Algorithm::pso,100);
	counter.count(Algorithm::fcmpso,3);
	counter.count(Algorithm::fa,20);
	counter.count(Algorithm::fafcm,1);
		
	/*char* title = "Iris Plants Database";
	char* creator = "Lucia Piatrikova";
	char* donor = " ";
	char* relation = "iris";

	vector<string> type;
	type.push_back("numeric");
	vector<string> type2;
	type2.push_back("Iris - setosa");
	type2.push_back("Iris - versicolor");
	type2.push_back("Iris - virginica");
	vector<Attribute*> attributes;
	/*attributes[0].setValues("sepallength", type);
	attributes[1].setValues("sepalwidth", type);
	attributes[2].setValues("petallength", type);
	attributes[3].setValues("petalwidth", type);
	attributes[4].setValues("class", type2);*/
	/*attributes.push_back(new Attribute("sepallength", type));
	attributes.push_back(new Attribute("sepalwidth", type));
	attributes.push_back(new Attribute("petallength", type));
	attributes.push_back(new Attribute("petalwidth", type));
	attributes.push_back(new Attribute("class", type2));

	counter.saveOutputToArff("iris.arff",title,creator,donor,relation,attributes);

	while (attributes.size() > 0) {
		Attribute* last = attributes.back();
		delete last;
		attributes.pop_back();
	}*/

 	return 0;
}
