
// clear ; javac _DataInputStream_readLine.java && java _DataInputStream_readLine

import java.io.DataInputStream;

public class _DataInputStream_readLine {
   public static void main(String args[]) {
      String linha="";
      
      DataInputStream meuDataInputStream;
      meuDataInputStream = new DataInputStream(System.in);
      
      try {
         linha = meuDataInputStream.readLine();
      }
      catch (Exception erro) {
         System.out.println("Erro de leitura");
      }
      
      System.out.println(linha + "\n");
   }
}

