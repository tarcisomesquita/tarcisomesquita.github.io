
// clear ; javac _IOException.java && java _IOException


import java.lang.Object;
import java.lang.String;
import java.lang.System;
import java.lang.Double;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _IOException {
   public static void main(String args[]) {
      double a;
      int b;
      BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
      try {
         System.out.print("Digite um número double: ");
         a = Double.parseDouble(teclado.readLine());
      }
      catch (IOException e) {
         System.out.println("Falha na entrada dos dados.");
         a = 0;
      }
      
      System.out.print("\nVocê digitou: " + a + "\n\n");
   }
}

