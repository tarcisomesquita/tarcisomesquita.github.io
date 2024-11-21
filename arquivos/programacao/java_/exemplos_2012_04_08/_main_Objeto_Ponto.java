
public class _main_Objeto_Ponto
{
   public float x,y;
   public _main_Objeto_Ponto(float ax,float ay) { // Aqui não pode ter o void. Por quê?
      this.x = ax; this.y = ay;
   }
   
   public void move(float dx,float dy) {
      this.x+=dx; this.y+=dy;
   }
   
   public String toString() {
      return "("+this.x+","+this.y+")"; //(x,y)
   }
   
   public void mostra() {
      System.out.println("("+this.x+","+this.y+")");
   }
   
   public boolean igual(_main_Objeto_Ponto outro) {
      return ((outro.x==this.x) && (outro.y==this.y)); //this==outro?
   }
}

