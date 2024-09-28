
// clear ; javac _extends.java ; java _extends

public class _extends {
   public static void main(String args[]) {
      Empregado pessoa1;
      pessoa1 = new Empregado("João Ninguem", 650.30);
      
      Gerente pessoa2;
      pessoa2 = new Gerente("Paulo Silva", 2500.67, "Maria José");
      
      System.out.println(pessoa1.nome);
      System.out.println(pessoa2.getSecretaria());
   }
}

class Empregado {
   public Empregado(String _nome, double _salario) {
      nome = _nome;
      salario = _salario;
   }
   
   public void aumentaSalario(double percentual) {
      salario *= 1 + percentual / 100;
   }
   
   String nome;
   double salario;
}

class Gerente extends Empregado {
   public Gerente(String _nome, double _salario, String _secretaria) {
      super(_nome, _salario); // Aqui eu chamo a super classe do Gerente
      secretaria = _secretaria;
   }
   
   public void aumentaSalario(double percentagem) {
      super.aumentaSalario(percentagem+0.5);
   }
   
   public String getSecretaria() {
      return secretaria;
   }
   
   public void setSecretaria(String _secretaria) {
      secretaria = _secretaria;
   }
   
   private String secretaria;
}

