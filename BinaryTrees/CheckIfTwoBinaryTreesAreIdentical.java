
package javaapplication34;
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
        return this.data +" ";
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
    
    public boolean isIdentical(Node r1,Node r2)
    {
        if(r1==null && r2==null)
        {
            return true;
        }
        if(r1==null || r2==null)
        {
            return false;
        }
        
        return r1.data==r2.data && isIdentical(r1.lchild,r2.lchild) && isIdentical(r1.rchild,r2.rchild);
    }
            
}


public class JavaApplication34 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        BinaryTree bt1 = new BinaryTree();
        System.out.println("Enter the root node of hte first tree");
        bt1.root.data=sc.nextInt();
        bt1.Insertion();
        bt1.PreOrder(bt1.root);
        System.out.println();
        System.out.println("Enter the root node of the second tree");
        BinaryTree bt2 = new BinaryTree();
        bt2.root.data=sc.nextInt();
        bt2.Insertion();
        bt2.PreOrder(bt2.root);
        BinaryTree bt = new BinaryTree();
        System.out.println();
        System.out.println(bt.isIdentical(bt1.root, bt2.root));
        
        
    }
    
}
