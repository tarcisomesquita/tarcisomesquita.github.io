

// clear ; javac _JFrame_getContentPane_add.java && java _JFrame_getContentPane_add &

import javax.swing.*;  

public class _JFrame_getContentPane_add {
   public static void main(String args[]) {
      JFrame frame = new JFrame("Hello"); // "Hello" é o título da janela. // Experimente Alt+Space para maximizar a janela
      JLabel label = new JLabel("Hello, Swing World");
      frame.getContentPane().add(label);
      
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setVisible(true);
   }  
}  

