#include<iostream>
#include <algorithm>
#include "param.h"

using namespace std;

void InitPlateau (vector<string> & Plateau)
{
    Plateau = {
    "xxxxxxxxxxxxxxxxxxxxxx",
    "x....x..........x....x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x.x................x.x",
    "x.x.xx.xxxnnxxx.xx.x.x",
    "x.x....xnnnnnnx....x.x",
    "x...xx.xxxxxxxx.xx...x",
    "x.x................x.x",
    "x.x.xx.xxxxxxxx.xx.x.x",
    "x.x................x.x",
    "x.xx.x.xxxxxxxx.x.xx.x",
    "x....x..........x....xx",
    "xxxxxxxxxxxxxxxxxxxxxx"};
}


void LoadParams (CMyParam & Param, const string & ConfigFileName)
{
    ifstream ifs;
    ifs.open(ConfigFileName);
    if (!ifs){
        cerr << "Error: File not found";
        exit(-1);
    }
    cout << "Fichier de paramètre trouvé" << endl;

    for (string cle, poubelle; ifs >> cle;){
        char deuxpoints;
        ifs >> deuxpoints;
        if (find(KAuthorizedKey.VParamChar.begin(), KAuthorizedKey.VParamChar.end(), cle) != KAuthorizedKey.VParamChar.end()){
            char val;
            ifs >> val;
            Param.MapParamChar[cle] = val;
        }
        if (find(KAuthorizedKey.VParamSize.begin(), KAuthorizedKey.VParamSize.end(), cle) != KAuthorizedKey.VParamSize.end()){
            unsigned val;
            ifs >> val;
            Param.MapParamSize[cle] = val;
        }
        if (find(KAuthorizedKey.VParamSpeed.begin(), KAuthorizedKey.VParamSpeed.end(), cle) != KAuthorizedKey.VParamSpeed.end()){
            unsigned val;
            ifs >> val;
            Param.MapParamSpeed[cle] = val;
        }
        if (find(KAuthorizedKey.VParamRGBAColor.begin(), KAuthorizedKey.VParamRGBAColor.end(), cle) != KAuthorizedKey.VParamRGBAColor.end()){
            unsigned val1;
            unsigned val2;
            unsigned val3;

            ifs >> val1;
            ifs >> val2;
            ifs >> val3;

            Param.MapParamRGBAColor[cle] = {val1, val2, val3};
        }
        else
            getline(ifs, poubelle);
    }
    cout << "Paramètres chargés" << endl;
}

void InitMursBPGhost (const vector<string> & Plateau, CMyParam & Parameters, PacMan & Pac, vector<nsGraphics::Vec2D> & VecteurMurs, map<nsGraphics::Vec2D, bool> & MapBP, unsigned & ResteBP, vector<GhostSprite> & VecteurGhost)
{
    Parameters.MapParamSize["WindowHeight"] = Plateau.size() * Parameters.MapParamSize.find("CaseSize")->second;
    Parameters.MapParamSize["WindowWidth"] = Plateau[0].size() * Parameters.MapParamSize.find("CaseSize")->second;

    for (unsigned i (0); i < Plateau.size(); ++i){
        for (unsigned j (0); j < Plateau[i].size(); ++j){
            // Start switch
            switch (Plateau[i][j]){
            case 'x':
                VecteurMurs.push_back({j*(Parameters.MapParamSize.find("CaseSize")->second), i*(Parameters.MapParamSize.find("Case Size")->second)});
                break;
            case '.':
                MapBP[nsGraphics::Vec2D(j*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2, i*(Parameters.MapParamSize.find("Case Size")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2)] = false;
                ++ResteBP;
                break;
            case 'o':
                Pac.CenterPos.setX(j*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
                Pac.CenterPos.setY(i*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
            case '1':
                VecteurGhost[0].CenterPos.setX(j*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
                VecteurGhost[0].CenterPos.setY(i*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
                break;
            case '2':
                VecteurGhost[1].CenterPos.setX(j*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
                VecteurGhost[1].CenterPos.setY(i*(Parameters.MapParamSize.find("CaseSize")->second) + (Parameters.MapParamSize.find("CaseSize")->second)/2);
                break;
            }
            // End switch
        }
    }
}

