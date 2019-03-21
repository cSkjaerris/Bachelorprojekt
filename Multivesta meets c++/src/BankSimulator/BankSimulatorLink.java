package BankSimulator;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface BankSimulatorLink extends Library {
    BankSimulatorLink INSTANCE = (BankSimulatorLink) Native.load("BankSimulator",BankSimulatorLink.class);

    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(int seed, String settingsPath);
    double rval(int obs);
    double rvals(String obs);
}
