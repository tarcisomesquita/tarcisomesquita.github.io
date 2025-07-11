
// clear ; javac Integer_valueOf_intValue.java && java Integer_valueOf_intValue

import java.io.DataInputStream; //classe DataInputStream para a entrada de dados

public class Integer_valueOf_intValue {
   public static void main(String args[]) {
      String line;
      line = "123";
      int i = Integer.valueOf(line).intValue();
      i = i + 1;
      System.out.println(i);
   }
}

