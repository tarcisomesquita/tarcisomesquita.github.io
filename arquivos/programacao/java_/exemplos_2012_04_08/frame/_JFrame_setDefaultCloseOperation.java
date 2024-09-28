

// clear ; javac _JFrame_setDefaultCloseOperation.java && java _JFrame_setDefaultCloseOperation &

import javax.swing.*;  

public class _JFrame_setDefaultCloseOperation {  
   public static void main(String args[]) {  
      JFrame frame = new JFrame("Hello"); // "Hello" é o título da janela. Experimente Alt+Space para redimensionar a janela
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
      frame.setVisible(true);             
   }  
}  

