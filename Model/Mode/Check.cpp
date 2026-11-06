#include "../Interfaces/Check.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

void Check::makeCheck(int col, bool verbose) {
	setExample();
	if (!setWeight())
		throw runtime_error("no weight file found, run -learn first");

	int right = 0, positives = 0, positivesRight = 0;
	for (int i = 0; i < col; i++) {
		nextSample(i);
		makePredict();
		const bool ok = result == ans;
		right += ok;
		if (ans) {
			positives++;
			positivesRight += ok;
		}
		if (verbose)
			cout << "Predict: " << result << " Answer: " << ans << (ok ? "" : "  <- wrong") << endl;
	}

	const int negatives = col - positives;
	auto pct = [](int a, int b) { return b ? 100.0 * a / b : 100.0; };
	cout << fixed << setprecision(2)
		<< "Accuracy:  " << pct(right, col) << "% (" << right << "/" << col << ")\n"
		<< "  pattern: " << pct(positivesRight, positives) << "% (" << positivesRight << "/" << positives << ")\n"
		<< "  noise:   " << pct(right - positivesRight, negatives) << "% (" << right - positivesRight << "/" << negatives << ")" << endl;
}
