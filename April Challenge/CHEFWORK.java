import java.util.Scanner;

class CHEFWORK {
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        
        int minRead = 10000000, minWrite = 10000000, minBoth = 10000000;
        
        int arr[] = new int[n];
        
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            int des = sc.nextInt();
            if(des == 1 && arr[i] < minRead){
                minRead = arr[i];
            }
            else if(des == 2 && arr[i] < minWrite){
                minWrite = arr[i];
            }
            else if(des == 3 && arr[i] < minBoth){
                minBoth = arr[i];
            }
        }
        if(minBoth < minRead + minWrite) System.out.println(minBoth);
        else System.out.println((minRead+minWrite));        
    }   
}
