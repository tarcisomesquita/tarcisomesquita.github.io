
// clear ; javac _main.java && java _main

public class _main
{
   public static void main(String args[])
   {
      _main_Objeto_Ponto pOriginal, pAlias, pCopia;             //preparacao das variaveis copia de objetos
      pOriginal = new _main_Objeto_Ponto((float)0.0,0.0f);      //(float)0.0 ou 0.0f; 0.0 eh double
      pOriginal.mostra();
      System.out.println(pOriginal.toString());
      
      pAlias = pOriginal;                                       //copiando atraves de atribuica (ambos estão no mesmo endereço)
      pCopia = new _main_Objeto_Ponto(pOriginal.x,pOriginal.y); //copiando atributo por atributo (são escritos em outro endereço)
      
      //resultados
      System.out.println("Original: " + pOriginal);
      System.out.println("Alias:    " + pAlias);
      System.out.println("");
      
      System.out.println("Modificando Alias.x para 2");
      pAlias.x = 2.0f;
      System.out.println("Veja como o original ficou: " + pOriginal);
      System.out.println("pCopia nao se modifica:     " + pCopia);
      System.out.println("");
      
      //comparacao de objetos
      System.out.println("Original == Alias: " + (pOriginal == pAlias) );
      System.out.println("Copia == Original: " + (pCopia == pOriginal) );
      System.out.println("");
      System.out.println("");

            
      System.out.println("Deixando atributos de Copia iguais aos de Original");
      pCopia.x=2;
      
      System.out.println("Original: " + pOriginal);
      System.out.println("Copia:    " + pCopia);
      System.out.println("");
      System.out.println("Copia == Original:     " + (pCopia == pOriginal) );
      System.out.println("Original.x == Copia.x: " + (pCopia.x == pOriginal.x) );
      System.out.println("Original.y == Copia.y: " + (pCopia.y == pOriginal.y) );
      System.out.println("");
      
   }
}


