package SimpleBank;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface JNASimulatorLink extends Library {
    JNASimulatorLink INSTANCE = (JNASimulatorLink) Native.load("Simulator", JNASimulatorLink.class);

    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(int seed, String settingsPath);
    double rval(int obs);
    double rvals(String obs);
}
