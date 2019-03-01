import java.util.Scanner;

class ADDREV{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for(int i=0; i<t; i++){
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();

            int n1_rev = revNum(n1);
            int n2_rev = revNum(n2);

            System.out.println(revNum(n1_rev + n2_rev));
        }

        sc.close();
    }
    
    static int revNum(int num){
        
        int ans = (num%10);
        num /= 10;

        while(num > 0){
        
            ans = ans*10 + num%10;
            num /= 10;
        
        }

        return ans;
    }
}