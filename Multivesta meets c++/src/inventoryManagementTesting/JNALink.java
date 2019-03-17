package inventoryManagementTesting;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface JNALink extends Library {
    JNALink INSTANCE = (JNALink) Native.load("InventoryManagementSimulator", JNALink.class);

    double getTime();
    void performOneStepOfSimulation();
    void performWholeSimulation();
    void setSimulatorForNewSimulation(int seed, String settingsPath);
    double rval(int obs);
    double rvals(String obs);
}
