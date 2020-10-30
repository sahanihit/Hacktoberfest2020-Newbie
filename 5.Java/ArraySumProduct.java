import java.util.Scanner;
class Product {
	public static void main (String[] args) {
	    Scanner sc=new Scanner(System.in);
	        int n = sc.nextInt();                          /*Size of the array*/
	        int a[]=new int[n];                           
	        for(int i=0;i<n;i++){                          /*Input the elements of the array*/
	            a[i]=sc.nextInt();
	        }
	        int div=n/2;
	        int ls=0;                                   /*ls store the sum of left half of the array*/
	        int rs=0;                                   /*rs store the sum of right half of the array*/
	        for(int i=0;i<n;i++){
	            if(i<div){
	                ls+=a[i];
	            }
	            else
	            rs+=a[i];
	        }
	        int pr=ls*rs;                           /*pr to store the product of left half and right half*/
	        System.out.println(pr);
	}
}
