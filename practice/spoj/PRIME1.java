import java.util.Scanner;

class PRIME1{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();

        while(t-- > 0){
            int m = sc.nextInt();
            int n = sc.nextInt();

            for(int k=m; k<=n; k++){
                if(isPrime(k)) System.out.println(k);
            }

            System.out.println();
        }

        sc.close();
    }

    static boolean isPrime(int n){
        boolean flag = true;
        for(int i=2; i<=(int)Math.sqrt(n); i++){
            if(n%i == 0){
                flag = false;
                break;
            }
        }
        if (n==1) flag = false;
        return flag;
    } 
}