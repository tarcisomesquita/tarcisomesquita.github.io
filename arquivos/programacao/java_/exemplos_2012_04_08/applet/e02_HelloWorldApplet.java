
// javac e02_HelloWorldApplet.java && firefox e02_HelloWorldApplet.html &

import java.applet.Applet;
import java.awt.Graphics;

public class e02_HelloWorldApplet extends Applet {
   public void paint(Graphics g) {
      g.drawString("Hello, Applet World", 100, 25);
   }
}

/*
import java.applet.*
import java.awt.*
public class hello extends Applet {
   Panel p1;
   Label l1;
   public hello() {
      p1 = new Panel();
      add (p1);
      l1 = new Label();
      p1.add(l1);
      l1.setText("Olá Internet ! ");
   }
}
*/

/*
Panel p1, p2;
...
p1.setBackground(Color.magenta);
p1.setForeground(Color.black);
Color c1 = new Color(230,240,250);
p1.setBackground(c1);

*/
