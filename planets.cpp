#include<bits/stdc++.h>
using namespace std;

//class definition for planet details
class Planet {
private:
	int moons;
	bool rings;
	vector<string> surfaceGases;
public:
	string name;
	// constructor
	Planet(string n, int a, bool b, vector<string> c) {
		name = n;
		moons = a;
		rings = b;
		surfaceGases = c;
	}
	int getMoons() {
		return moons;
	}
	bool hasRings() {
		return rings;
	}
	vector<string> getGases() {
		return surfaceGases;
	}
};

//method to get count of moons of all planets having rings
int numMoonRings(vector<Planet*> planets) {
	int count = 0;
	for (Planet* x : planets)
		if (x->hasRings())
			count += x->getMoons();
	return count;
}

//method to retrieve gas(es) found on maximum planets
vector<string> mostCommonGas(vector<Planet*> planets) {
	vector<string> gases;
	int max=0;
	unordered_map<string,int> m;
	for (Planet* x : planets) {
		for (string g : x->getGases()) {
			if (m.find(g)==m.end())
				m[g] = 1;
			else
				m[g]++;
			if (m[g] > max) {
				max = m[g];
				gases.clear();
				gases.push_back(g);
			}
			else if (m[g] == max) {
				gases.push_back(g);
			}
		}
	}

	//this method takes into consideration the case where there are multiple gases with the same count of occurences
	//so, we return an array of strings instead of just one string
	return gases;
}

int main() {
	vector<Planet*> planets;

	//input- name, moons, rings, gases
	vector<string> gases;
	planets.push_back(new Planet("Mercury",0,false,gases));

	gases.push_back("Carbon Dioxide");
	gases.push_back("Nitrogen");
	planets.push_back(new Planet("Venus",0,false,gases));

	gases.clear();
	gases.push_back("Nitrogen");
	gases.push_back("Oxygen");
	planets.push_back(new Planet("Earth",1,false,gases));

	gases.clear();
	gases.push_back("Hydrogen");
	gases.push_back("Helium");
	planets.push_back(new Planet("Jupitor",79,true,gases));

	planets.push_back(new Planet("Saturn",83,true,gases));

	gases.push_back("Methane");
	planets.push_back(new Planet("Uranus",27,true,gases));



	cout << "Total number of moons on planets with rings is-" << endl;
	cout << numMoonRings(planets) << endl;

	cout << endl << "Most common gas(es) on the surface of planets is-" << endl;
	for (string gas : mostCommonGas(planets)) {
		cout << gas << endl;
	}

	return 0;
}
