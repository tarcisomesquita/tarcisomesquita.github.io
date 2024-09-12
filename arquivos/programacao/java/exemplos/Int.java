// clear ; javac Int.java && java Int

public class Int{
	public static void main(String args[]) {
		int valor = 23;
		System.out.println("Decimal: " + valor);
		System.out.println("Binario: " + Integer.toBinaryString(valor));
		System.out.println("Hexadecimal: 0x" + Integer.toHexString(valor));
		System.out.println("Octal: 0" + Integer.toOctalString(valor));
		
		System.out.println("");
		
		int n = Integer.valueOf("5");
		
		int a[] = {0,10,20};
		System.out.println("a = {" + a[0] + ", " + a[1] + ", " + a[2] + "}");
		
		// a.length; //armazena o numero de elementos do vetor a
		// int a[][]; //declara matriz de inteiros
	}
}
