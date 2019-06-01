package argos;

import vesta.mc.ParametersForState;
import vesta.quatex.DEFAULTOBSERVATIONS;

public class TestArgos {
    public static void main(String[] args) {
        System.setProperty("jna.library.path","/Users/casperskjaerris/Documents/cApp");
        SimulatorState sim = new SimulatorState(new ParametersForState(
                "/Users/casperskjaerris/Documents/cApp/argos/diffusion10.argos",""));

        for(int i = 0; i < 2;i++){
            sim.setSimulatorForNewSimulation(i);
            for(int j = 0; j<51;j++){
                if(j%5 == 0) {
                    System.out.println(String.format("time: %f, step: %f", sim.rval(DEFAULTOBSERVATIONS.TIME.toString()),sim.rval(DEFAULTOBSERVATIONS.STEPS.toString())));
                }
                sim.performOneStepOfSimulation();
            }
            System.out.println("Testing with same seed");
        }
    }
}
