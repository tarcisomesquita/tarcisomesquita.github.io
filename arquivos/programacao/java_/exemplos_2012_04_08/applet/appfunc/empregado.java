// não é necessário dar este import
import java.lang.*;

public class empregado extends Object {
   String nomefunc;
   String rgeral;
   String matricula;
   int anomatricula;
   
   // método construtor
   public empregado(String nfunc, String rg, String matri, int anomat) {
      this.nomefunc = nfunc;
      this.rgeral = rg;
      this.matricula = matri;
      this.anomatricula = anomat;
   }
   
   // método que retorna valor inteiro
   public int mtTempoServico() {
      return (1997 - this.anomatricula);
   }
   
   // Se método não retornar valor, usa-se a palavra void Ex. public void <nome método>()
}

