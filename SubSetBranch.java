package net.zealot.test;
import java.util.*;
public class {
	/**
	 * 1.求集合(a,b,c,d)的子集， 如：a,b,c,d,ab,cd,bc...............
		 
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
		que.offer(end);//""表示一层的结尾
		int layer = 1;//表示当前的层数，最多4层
		String curr;//表示当前的结果
		while(true){
			curr = que.poll();	//第一次要拿到""
			que.offer(curr+strs[layer]);//选左节点
			que.offer(curr+"");//选右节点
			if(que.peek() == end){	//如果是一层的末尾，则i++下一个字母
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