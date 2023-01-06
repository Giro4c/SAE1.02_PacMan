#include <vector>
#include "fstream"

#include "yaml.h"

using namespace std;

vector<unsigned> vecParam (const string & fileName) {
    const vector<string> vecValuesUns = {"KMoveStraight", "KMoveRight","KMoveLeft", "KMoveBack"};
    ifstream ifs(fileName);
    char valChar;
    unsigned valUnsigned;
    vector<unsigned> vecValues;
    for (string key; ifs >> key;) {
        ifs >> valChar;
        if (vecValuesUns.end() != find(vecValuesUns.begin(), vecValuesUns.end(), key)) {
            ifs >> valUnsigned;
            vecValues.push_back(valUnsigned);
        }
    }
    return vecValues;

}
