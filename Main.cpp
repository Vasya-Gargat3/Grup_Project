#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<fstream>

using namespace std;

class Region //Îáëàñòü
{
	string name;

public:
	Region() {
		name = "";
	}
	Region(string name) {
		this->name = name; //íàçâà îáëàñò³
	}
	string getName() { return name; }
	void setName(string name) { this->name = name; }

};

class Settlement : public Region//Íàñåëåíèé ïóíêò
{
	string settlementName; //íàçâà
	string geomorphicBinding; //ãåîìîðôîëîã³÷íà ïðèâ’ÿçêà ì³ñöÿ â³äáîðó ïðîáè

public:

	Settlement() {

		settlementName = "";
		geomorphicBinding = "";
	}
	Settlement(string name, string settlementName, string geomorphicBinding) :
		Region(name)
	{
		this->settlementName = settlementName;
		this->geomorphicBinding = geomorphicBinding;
	}

	string getSettlementName() { return settlementName; }
	void setSettlementName(string settlementName) { this->settlementName = settlementName; }

	string getGeomorphicBinding() { return geomorphicBinding; }
	void setGeomorphicBinding(string geomorphicBinding) { this->geomorphicBinding = geomorphicBinding; }

};

class SamplingData //Äàí³ â³äáîðó ïðîá
{
	Settlement settlement;//Íàñåëåíèè ïóíêò
	string samplingDate; //äàòà â³äáîðó ïðîáè
	double CO2Content; //âì³ñò âóãëåêèñëîãî ãàçó
	double COContent; //âì³ñò ÑÎ
	double SO2Content; //âì³ñò SO2
	double GasolineContent; //âì³ñò áåíçèíó
	double HClContent; //âì³ñò HCl

public:
	SamplingData() {
		this->settlement = Settlement();
		this->samplingDate = "";
		this->CO2Content = 0;
		this->COContent = 0;
		this->SO2Content = 0;
		this->GasolineContent = 0;
		this->HClContent = 0;
	}
	SamplingData(Settlement settlement, string samplingDate, double CO2Content, double COContent, double SO2Content, double GasolineContent, double HClContent) {

		this->settlement = settlement;
		this->samplingDate = samplingDate;
		this->CO2Content = CO2Content;
		this->COContent = COContent;
		this->SO2Content = SO2Content;
		this->GasolineContent = GasolineContent;
		this->HClContent = HClContent;
	}

	Settlement getSettlement() { return this->settlement; }
	void setSettlement(Settlement settlement) { this->settlement = settlement; }

	string getRegionName() { return this->settlement.getName(); }
	void setRegionName(string name) { this->settlement.setName(name); }

	string getSettlementName() { return this->settlement.getSettlementName(); }
	void setSettlementName(string settlementName) { this->settlement.setSettlementName(settlementName); }

	string getGeomorphicBinding() { return this->settlement.getGeomorphicBinding(); }
	void setGeomorphicBinding(string geomorphicBinding) { this->settlement.setGeomorphicBinding(geomorphicBinding); }

	string getSamplingDate() { return samplingDate; }
	void setSamplingDate(string date) { this->samplingDate = date; }

	double getCO2Content() { return CO2Content; }
	void setCO2Content(double) { this->CO2Content = CO2Content; }
	double getCOContent() { return COContent; }
	void setCOContent(double COContent) { this->COContent = COContent; }
	double getSO2Content() { return SO2Content; }
	void setSO2Content(double SO2Content) { this->SO2Content = SO2Content; }
	double getGasolineContent() { return GasolineContent; }
	void setGasolineContent(double GasolineContent) { this->GasolineContent = GasolineContent; }
	double getHClContent() { return HClContent; }
	void setHClContent(double HClContent) { this->HClContent = HClContent; }


};

//Êëàññ äëÿ çàïèñó äàíèõ ïðîá äî ôàéëó òà éîãî ÷èòàííÿ
class SampleStorage {
	vector<SamplingData> samples;
public:
	SampleStorage();
	void addSample(); //äîäàòè ïðîáè
	void deleteSample(); //âèäàëèòè ïðîáè
	void searchSample(); //çíàòè ïðîáó
	void viewSamples(); //â³äîáðàçèòè ïðîáè
	void fullTable();
private:
	void readSamplesFromFile(); //÷èòàòè âñ³ ïðîáè ç ôàéëó
	void writeSamplesToFile(); //çàïñàòè âñ³ ïðîáè äî ôàéëó
	void printSample(int i); //Âèâîä ñòðîêè ïðîáè äî åêðàíó

};

SampleStorage::SampleStorage()
{
	readSamplesFromFile();

	if (samples.empty()) {
		fullTable();
		writeSamplesToFile();
	}
}

void SampleStorage::addSample()
{

	SamplingData sample;

	string region;
	string settlement;
	string geomorphicBinding;
	string samplingDate;
	double CO2Content;
	double COContent;
	double SO2Content;
	double GasolineContent;
	double HClContent;

	ofstream fout("text.txt", ios_base::app);
	//fout<<endl;

	cout << endl << "------------------------------------" << endl;
	cout << endl << "Enter region name" << endl;
	cin >> region;
	cout << endl << "Enter settlement name" << endl;
	cin >> settlement;
	cout << endl << "Enter geomorphic binding name" << endl;
	cin >> geomorphicBinding;
	cout << endl << "Enter sampling date" << endl;
	cin >> samplingDate;
	cout << endl << "Enter CO2 content" << endl;
	cin >> CO2Content;
	cout << endl << "Enter CO content" << endl;
	cin >> COContent;
	cout << endl << "Enter SO2 content" << endl;
	cin >> SO2Content;
	cout << endl << "Enter Gasoline content" << endl;
	cin >> GasolineContent;
	cout << endl << "Enter HCl Content" << endl;
	cin >> HClContent;

	sample.setSettlement(Settlement(region, settlement, geomorphicBinding));
	sample.setSamplingDate(samplingDate);
	sample.setCO2Content(CO2Content);
	sample.setCOContent(COContent);
	sample.setSO2Content(SO2Content);
	sample.setGasolineContent(GasolineContent);
	sample.setHClContent(HClContent);
	samples.push_back(sample);

	fout << region << " ";
	fout << settlement << " ";
	fout << geomorphicBinding << " ";
	fout << samplingDate << " ";
	fout << CO2Content << " ";
	fout << COContent << " ";
	fout << SO2Content << " ";
	fout << GasolineContent << " ";
	fout << HClContent << ";";
	fout << endl;
	fout.close();

}

void SampleStorage::deleteSample()
{
	string settlement;
	string date;
	cout << "Input settlement name you want to delete: " << endl;
	cin >> settlement;
	cout << "Input date you want to delete: " << endl;
	cin >> date;

	for (size_t i = 0; i<samples.size(); i++) {

		if ((samples[i].getSettlementName() == settlement) && (samples[i].getSamplingDate() == date)) {

			samples.erase(samples.begin() + i);
			writeSamplesToFile();
			cout << "Succesfully deleted!" << endl;
			return;
		}
	}
	cout << "No matches found!" << endl;

}

void SampleStorage::searchSample()
{
	string settlement;
	cout << "Input settlement name you want to search: " << endl;
	cin >> settlement;
	bool isFound = false;
	for (size_t i = 0; i<samples.size(); i++) {

		if (samples[i].getSettlementName() == settlement) {
			printSample(i);
			isFound = true;
		}
	}
	if (!isFound) cout << "No matches found!";

}

void SampleStorage::viewSamples()
{
	for (size_t i = 0; i<samples.size(); i++) {
		printSample(i);
	}
}

void SampleStorage::fullTable()
{

	SamplingData sample1(
		Settlement("Ivano-Frank³vska", "Pidkamin", "r.Svirzh"),
		"22.02.97",
		0.033, 3, 0.05, 1.5, 0.2
	);
	samples.push_back(sample1);

	SamplingData sample2(
		Settlement("Ivano-Frank³vska", "Rogatin", "r.Gnila_Lipa"),
		"22.02.97",
		0.013, 1.2, 0.04, 0.01, 0
	);
	samples.push_back(sample2);

	SamplingData sample3(
		Settlement("Chern³vecka", "Putila", "Vododil"),
		"22.02.97",
		0.031, 0.2, 0.01, 0.01, 0
	);
	samples.push_back(sample3);

	SamplingData sample4(
		Settlement("Ivano-Frank³vska", "Pidkamin", "r.Svirzh"),
		"23.02.97",
		0.013, 1.2, 0.05, 0.02, 0
	);
	samples.push_back(sample4);

	SamplingData sample5(
		Settlement("Ivano-Frank³vska", "Rogatin", "r.Gnila_Lipa"),
		"23.02.97",
		0.031, 1, 0, 0.01, 0.01
	);
	samples.push_back(sample5);

}

void SampleStorage::readSamplesFromFile()
{
	int n = 0;
	ifstream input_file("text.txt");
	if (!input_file) { return; }

	char letter;
	while (!input_file.eof()) {
		letter = input_file.get();
		if (letter == ';') {
			n++;
		}
	}

	ifstream fin("text.txt");

	for (int i = 0; i<n; i++) {

		string region;
		string settlement;
		string geomorphicBinding;
		string samplingDate;
		double CO2Content;
		double COContent;
		double SO2Content;
		double GasolineContent;
		double HClContent;

		fin >> region;
		fin >> settlement;
		fin >> geomorphicBinding;
		fin >> samplingDate;
		fin >> CO2Content;
		fin >> COContent;
		fin >> SO2Content;
		fin >> GasolineContent;
		fin >> HClContent;
		fin.ignore(1);

		SamplingData sample;
		sample.setSettlement(Settlement(region, settlement, geomorphicBinding));
		sample.setSamplingDate(samplingDate);
		sample.setCO2Content(CO2Content);
		sample.setCOContent(COContent);
		sample.setSO2Content(SO2Content);
		sample.setGasolineContent(GasolineContent);
		sample.setHClContent(HClContent);
		samples.push_back(sample);

		cout << region << " ";
		cout << settlement << " ";
		cout << geomorphicBinding << " ";
		cout << samplingDate << " ";
		cout << CO2Content << " ";
		cout << COContent << " ";
		cout << SO2Content << " ";
		cout << GasolineContent << " ";
		cout << HClContent << " " << endl;
	}

}

void SampleStorage::writeSamplesToFile()
{
	ofstream fout("text.txt");

	for (size_t i = 0; i<samples.size(); i++) {

		fout << samples[i].getRegionName() << " ";
		fout << samples[i].getSettlementName() << " ";
		fout << samples[i].getGeomorphicBinding() << " ";
		fout << samples[i].getSamplingDate() << " ";
		fout << samples[i].getCO2Content() << " ";
		fout << samples[i].getCOContent() << " ";
		fout << samples[i].getSO2Content() << " ";
		fout << samples[i].getGasolineContent() << " ";
		fout << samples[i].getHClContent() << ";";
		fout << endl;

	}
	fout.close();


}

void SampleStorage::printSample(int i)
{
	cout << samples[i].getRegionName() << " ";
	cout << samples[i].getSettlementName() << " ";
	cout << samples[i].getGeomorphicBinding() << " ";
	cout << samples[i].getSamplingDate() << " ";
	cout << samples[i].getCO2Content() << " ";
	cout << samples[i].getCOContent() << " ";
	cout << samples[i].getSO2Content() << " ";
	cout << samples[i].getGasolineContent() << " ";
	cout << samples[i].getHClContent() << ";";
	cout << endl;
	cout << endl;
}



int main()
{

	SampleStorage storage; //ñõîâèùå äëÿ äàíèõ ïðîá

	while (1)
	{

		int option;
		cout << endl;
		cout << "Enter 1 to view samples" << endl;
		cout << "Enter 2 to add sample" << endl;
		cout << "Enter 3 to delete sample" << endl;
		cout << "Enter 4 to search sample" << endl;
		cout << "Enter 5 to exit program" << endl;
		cin >> option;

		if (option == 1) {
			storage.viewSamples();
		}
		else if (option == 2) {
			storage.addSample();
		}
		else if (option == 3) {
			storage.deleteSample();
		}
		else if (option == 4) {
			storage.searchSample();
		}
		else if (option == 5) {
			break;
		}
		else {
			cout << "WRONG VALUE!" << endl;
		}
	}

	return 0;
}