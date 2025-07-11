
// clear ; javac _int.java && java _int

public class _int
{
   public static void main(String args[])
   {
      int a[];        //declara vetor de inteiros 'a'
      int b = 5;
      a = new int[3]; //aloca vetor 'a' com 3 posicoes
      a[0] = 0;
      a[1] = 10;
      a[2] = 20;
      // int a[3]={0,10,20}; pode se fazer tudo de uma vez
      System.out.println("a = {" + a[0] + ", " + a[1] + ", " + a[2] + "}");
      System.out.println("b = " + b);
   }
}

// a.length; //armazena o numero de elementos do vetor a

// int a[][]; //declara matriz de inteiros a
// a=new int[3][3]; //aloca matriz 3x3, 9 celulas

//as duas linhas anteriores podem ser abreviadas por:
// int a[]=new int[3][3];

//alem disso se voce quiser inicializar a matriz a ja na declaracao:
//int a[3][3]={{0,10,20},{30,40,50},{60,70,80}};

