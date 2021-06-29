
package leftviewofbinarytree;

import java.util.*;


class Node
{
    int data;
    Node lchild;
    Node rchild;
    
    public Node(int data)
    {
        this.data=data;
        this.lchild=this.rchild=null;
    }
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
    static int maxLevel=0;
    Scanner sc = new Scanner(System.in);
    Node root=new Node();
    public BinaryTree()
    {
        
        root.lchild=root.rchild=null;
    }
    
    Queue<Node> q = new LinkedList<>();
    
    public void Insertion()
    {
        q.add(root);
        int num;
        
        while(!q.isEmpty())
        {
            Node p = q.poll();
            System.out.println("Enter the left child of "+p.data);
            num=sc.nextInt();
            if(num!=-1)
            {
                Node t = new Node();
                t.data=num;
                t.lchild=t.rchild=null;
                p.lchild=t;
                q.add(t);
            }
            System.out.println("Enter the right child of "+p.data);
            num=sc.nextInt();
            if(num!=-1)
            {
                Node t = new Node();
                t.data=num;
                t.lchild=t.rchild=null;
                p.rchild=t;
                q.add(t);
            
        }
        
        }
    }
    
//    public void Preorder(Node root)
//    {
//        if(root!=null)
//        {
//            System.out.print(root+" ");
//            Preorder(root.lchild);
//            Preorder(root.rchild);
//        }
//    }
    public void Left(Node root,int level)
    {
        
        
        if(root==null)
        {
            return;
        }
        if(level>=maxLevel)
        {
            System.out.print(root.data+" ");
            maxLevel=level;
        }
        
        Left(root.lchild,level+1);
        Left(root.rchild,level+1);
    }
}

public class LeftViewOfBinaryTree {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        System.out.println("Enter the root node");
        BinaryTree bt = new BinaryTree();
        bt.root.data=sc.nextInt();
        bt.Insertion();
//        bt.Preorder(bt.root);
        System.out.println();
        
        bt.Left(bt.root,0);
        
    }
    
}
