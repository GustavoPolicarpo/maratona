# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Teste de Seleção 1
# Nível: 1
# Categoria: INICIANTE
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1035


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) throws IOException {
        
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int c = input.nextInt();
        int d = input.nextInt();
        if(b>c && d>a && c+d>a+b && c>0 && d>0 && a%2==0){
            System.out.println("Valores aceitos");
        }else{
            System.out.println("Valores nao aceitos");
        }
        
    }
    
}
