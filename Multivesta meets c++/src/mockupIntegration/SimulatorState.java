package mockupIntegration;

public class SimulatorState {

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
		JNASimulatorLink.INSTANCE.setSimulatorForNewSimulation(seed);
	}

	public double rval(int obs) {
		return JNASimulatorLink.INSTANCE.rval(obs);
	}

	public double rval(String obs) {
		return JNASimulatorLink.INSTANCE.rvals(obs);
	}

}
