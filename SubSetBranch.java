package net.zealot.test;
import java.util.*;
public class {
	/**
	 * 1.�󼯺�(a,b,c,d)���Ӽ��� �磺a,b,c,d,ab,cd,bc...............
		 
		         "" "end"
	      a              -a   end
	   b    -b         b    -b end
	 c  -c c  -c    c   -c c   -c  end
	 
	abc ab ac a      bc b c ""
	layer = 3
	currStr = ""
	abc ab ac a bc b c "" end
	
	*/
	public static void subSet(){
		Queue<String> que = new LinkedList<>();
		String[] strs = {"","a","b","c","d"};
		int n = 4;
		String end = "end";
		que.offer("");
		que.offer(end);//""��ʾһ��Ľ�β
		int layer = 1;//��ʾ��ǰ�Ĳ��������4��
		String curr;//��ʾ��ǰ�Ľ��
		while(true){
			curr = que.poll();	//��һ��Ҫ�õ�""
			que.offer(curr+strs[layer]);//ѡ��ڵ�
			que.offer(curr+"");//ѡ�ҽڵ�
			if(que.peek() == end){	//�����һ���ĩβ����i++��һ����ĸ
				que.poll();
				if(layer >= n) 
					break;
				que.offer(end);
				layer++;
			}
		}
		System.out.println(que);
	}
	publis static void main(String[] args){
		subSet();
	}
}