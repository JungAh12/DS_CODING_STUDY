import java.util.Scanner;

public class KiwiJuice {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] capacities= {14,35,86,58,25,62};
		int[] bottles= {6,34,27,38,9,60};
		int[] fromId= {1,2,4,5,3,3,1,0};
		int[] toId= {0,1,2,4,2,5,3,1};
		
		int[] result= thePouring(capacities, bottles, fromId, toId);
		for(int r:result)
			System.out.println(r);
		
	}
	

	public static int[] thePouring(int[] capacities, int[]bottles, int[] fromId, int[] toId) {
		/*
		for(int i=0;i<fromId.length;++i) {
			int f=fromId[i];
			int t=toId[i];
			int tmp=capacities[t]-bottles[t];
			if(tmp>=bottles[f]) {
				bottles[t]+=bottles[f];
				bottles[f]=0;
			}
			else {
				bottles[t]+=(tmp);
				bottles[f]-=(tmp);
			}
			
		}
		*/
		for(int i=0;i<fromId.length;++i) {
			int sum=bottles[fromId[i]]+bottles[toId[i]];
			bottles[toId[i]]=Math.min(sum,  capacities[toId[i]]);
			bottles[fromId[i]]=sum-bottles[toId[i]];
			
		}
		
		
		
		
		
		return bottles;
		
	}


}
