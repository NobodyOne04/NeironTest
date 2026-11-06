#include "../Interfaces/File.h"

#include <fstream>
#include <stdexcept>

using namespace std;

File::File(string dataDir) : dataDir(std::move(dataDir)) {}

string File::path(const char* name) const {
	if (dataDir.empty())
		return name;
	const char last = dataDir.back();
	return (last == '/' || last == '\\') ? dataDir + name : dataDir + "/" + name;
}

/* Читает файл с примером. */
void File::readExample(vector<int>& x, bool& ans) const {
	const string file = path("example.txt");
	ifstream input(file);
	if (!input)
		throw runtime_error("cannot open " + file);
	for (int& value : x) {
		if (!(input >> value) || (value != 0 && value != 1))
			throw runtime_error(file + ": expected " + to_string(x.size()) + " signals (0 or 1)");
	}
	int answer;
	if (!(input >> answer) || (answer != 0 && answer != 1))
		throw runtime_error(file + ": expected answer (0 or 1) after the signals");
	ans = answer == 1;
}

/* Читает веса из файла. Формат: размер, веса, порог (порог — необязателен для старых файлов). */
bool File::readWeight(vector<int>& weight, int& lim) const {
	const string file = path("weight.txt");
	ifstream input(file);
	if (!input)
		return false;
	size_t size = 0;
	if (!(input >> size) || size != weight.size())
		throw runtime_error(file + ": expected " + to_string(weight.size()) + " weights, found " + to_string(size));
	for (int& value : weight) {
		if (!(input >> value))
			throw runtime_error(file + ": not enough weights");
	}
	int fileLim;
	if (input >> fileLim)
		lim = fileLim;
	return true;
}

/* Записывает веса полученые в процессе обучения в файл. */
void File::writeWeight(const vector<int>& weight, int lim) const {
	const string file = path("weight.txt");
	ofstream output(file);
	if (!output)
		throw runtime_error("cannot write " + file);
	output << weight.size() << "\n";
	for (size_t i = 0; i < weight.size(); i++)
		output << (i ? " " : "") << weight[i];
	output << "\n" << lim << "\n";
	if (!output)
		throw runtime_error("failed writing " + file);
}
