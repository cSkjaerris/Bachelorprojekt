package inventoryManagement;

import com.sun.jna.Native;
import vesta.mc.ParametersForState;
import vesta.quatex.DEFAULTOBSERVATIONS;

import java.util.Random;

public class TestInventory {
    @SuppressWarnings("Duplicates")
    public static void main(String[] args) {
        System.setProperty("jna.library.path","/Users/casperskjaerris/Documents/cApp");
        SimulatorState sim = new SimulatorState(new ParametersForState("/Users/casperskjaerris/Documents/cApp/InvManSetting.cfg",""));

        for(int i = 0; i < 2;i++){
            sim.setSimulatorForNewSimulation(9876543);
            for(int j = 0; j<151;j++){
                if(j%25 == 0) {
                    System.out.println(String.format("Run %d steps. Products sold = %f, lost sales are = %f and we had %f restockings",j,sim.rval("soldProducts"),sim.rval("lostSales"),sim.rval("numberOfRestocking")));
                }
                sim.performOneStepOfSimulation();
            }
            System.out.println("Testing with same seed");
        }
        System.out.println("Testing new seed");
        sim.setSimulatorForNewSimulation(324325);
        for(int j = 0; j<151;j++){
            if(j%25 == 0) {
                System.out.println(String.format("Run %d steps. Products sold = %f, lost sales are = %f and we had %f restockings",j,sim.rval("soldProducts"),sim.rval("lostSales"),sim.rval("numberOfRestocking")));
            }
            sim.performOneStepOfSimulation();
        }
        System.out.println("Now testing whole simulation");
        sim.setSimulatorForNewSimulation(75484356);
        sim.performWholeSimulation();
        System.out.println(String.format("Final sales: %f. total lost sales: %f and we had %f restockings",sim.rval("soldProducts"),sim.rval("lostSales"),sim.rval("numberOfRestocking")));
        System.out.println(String.format("Just making sure time is now: %f",sim.getTime()));

        sim.setSimulatorForNewSimulation(42034);
        for(int i=0; i<101;i++ ){
            if(i%5 == 0){
                System.out.println(String.format("Time: %f, lost: %f",sim.getTime(),sim.rval("lostSales")));
            }
            sim.performOneStepOfSimulation();
        }

    }
}
