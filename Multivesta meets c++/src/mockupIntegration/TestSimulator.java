package mockupIntegration;

public class TestSimulator {
    public static void main(String[] args) {
        SimulatorState sim = new SimulatorState();
        double time = sim.getTime();
        sim.performOneStepOfSimulation();
        sim.performWholeSimulation();
        sim.setSimulatorForNewSimulation((int)time);
        double val1 = sim.rval(1);
        double val2 = sim.rval("test");
        System.out.println(String.format("Time: %f\tval1: %f\tval2: %f",time,val1,val2));
    }
}
