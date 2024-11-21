public class MainPonto {
	public float x, y;
	public MainPonto(float x, float y) {
		this.x = x; this.y = y;
	}
	
	public void move(float dx, float dy) {
		this.x += dx; this.y += dy;
	}

	public String toString() {
		return "(" + this.x + "," + this.y + ")"; // (x,y)
	}
	
	public void mostra() {
		System.out.println("(" + this.x + "," + this.y + ")");
	}
	
	public boolean igual(MainPonto outro) {
		return ((outro.x == this.x) && (outro.y == this.y)); // this == outro?
	}
}
