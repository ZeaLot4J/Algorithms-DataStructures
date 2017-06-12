package net.zealot.test;
import java.util.*;
public class PermutationBranch{
	//È«ÅÅÁÐ
	/*
	 *                "" end
	 *       1        2        3   end
	 *    1  2  3  1  2  3  1  2  3 end
	 *   123123123123123123123123123  end    
	 * que:123 132 213 231 312 321 end
	 * */
	public static void permutation(){
		Queue<String> que = new LinkedList<>();
		String[] numbers = {"0","1","2","3","4","5"};
		int n = 5;
		boolean[][] flag = new boolean[n+1][n+1];
		int layer = 1;
		int i;
		String end = "end";
		String curr = "";
		que.offer("");
		que.offer(end);
		
		while(true){
			curr = que.poll();
			for(i = 1; i<=n; i++){
				if(!curr.contains(numbers[i]))
					que.offer(curr+numbers[i]);
			}
			if(que.peek() == end){
				que.poll();
				if(layer >= n)
					break;
				que.offer(end);
				layer++;
			}
		}
		System.out.println(que);
	}
	public static void main(String[] args){
		permutation();
	}
}