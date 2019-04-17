package argos;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface ArgosLink extends Library {
    ArgosLink INSTANCE = (ArgosLink) Native.load("argosFromBinary", ArgosLink.class);

    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(int seed, String settingsPath);
    double rval(int obs);
    double rvals(String obs);
}
