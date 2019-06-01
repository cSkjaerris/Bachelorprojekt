package inventoryManagement;

import entrypointmultivesta.UniqueEntryPoint;

public class EntrypointMultiVeStA {
    public static void main(String[] args) {
        String jnaPath = System.getProperty("jna.library.path");
        System.setProperty("jna.library.path",jnaPath != null && !jnaPath.isEmpty() ? jnaPath +
                ":/Users/casperskjaerris/Documents/cApp" : "/Users/casperskjaerris/Documents/cApp");
        if (args.length == 1){
            UniqueEntryPoint.main(args);
        } else {
            String[] input = new String[]{
                    "-client",
                    "-m", "/Users/casperskjaerris/Documents/cApp/InvManSetting.cfg",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/timeAtSteps.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/stepsAfterXSteps.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/timeAtSold.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/timeAtRestock.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/stockAtTime.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/lostAtSold.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/soldAtRestock.quatex",
                    "-f", "/Users/casperskjaerris/Documents/cApp/lostAtTime.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/restockAtTime.quatex",
                    //"-f", "/Users/casperskjaerris/Documents/cApp/multipleExprInv.quatex",
                    "-l", "/Users/casperskjaerris/Documents/cApp/oneLocal",
                    "-delta1", "0.5",
                    "-a", "0.05",
                    "-sd", "inventoryManagement.SimulatorState"
            };
            UniqueEntryPoint.main(input);
        }
    }
}
