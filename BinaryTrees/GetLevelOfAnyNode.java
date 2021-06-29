
package javaapplication35;
import java.util.*;

class Node
{
    public int data;
    public Node lchild;
    public Node rchild;
    
    public Node()
    {
        this.lchild=this.rchild=null;
    }
    
    @Override
    public String toString()
    {
        return this.data+" ";
    }
}

class BinaryTree
{
    Scanner sc = new Scanner(System.in);
    public Node root = new Node();
    Queue<Node> q= new LinkedList<>();
    
    public BinaryTree()
    {
        this.root.lchild=this.root.rchild=null;
    }
    public void Insertion()
    {
        q.add(root);
        int num;
        while(!q.isEmpty())
        {
            Node n = q.poll();
            System.out.println("Enter the left child of "+n.data);
            num=sc.nextInt();
            if(num!=-1)
            {
                Node temp=new Node();
                temp.data=num;
                temp.lchild=temp.rchild=null;
                q.add(temp);
                n.lchild=temp;
                      
            }
            System.out.println("Enter the right child of "+n.data);
            num=sc.nextInt();
            if(num!=-1)
            {
                Node temp=new Node();
                temp.data=num;
                temp.lchild=temp.rchild=null;
                q.add(temp);
                n.rchild=temp;
                      
            }
        }
    }
    public void PreOrder(Node root)
    {
        if(root!=null)
        {
            System.out.print(root.data+" ");
            PreOrder(root.lchild);
            PreOrder(root.rchild);
        }
    }
    public int FindLevel(Node root,int num,int level)
    {
        //System.out.println(root);
        
        if(root==null)
        {
            return 0;
        }
        if(root.data==num)
        {
            return level;
        }
        
        int res = FindLevel(root.lchild,num,level+1);
        if(res!=0)
        {
            return res;
        }
        
        
        res = FindLevel(root.rchild,num,level+1);
        return res;
    }
}

public class JavaApplication35 {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        BinaryTree bt = new BinaryTree();
        System.out.println("Enter the root node");
        bt.root.data=sc.nextInt();
        bt.Insertion();
        bt.PreOrder(bt.root);
        System.out.println();
        int num;
        System.out.println("Enter the number whose level you want to know");
        num=sc.nextInt();
        System.out.println(bt.FindLevel(bt.root,num,0));
        
    }
    
}
