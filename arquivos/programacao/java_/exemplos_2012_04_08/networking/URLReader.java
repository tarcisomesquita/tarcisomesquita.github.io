// clear ; javac URLReader.java && java URLReader
// sudo nc -vv -l -n 127.0.0.1 -p 80

import java.net.*;
import java.io.*;

public class URLReader {
   public static void main(String[] args) throws Exception {
      URL oracle = new URL("http://127.0.0.1");
      BufferedReader in = new BufferedReader(new InputStreamReader(oracle.openStream()));
      
      String inputLine;
      while ((inputLine = in.readLine()) != null) System.out.println(inputLine);
      in.close();
   }
}

