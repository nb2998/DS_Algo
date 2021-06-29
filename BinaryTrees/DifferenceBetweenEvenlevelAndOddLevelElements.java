
package differencebetweenevenlevelandoddlevelelements;
import java.util.*;

class Node
{
    int data;
    Node lchild;
    Node rchild;
    
    public Node(int value)
    {
        this.data=value;
        this.lchild=this.rchild=null;
    }
    public Node()
    {
        this.lchild=this.rchild=null;
    }
}

class BinaryTree
{
    Scanner sc = new Scanner(System.in);
    Node p = new Node();
    Node root = new Node();
    Queue<Node> q;
    
    public BinaryTree()
    {
        q = new LinkedList<>();
        q.add(root);
    }
    public void Insert()
    {
        while(!q.isEmpty())
        {
            p=q.poll();
            System.out.println("Enter the left chlid of "+p.data);
            int num;
            num = sc.nextInt();
            if(num !=-1)
            {
                Node r = new Node(num);
                r.lchild=r.rchild=null;
                q.add(r);
                p.lchild=r;
            }
            System.out.println("Enter the right chlid of "+p.data);
            
            num = sc.nextInt();
            if(num !=-1)
            {
                Node r = new Node(num);
                r.lchild=r.rchild=null;
                q.add(r);
                p.rchild=r;
            }
        }
    }
}

public class DifferenceBetweenEvenlevelAndOddLevelElements {
    public static void Preorder(Node P)
    {
        if(P!=null)
        {
            System.out.print(P.data+" ");
            Preorder(P.lchild);
            Preorder(P.rchild);
        }
    }
    public static int EvenOddDifference(Node P)
    {
        if(P==null)
        {
            return 0;
        }
        else
        {
            return P.data - EvenOddDifference(P.lchild)-EvenOddDifference(P.rchild);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the root node");
        int num =sc.nextInt();
        BinaryTree bt = new BinaryTree();
        bt.root.data=num;
        bt.Insert();
        System.out.println();
        System.out.println("Preorder");
        Preorder(bt.root);
        System.out.println();
        System.out.println(EvenOddDifference(bt.root));
                
                
    }
    
}
