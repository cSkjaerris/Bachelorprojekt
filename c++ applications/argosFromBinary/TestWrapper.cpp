//
// Created by Casper Skjærris on 2019-04-03.
//

#include "JNALink.h"
//#include "Argos3SimulatorWrapper.h"

int main(){

    string sp = "/Users/casperskjaerris/Documents/cApp/Argos/diffusion10.argos";
    char* settingsPath = new char[sp.length()+1];
    strcpy(settingsPath,sp.c_str());

    setSimulatorForNewSimulation(123,settingsPath);
    argos::LOG.Flush();
    argos::LOGERR.Flush();
    for (int j = 0; j< 2;j++) {
        for (int i = 0; i < 100; i++) {
            if (i % 20 == 0) {
                cout << getTime() << endl;
                cout << "position for x coordinate " << rvals(settingsPath) << endl;
            }
            performOneStepOfSimulation();
        }
        setSimulatorForNewSimulation(j,settingsPath);
    }


    return 0;
}