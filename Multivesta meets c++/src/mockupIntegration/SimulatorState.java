package mockupIntegration;

import vesta.mc.NewState;
import vesta.mc.ParametersForState;
import vesta.quatex.DEFAULTOBSERVATIONS;

public class SimulatorState extends NewState {

	public SimulatorState(ParametersForState parameters) {
		super(parameters);
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
		JNASimulatorLink.INSTANCE.setSimulatorForNewSimulation(seed,"/Users/casperskjaerris/Documents/cApp/settings.ini");
	}

	public double rval(int obs) {
		return JNASimulatorLink.INSTANCE.rval(obs);
	}

	public double rval(String obs) {
		obs = obs.trim();
		if(obs.equalsIgnoreCase(DEFAULTOBSERVATIONS.STEPS.toString())){
			return (double)this.getNumberOfSteps();
		}
		return JNASimulatorLink.INSTANCE.rvals(obs);
	}

}
