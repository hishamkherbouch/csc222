#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Time {
	int sec, min, hr;

	void to_string() const;
};
