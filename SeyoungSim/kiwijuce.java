package ch05;

public class kiwijuce {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] capacities = {20,20};
		int[] bottles = {5,8};
		int[] fromId = {0};
		int[] toId = {1};
		
		
		int[] result = thePouring(capacities,bottles,fromId,toId);
	}

	public static int[] thePouring(int[] capacities, int[] bottles,int[] fromId,int[]toId) {
		
		boolean b = true;
		int temp=0;
		int i=0;
		
		while(b){
			
			temp = bottles[fromId[i]]+bottles[toId[i]];
			
			if(temp < capacities[toId[i]]) {
			   bottles[toId[i]] = temp;
			   bottles[fromId[i]] = 0;
			}
			
			else {
				bottles[toId[i]] = capacities[toId[i]];
				bottles[fromId[i]] = temp - capacities[toId[i]];
				b= false;
			}
				
			
			if(i == fromId.length)
				b=false;
			
		}
		
		return bottles;
	}
}
