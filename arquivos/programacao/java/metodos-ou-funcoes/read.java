
import java.io.*;

public class read {
  public static void main (String args[]) {
    byte vetortexto[] = new byte[200]; //declaracao de um vetor de bytes
    int byteslidos = 0;
    System.out.println("Escreva algo:");
    
    try {
      byteslidos = System.in.read(vetortexto);
      System.out.print("Voce escreveu: ");
      System.out.write(vetortexto, 2, byteslidos); // escreve os bytes de 2 até byteslidos
    }
    catch (IOException e) {
      // Alguma acao de recuperacao da falha
    }
  }
}

