
import java.io.*;
public class e15_InputFile {
   private FileReader in;
   public e15_InputFile(String filename) {
      try {
         in = new FileReader(filename);
      }
      catch(java.io.FileNotFoundException in) {
         System.out.println("ERRO");
      }
   }
   
   public String getWord() {
      int c;
      StringBuffer buf = new StringBuffer();
      do {
         try {
            c = in.read();
         }
         catch(java.io.IOException d) {
            System.out.println("ERRO");
         }
         
         if (Character.isWhitespace((char)c))
            return buf.toString();
         else
            buf.append((char)c);
      } while (c != -1);
      return buf.toString();
   }
}

