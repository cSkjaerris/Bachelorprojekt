package argos;

import vesta.mc.NewState;
import vesta.mc.ParametersForState;
import vesta.quatex.DEFAULTOBSERVATIONS;

public class SimulatorState extends NewState {
    private String simulatorSettingsPath; //"/Users/casperskjaerris/Documents/cApp/argos/diffusion10.argos"

    public SimulatorState(ParametersForState parameters) {
        super(parameters);
        simulatorSettingsPath = parameters.getModel();

    }

    @Override
    public void performOneStepOfSimulation() {
        ArgosLink.INSTANCE.performOneStepOfSimulation();
    }

    @Override
    public void performWholeSimulation() {
        ArgosLink.INSTANCE.performWholeSimulation();
    }

    @Override
    public double getTime() {
        return ArgosLink.INSTANCE.getTime();
    }

    @Override
    public double rval(int i) {
        return ArgosLink.INSTANCE.rval(i);
    }

    @Override
    public double rval(String obs) {
        if(obs.equalsIgnoreCase(DEFAULTOBSERVATIONS.STEPS.toString())){
            return (double)this.getNumberOfSteps();}
        else if (obs.equalsIgnoreCase("time")){
                return getTime();
            }
        return ArgosLink.INSTANCE.rvals(obs);
    }

    @Override
    public void setSimulatorForNewSimulation(int i) {
        ArgosLink.INSTANCE.setSimulatorForNewSimulation(i,simulatorSettingsPath);
    }

}
