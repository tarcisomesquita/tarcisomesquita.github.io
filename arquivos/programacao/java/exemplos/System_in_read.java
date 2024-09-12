
// clear ; javac System_in_read.java && java System_in_read

import java.io.*;

public class System_in_read {
   public static void main (String args[]) {
      byte vetortexto[] = new byte[10]; //declaracao de um vetor de bytes
      int byteslidos = 0;
      System.out.print("Escreva algo: ");
      
      try {
         byteslidos = System.in.read(vetortexto);
         System.out.print("Li " + byteslidos + " bytes\n\n");
         
         System.out.print("Voce escreveu: ");
         System.out.write(vetortexto,0,byteslidos);
      }
      catch (IOException e) {
         System.out.println("\nFalhou a leitura\n");
      }
   }
}

