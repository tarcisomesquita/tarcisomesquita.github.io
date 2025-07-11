
// clear ; javac Main.java && java Main

public class Main {
	public static void main(String args[]) {
		MainPonto pontoOriginal = new MainPonto((float)0.0, 0.0f);                 // (float)0.0 ou 0.0f; 0.0 eh double
		MainPonto pontoAlias    = pontoOriginal;                                   // copiando através de atribuicão (ambos estão no mesmo endereço)
		MainPonto pontoCopia    = new MainPonto(pontoOriginal.x, pontoOriginal.y); // copiando atributo por atributo (são escritos em outro endereço)
		
		
		//resultados
		System.out.println("pontoOriginal: " + pontoOriginal);
		System.out.println("pontoAlias:    " + pontoAlias);
		System.out.println("pontoCopia:    " + pontoCopia);
		System.out.println("");
		
		System.out.println("Modificando pontoAlias.x para 2");
		pontoAlias.x = 2.0f;
		
		System.out.println("pontoOriginal: " + pontoOriginal);
		System.out.println("pontoAlias:    " + pontoAlias);
		System.out.println("pontoCopia:    " + pontoCopia);
		System.out.println("");
		
		//comparacao de objetos
		System.out.println("Original == Alias:    " + (pontoOriginal == pontoAlias   ) );
		System.out.println("Copia    == Original: " + (pontoCopia    == pontoOriginal) );
		System.out.println("");
	}
}
