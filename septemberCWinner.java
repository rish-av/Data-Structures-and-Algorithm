import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
       while(t-->0){
           int n = sc.nextInt();
           long arr[] = new long[n];
           for(int i=0;i<n;i++){
               arr[i] = sc.nextLong();
           }
           int count=0;
           for(int i=0;i<n;i++){
               long temp = arr[i];
               while(temp%2==0){
                   temp = temp/2;
                   count++;
               }
           }
           if(count%2==0){
               System.out.println("Alan");
           }else{
               System.out.println("Charlie");
           }

       }
    }
}
