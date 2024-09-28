// javac appfunc.java && firefox appfunc.html &

import java.applet.*;
import java.awt.*;
//import empregado;

public class appfunc extends Applet {
   Panel p1;
   Label l1;
   empregado carlos;
   
   public appfunc() {
      carlos = new empregado("Carlos Silva","15.499.789-X","17.4859",1980);
      setLayout(new BorderLayout() );
      p1 = new Panel();
      add("Center",p1);
      l1 = new Label(carlos.nomefunc + " Matr.:" + carlos.matricula + " RG.:" +carlos.rgeral);
      p1.add(l1);
   }
}

