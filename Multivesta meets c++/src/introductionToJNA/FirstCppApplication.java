package introductionToJNA;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;
import com.sun.jna.ptr.DoubleByReference;

import java.util.Arrays;
import java.util.List;

public class FirstCppApplication {
    public interface HelloLibrary extends Library{
        HelloLibrary INSTANCE = (HelloLibrary) Native.load("HelloJNA", HelloLibrary.class);

        void sayHello(String name);
        CHelloResponse.ByValue hello(String message);
        CHelloResponse.ByValue helloTest(CHelloRequest request);

        class CHelloRequest extends Structure {
            public String name;
            public String message;

            @Override
            protected List<String> getFieldOrder(){
                return Arrays.asList(new String[]{"name","message"});
            }
        }

        class CHelloResponse extends Structure{
            public static class ByValue extends CHelloResponse implements Structure.ByValue {
                public String message;
            }
            @Override
            protected List<String> getFieldOrder(){
                return Arrays.asList(new String[]{"message"});
            }
        }
    }

    public interface SimpleDLL extends Library{
        SimpleDLL INSTANCE = (SimpleDLL) Native.load("simpleDLL",SimpleDLL.class);
        int multiply(double a, double b, DoubleByReference result);
        int sumArray(double[] a, int length, DoubleByReference result);
        String getVersion();
        int addValue(double[] a, int length, double value);

        int initFoo(double initialState);
        String getFooVersion();
        double getFooState();

    }

    public static void main(String[] args) {
        HelloLibrary.INSTANCE.sayHello("Foo");

        HelloLibrary.CHelloRequest req = new HelloLibrary.CHelloRequest();
        req.name = "Bar";
        req.message = "Bye";
        HelloLibrary.CHelloResponse.ByValue res = HelloLibrary.INSTANCE.helloTest(req);
        System.out.println(res.message);
        HelloLibrary.CHelloResponse.ByValue re2 = HelloLibrary.INSTANCE.hello("Test 2");
        System.out.println(re2.message);

        //Test simple dll
        DoubleByReference multiplyResult = new DoubleByReference(0);
        DoubleByReference sumResult = new DoubleByReference(0);
        SimpleDLL.INSTANCE.multiply(2,3,multiplyResult);
        System.out.println(String.format("2 * 3 = %f",multiplyResult.getValue()));

        double[] d = new double[10];
        for(int i = 0; i<d.length;i++){
            d[i] = i+1;
        }
        SimpleDLL.INSTANCE.sumArray(d,d.length,sumResult);
        System.out.println(String.format("Sum of d = %f",sumResult.getValue()));
        SimpleDLL.INSTANCE.addValue(d,d.length,4.5);
        SimpleDLL.INSTANCE.sumArray(d,d.length,sumResult);
        System.out.println(String.format("After adding 4.5 to each value, sum is now = %f",sumResult.getValue()));


        //Testing pointer
        SimpleDLL.INSTANCE.initFoo(0);
        System.out.println(String.format("Foo version is: %s",SimpleDLL.INSTANCE.getFooVersion()));
        for(int i = 0; i < 10; i++){
            System.out.println(String.format("Foo state is: %f",SimpleDLL.INSTANCE.getFooState()));
        }
    }

}
