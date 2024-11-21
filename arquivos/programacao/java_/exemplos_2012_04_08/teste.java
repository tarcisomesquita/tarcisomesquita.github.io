import java.io.*;
public class teste
{
  public static void main(String args[]) throws IOException
  {
    double x;
    BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("x = ");
    x = Double.parseDouble(teclado.readLine()); // Lê um dado double a partir do teclado
    System.out.println("x = " + x);
  }
}

