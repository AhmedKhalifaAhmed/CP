package test;
import java.util.Scanner;

public class Test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int N = (int) Math.pow(2, ((int)Math.ceil(Math.log(n) / Math.log(2))));
        System.out.println(N);
        sc.close();
    }
}