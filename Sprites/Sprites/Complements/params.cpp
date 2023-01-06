#include <string>
#include "params.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>


using namespace std;

void InitParams (CMyParam & Param)
{
//Move Keys
Param.MapParamChar["KeyUp"] = 'z';
Param.MapParamChar["KeyDown"] = 's';
Param.MapParamChar["KeyLeft"] = 'q';
Param.MapParamChar["KeyRight"] = 'd';

Param.MapParamChar["TokenP1"] = 'O';
Param.MapParamChar["TokenP2"] = 'X';

//Size of grid — suppose to be a rectangle
Param.MapParamUnsigned["NbColumn"] = 10;
Param.MapParamUnsigned["NbLine"] = 10;

//Display Colors
Param.MapParamString["ColorP1"] = KColor.find("KRed")->second ;
Param.MapParamString["ColorP2"] = KColor.find("KYellow")->second ;

}

bool isDigit(string & strg)
{
    bool dgt(false);
    string digit("0123456789");
    for (unsigned i (0); i < strg.size(); ++i)
    {
        for (unsigned j (0); j < digit.size(); ++i)
            if (strg[i] == digit[j])
            {
                dgt = true;
            }
    }
    return dgt;
}
int strToInt(std::string in)
{
    return stoi(in.c_str());
}

/*
void LoadParams (CMyParam & Param)
{
    ifstream ifs("config.yaml");
    string str;
    while(true)
    {
        //cin >> str;
        if (ifs.eof()) break;
        getline(ifs,str);

        // cout << str << '\n';

        // extraire param et val
        string param ;
        string val;
        size_t pos = str.find(":");
        param = str.substr(0,pos - 1);
        val = str.substr(pos + 1);
        cout << param << " : " << val << endl;
        // enregistrer dans la struct

        // detecter le type de val et le convertir
        // si int
        int valInt;
        if (isDigit(val) == true)
            valInt = strToInt(val);
        //...
        if (param == "NbColumn" || param == "NbLine")
        {
            Param.MapParamChar[param] = valInt;
        }
        //si string
        if (param == "ColorP1" || param == "ColorP2")
        {
            Param.MapParamChar[param] = KColor.find(val)->second;
        }
        // si char
        char valChar;
    }
}
*/
void LoadParams (CMyParam & Param)
{
    ifstream ifs ("../prog12_PacMan/Nos_fichiers/config.yaml");
    if (!ifs)
    {
        cerr << "Pas de fichier de configuration ici" << endl;
        exit(-1);
    }
   cout << "fichier de param OK" << endl;
   for (string cle, poubelle; ifs >> cle;)
   {
       char deuxpoints;
       ifs >> deuxpoints;
       if (find(KAuthorizedKey.VParamChar.begin(), KAuthorizedKey.VParamChar.end() != )
   }
}
