import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       int arr[] = new int[n];
       int countp=0;
       for(int i=0;i<n;i++){
           arr[i] = sc.nextInt();
       }
       double a=1;
        int b=0;
           int count=0;
           int num=2;
           while(count!=n)
           {
               boolean prime=true;
               for (int i=2;i<=Math.sqrt(num);i++)//efficiency matters
               {
                   if (num%i==0)
                   {
                       prime=false;
                       break;
                   }

               }
               if (prime)
               {
                   a = a*Math.pow(num,arr[0]);
                   b++;
                   count++;
               }
               num++;

           }
           long P=1;
           for(int i=1;i<=Math.sqrt(a);i++){
               if(a%i==0){
                   if(a/i==i){
                       P = P*i;
                   }
                   else{
                       P = (long)(P*i*(a/i));
                   }
               }
        }
         System.out.println(P);
          for(int i=1;i<Math.sqrt(P);i++){
               if(P%i==0){
                   if(a/i==i){
                       countp++;
                   }else{
                       countp+=2;
                   }
               }
          }
          System.out.println((countp+1)%1000000007);

    }
}
