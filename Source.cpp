#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value> &m, Key key) {
	if (m.count(key) == 0) {
		throw runtime_error("Element does't exist in collection");
	}
	return m[key];
}

int main(void) {
	try {
		map<int, string> m = { {0, "value"} };
		string& item = GetRefStrict(m, 0);
		item = "newvalue";
		cout << m[0] << endl; // выведет newvalue
	}
	catch(exception const& e){
		cout << "Exception: " << e.what() << endl;
	}
}