package mockupIntegration;

public class TestSimulator {
    public static void main(String[] args) {
        SimulatorState sim = new SimulatorState();

        for(int i = 0; i < 2;i++){
            sim.setSimulatorForNewSimulation(123);
            for(int j = 0; j<51;j++){
                if(j%5 == 0) {
                    System.out.println(String.format("Run %d steps. Queue size is: %f, amount served: %f and time is: %f",j,sim.rval(0),sim.rval(""),sim.getTime()));
                }
                sim.performOneStepOfSimulation();
            }
            System.out.println("Testing with same seed");
        }
        sim.setSimulatorForNewSimulation(9876543);
        for(int j = 0; j<51;j++){
            if(j%5 == 0) {
                System.out.println(String.format("Run %d steps. Queue size is: %f, amount served: %f and time is: %f",j,sim.rval(0),sim.rval(""),sim.getTime()));
            }
            sim.performOneStepOfSimulation();
        }
        System.out.println("Now testing whole simulation");
        sim.setSimulatorForNewSimulation(75484356);
        sim.performWholeSimulation();
        System.out.println(String.format("Final served: %f. Time is now: %f",sim.rval(""),sim.getTime()));
    }
}
