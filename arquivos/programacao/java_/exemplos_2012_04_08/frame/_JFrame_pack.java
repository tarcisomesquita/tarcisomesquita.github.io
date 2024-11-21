
// clear ; javac _JFrame_pack.java && java _JFrame_pack &

import javax.swing.*;  

public class _JFrame_pack
{  
   public static void main(String args[])
   {
      JFrame frame = new JFrame("Hello");
      JLabel label = new JLabel("Hello, Swing World");
      frame.getContentPane().add(label);
      frame.pack(); // Experimente Alt+Space para maximizar a janela
      
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
      frame.setVisible(true);  
   }  
}  

