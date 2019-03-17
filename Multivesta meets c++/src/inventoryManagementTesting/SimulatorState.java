package inventoryManagementTesting;

import vesta.mc.NewState;
import vesta.mc.ParametersForState;
import vesta.quatex.DEFAULTOBSERVATIONS;

public class SimulatorState extends NewState {
    private String simulatorSettingsPath; //"/Users/casperskjaerris/Documents/cApp/settings.ini"

    public SimulatorState(ParametersForState parameters) {
        super(parameters);
        simulatorSettingsPath = parameters.getModel();

    }

    public double getTime() {
        return JNALink.INSTANCE.getTime();
    }

    public void performOneStepOfSimulation() {
        JNALink.INSTANCE.performOneStepOfSimulation();
    }

    public void performWholeSimulation() {
        JNALink.INSTANCE.performWholeSimulation();
    }

    public void setSimulatorForNewSimulation(int seed) {
        JNALink.INSTANCE.setSimulatorForNewSimulation(seed,simulatorSettingsPath);
    }

    public double rval(int obs) {
        return JNALink.INSTANCE.rval(obs);
    }

    public double rval(String obs) {
        obs = obs.trim();
        if(obs.equalsIgnoreCase(DEFAULTOBSERVATIONS.STEPS.toString())){
            return (double)this.getNumberOfSteps();
        } else if (obs.equalsIgnoreCase("time")){
            return getTime();
        }
        return JNALink.INSTANCE.rvals(obs);
    }

}
