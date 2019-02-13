package introductionToJNA;

import com.sun.jna.Library;
import com.sun.jna.Native;

public class HelloWorld {
    interface Clibary extends Library{
        Clibary INSTANCE = (Clibary) Native.load("c",Clibary.class);

        void printf(String format, Object... args);

    }

    public static void main(String[] args) {
        Clibary.INSTANCE.printf("Hello world\n");

        for(int i = 0; i<10;i++){
            Clibary.INSTANCE.printf("Call with args %d\n",i+1);
        }
    }
}
