#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include "Interfaces/Learn.h"
#include "Interfaces/Check.h"

using namespace std;

namespace {

const int SIZE = 15; // 3x5 пикселей

/* Выводит доступные команды. */
void showHelp(const char* prog) {
	cout << "Usage: " << prog << " (-learn | -check) -iter N [-data DIR] [-v]\n"
		<< "  -learn     train the perceptron on N samples and save weights\n"
		<< "  -check     evaluate saved weights on N samples\n"
		<< "  -iter N    number of samples (positive integer)\n"
		<< "  -data DIR  folder with example.txt / weight.txt (default: Data)\n"
		<< "  -v         (check) print every prediction\n"
		<< "  -h         show this help" << endl;
}

/* Преобразование аргумента в положительное int. */
int parseIterations(const string& arg) {
	size_t pos = 0;
	int value = 0;
	try {
		value = stoi(arg, &pos);
	}
	catch (const exception&) {
		pos = 0;
	}
	if (pos != arg.size() || value <= 0)
		throw invalid_argument("invalid iteration count: '" + arg + "'");
	return value;
}

} // namespace

/* Обработка параметров командной строки. */
int main(int argc, char* argv[]) {
	string mode, dataDir = "Data";
	int iterations = 0;
	bool verbose = false;

	try {
		for (int i = 1; i < argc; i++) {
			const string arg = argv[i];
			auto value = [&]() -> string {
				if (i + 1 >= argc)
					throw invalid_argument(arg + " needs a value");
				return argv[++i];
			};
			if (arg == "-h" || arg == "--help") { showHelp(argv[0]); return 0; }
			else if (arg == "-learn" || arg == "-check") mode = arg;
			else if (arg == "-iter") iterations = parseIterations(value());
			else if (arg == "-data") dataDir = value();
			else if (arg == "-v") verbose = true;
			else throw invalid_argument("unknown argument: " + arg);
		}
		if (mode.empty() || iterations == 0) {
			showHelp(argv[0]);
			return EXIT_FAILURE;
		}

		if (mode == "-learn")
			Learn(SIZE, dataDir).makeLearn(iterations);
		else
			Check(SIZE, dataDir).makeCheck(iterations, verbose);
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
		return EXIT_FAILURE;
	}
	return 0;
}
