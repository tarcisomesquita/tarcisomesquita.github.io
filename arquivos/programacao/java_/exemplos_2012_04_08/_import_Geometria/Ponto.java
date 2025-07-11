
package _import_Geometria;

public class Ponto
{
   public float x,y;
   public Ponto(float ax,float ay) { // Aqui não pode ter o void. Por quê?
      this.x = ax; this.y = ay;
   }
   
   public void mostra() {
      System.out.println("("+this.x+","+this.y+")");
   }
}

