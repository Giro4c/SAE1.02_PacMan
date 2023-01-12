#include "param.h"

using namespace std;


void LoadParams (CMyParam & Parameters, const string & ConfigFileName)
{
    ifstream ifs;
    ifs.open(ConfigFileName);
    if (!ifs)
        cerr << "Error: File not found"
    
}


void InitMursBPGhost (const vector<string> & Plateau, CMyParam & Parameters, PacMan & Pac, vector<nsGraphics::Vec2D> & VecteurMurs, map<nsGraphics::Vec2D, bool> & MapBP, unsigned & ResteBP, vector<GhostSprite> & VecteurGhost)
{
    Parameters.MapParamSize["WindowHeight"] = Plateau.size() * Parameters.MapParamUnsigned.find("CaseSize")->second;
    Parameters.MapParamSize["WindowWidth"] = Plateau[0].size() * Parameters.MapParamUnsigned.find("CaseSize")->second;

    for (unsigned i (0); i < Plateau.size(); ++i){
        for (unsigned j (0); j < Plateau[i]; ++j){
            // Start switch
            switch (Plateau[i][j]){
            case 'x':
                VecteurMurs.push_back({j*(Parameters.MapParamUnsigned.find("CaseSize")->second), i*(Parameters.MapParamUnsigned.find("Case Size")->second)});
                break;
            case '.':
                MapBP[nsGraphics::Vec2D(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2, i*(Parameters.MapParamUnsigned.find("Case Size")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2)] = false;
                ++ResteBP;
                break;
            case 'o':
                Pac.CenterPos.setX(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                Pac.CenterPos.setY(i*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
            case '1':
                VecteurGhost[0].CenterPos.setX(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                VecteurGhost[0].CenterPos.setY(i*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                break;
            case '2':
                VecteurGhost[1].CenterPos.setX(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                VecteurGhost[1].CenterPos.setY(i*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                break;
            case '3':
                VecteurGhost[2].CenterPos.setX(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                VecteurGhost[2].CenterPos.setY(i*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                break;
            case '4':
                VecteurGhost[3].CenterPos.setX(j*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                VecteurGhost[3].CenterPos.setY(i*(Parameters.MapParamUnsigned.find("CaseSize")->second) + (Parameters.MapParamUnsigned.find("CaseSize")->second)/2);
                break;
            }
            // End switch
        }
    }
}

