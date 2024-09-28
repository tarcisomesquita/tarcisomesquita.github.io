// clear ; javac URLConnectionReader.java && java URLConnectionReader
// nc -vv -l -n 127.0.0.1 -p 8080

import java.net.*;
import java.io.*;

public class URLConnectionReader {
   public static void main(String[] args) throws Exception {
      try {
         URL myURL = new URL("http://127.0.0.1:8080/");
         URLConnection myURLConnection = myURL.openConnection();
         myURLConnection.connect();  // estabelece a conexão
         BufferedReader in = new BufferedReader(new InputStreamReader(myURLConnection.getInputStream()));  // getInputStream, getOutputStream, etc
         
         String inputLine;
         while ((inputLine = in.readLine()) != null) System.out.println(inputLine);
         in.close();
      }
      catch (MalformedURLException e) { 
         System.out.println("new URL() failed");
      } 
      catch (IOException e) {
         System.out.println("openConnection() failed");
      }
   }
}

