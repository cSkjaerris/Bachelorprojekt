package BankSimulator;

import entrypointmultivesta.UniqueEntryPoint;

public class EntrypointMultiVeStA {
    public static void main(String[] args) {
        String jnaPath = System.getProperty("jna.library.path");
        System.setProperty("jna.library.path",jnaPath != null && !jnaPath.isEmpty() ? jnaPath + ":/Users/casperskjaerris/Documents/cApp" : "/Users/casperskjaerris/Documents/cApp");
        if (args.length == 1){
            UniqueEntryPoint.main(args);
        } else{
            String[] input = new String[]{
                "-client",
                "-m", "/Users/casperskjaerris/Documents/cApp/settings.ini",
                //"-f", "/Users/casperskjaerris/Documents/cApp/stepsAfterXSteps.quatex",
                "-f", "/Users/casperskjaerris/Documents/cApp/timeAtArrivedAndServed.quatex",
                //"-f", "/Users/casperskjaerris/Documents/cApp/sizeAfterXSteps.quatex",
                //"-f", "/Users/casperskjaerris/Documents/cApp/sizeAtTime.quatex",
                "-l", "/Users/casperskjaerris/Documents/cApp/oneLocal",
                "-delta1", "0.5",
                "-a", "0.05",
                "-sd", "BankSimulator.SimulatorState"
            };
            UniqueEntryPoint.main(input);
        }

    }
}
