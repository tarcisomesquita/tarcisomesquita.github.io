public class quadrado implements figura {
   int l;          // lado do quadrado
   int x;         // centro da fig. x
   int y;         // centro da fig. y
   
   public quadrado(int x1, int y1, int l1) {
        x = x1; y=y1; l = l1;
   }
   
   public void desenha() {
      System.out.println("Desenhando quadrado (" + x + "," + y + ") lado "+ l );
   }
   
   public void apaga() {
      System.out.println("Apagando quadrado (" + x + "," + y + ") lado " + l );
   }
   
   public void move (int x1, int y1) {
      this.apaga();
      x = x1;
      y = y1;
      this.desenha();
  }
}

