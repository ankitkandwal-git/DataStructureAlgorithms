package DynamicProgramming.FrogJump2.Tabulation;

public class Main {
    static int frogJump(int n , int[]height,int k){
        int[] dp = new int[n];
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int min_energy = Integer.MAX_VALUE;
            for(int j=1;j<=k;j++){
                if((i-j)>=0){
                    int jump = Math.abs(height[i]-height[i-j]) + dp[i-j];
                    min_energy = Math.min(min_energy,jump);
                }
            }
            dp[i] = min_energy;
        }
        return dp[n-1];
    } 
    public static void main(String[]args){
        try(java.util.Scanner sc = new java.util.Scanner(System.in)){
            System.out.print("Enter number of stairs: ");
            int n = sc.nextInt();
            System.out.print("Enter maximum jump length: ");
            int k = sc.nextInt();
            int[] height = new int[n];
            for(int i=0;i<n;i++){
                System.out.print("Enter height of stair ");
                height[i] = sc.nextInt();
            }
            System.out.println("Minimum energy required to reach the top: " + frogJump(n, height, k));
        }
    }
}
