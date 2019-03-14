package mockupIntegration;

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
		return JNASimulatorLink.INSTANCE.getTime();
	}

	public void performOneStepOfSimulation() {
		JNASimulatorLink.INSTANCE.performOneStepOfSimulation();
	}

	public void performWholeSimulation() {
		JNASimulatorLink.INSTANCE.performWholeSimulation();
	}

	public void setSimulatorForNewSimulation(int seed) {
		JNASimulatorLink.INSTANCE.setSimulatorForNewSimulation(seed,simulatorSettingsPath);
	}

	public double rval(int obs) {
		return JNASimulatorLink.INSTANCE.rval(obs);
	}

	public double rval(String obs) {
		obs = obs.trim();
		if(obs.equalsIgnoreCase(DEFAULTOBSERVATIONS.STEPS.toString())){
			return (double)this.getNumberOfSteps();
		} else if (obs.equalsIgnoreCase("time")){
			return getTime();
		}
		return JNASimulatorLink.INSTANCE.rvals(obs);
	}

}
