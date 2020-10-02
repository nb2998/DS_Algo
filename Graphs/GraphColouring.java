import java.util.Arrays;

public class GraphColouring{
	 public static void main(String[] args){
		  int[][] graph={{0, 1, 1, 1},
				  {1, 0, 1, 0},
				  {1, 1, 0, 1},
				  {1, 0, 1, 0}};
		  int colours[]={'r','b','g'};
		  int[] colored=new int[graph.length];
		  int[] answer=new int[graph.length];
		  System.out.println(ColourGraph(graph,colours,colored,answer,0));

		  for(int i=0;i<answer.length;i++){
			   System.out.println(answer[i]);
		  }


	 }

	 static boolean ColourGraph(int[][] graph,int colours[],int colored[],int answer[],int node){
		  if(isAllColouredExcept(colored,node)){
			   int col=findAvailableColourFor(graph,colored,answer,colours,node);
			   System.out.println("available "+col);
			   if(col!=-1){
					colored[node]=1;
					answer[node]=col;
					return true;
			   }
			   else{return false;}
		  }
		  int len=graph.length;

		  int c=findAvailableColourFor(graph,colored,answer,colours,node);
		  System.out.println("available "+c);
		  if(c==-1){
			   return false;
		  }
		  answer[node]=c;
		  System.out.println("setting "+node+" as "+c);
		  colored[node]=1;

		  for(int i=0;i<len;i++){
			   if(colored[i]==0){
					if(ColourGraph(graph, colours, colored, answer, i)==false){
						 return false;
					}
			   }
		  }
		  return true;
	 }

	 static boolean isAllColouredExcept(int[] coloured,int node){
		  for(int i=0;i<coloured.length;i++){
			   if(i==node){
					if(coloured[node]!=0){return false;}
			   }
			   else{
					if(coloured[i]!=1){return false;}
			   }
		  }
		  return true;
	 }

	 static int findAvailableColourFor(int graph[][],int[] colored,int[] answer,int colours[],int node){
		  int len=colored.length;
		  int availableArray[]=new int[colours.length];
		  Arrays.fill(availableArray,1);
		  for(int i=0;i<len;i++){
			   if(graph[node][i]>0){
					if(colored[i]==1){
						 int colour=answer[i];
						 availableArray[colour]=0;
					}
			   }
		  }
		  for(int i=0;i<availableArray.length;i++){
			   if(availableArray[i]==1){
					return i;
			   }
		  }
		  return -1;
	 }
}
