package SimpleBank;

import vesta.mc.ParametersForState;

public class TestBank {
    public static void main(String[] args) {
        System.setProperty("jna.library.path","/Users/casperskjaerris/Documents/cApp");
        SimulatorState sim = new SimulatorState(new ParametersForState("/Users/casperskjaerris/Documents/cApp/settings.ini",""));

        for(int i = 0; i < 2;i++){
            sim.setSimulatorForNewSimulation(123);
            for(int j = 0; j<51;j++){
                if(j%5 == 0) {
                    System.out.println(String.format("Run %d steps. Queue size is: %f, amount served: %f and time is: %f",j,sim.rval("queueSize"),sim.rval("served"),sim.getTime()));
                }
                sim.performOneStepOfSimulation();
            }
            System.out.println("Testing with same seed");
        }
        sim.setSimulatorForNewSimulation(9876543);
        for(int j = 0; j<51;j++){
            if(j%5 == 0) {
                System.out.println(String.format("Run %d steps. Queue size is: %f, amount served: %f and time is: %f",j,sim.rval("queueSize"),sim.rval("served"),sim.getTime()));
            }
            sim.performOneStepOfSimulation();
        }
        System.out.println("Now testing whole simulation");
        sim.setSimulatorForNewSimulation(75484356);
        sim.performWholeSimulation();
        System.out.println(String.format("Final served: %f. Time is now: %f",sim.rval("served"),sim.getTime()));
        System.out.println(String.format("Just making sure queue size is %f",sim.rval("queueSize")));

        System.out.println("Testing queue size through whole simulation");
        sim.setSimulatorForNewSimulation(62738429);
        while(true){
            sim.performOneStepOfSimulation();
            double time = sim.getTime();
            if ((int) time % 10 == 0) {
                System.out.println(String.format("Time: %d\t queueSize: %f", (int) time, sim.rval("queueSize")));
            }
            if (time >= 1000){
                break;
            }
        }
    }
}
