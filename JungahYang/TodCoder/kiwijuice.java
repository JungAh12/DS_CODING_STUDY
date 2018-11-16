package kiwijuice;

import java.util.Scanner;

public class kiwijuice {
	public static int [] thePouringJuice(int[] capacities, int[] bottles, int[] fromId, int[] toId) {
		for(int i=0;i<fromId.length; i++) {
			int f = fromId[i];
			int t = toId[i];
			int space = capacities[t]- bottles[t];
			
			if(space>=bottles[f]) {
				int vol = bottles[f];
				bottles[f] = 0;
				bottles[t] += vol;
				
			}
			else {
				int vol = space;
				bottles[f] -= vol;
				bottles[t] += vol;
			}

		}
		return bottles;
	}
	
	public static void main(String args[]) {
		/*
		 * (1) 키위주스를 0~N-1이라고 번호 매겨진 병에 붓는다.
		 * (2) i번째 병의 용량은 capacities[i]
		 * (3) i번째의 주스양은 bottles[i]
		 * (4) 주스를 fromId[i] 병에서 toid[i] 병으로 붓는다.
		 * (5) fromId[i]가 텅 비거나 toId[i]가 꽉차면 붓는 행동을 멈춘다. 
		 * (6) return 값은 각각의 i번째 병에 남은 주스의 양으로 한다.
		 */
		Scanner s = new Scanner(System.in);
//		int[] bottles;
//		int[] capacities;
//		int[] fromId;
//		int[] toId;
//		int juicenum;
		/*
		System.out.print("병의 개수 (total juice num)");
		juicenum = s.nextInt();
		bottles = new int[juicenum];
		capacities = new int[juicenum];
		fromId = new int[juicenum];
		toId = new int[juicenum];
		*/
		int [] bottles = {5,8};
		int []capacities = {10,10};
		int []fromId = {0};
		int []toId = {1};
		
		thePouringJuice(capacities,bottles,fromId,toId);
		
		
	}
}
