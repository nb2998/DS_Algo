package dll;

import java.util.Arrays;
import java.util.Scanner;

import dll.DoubleLinkedList;

public class DLLClient{
    public static void main(String[] args) {
        
        DoubleLinkedList<Integer> myDll = new DoubleLinkedList<>();
        Scanner in = new Scanner(System.in);
        String ls = System.lineSeparator();
        String menu = "(IF) Insert first" + ls
                     +"(IL) Insert last" + ls
                     +"(RF) Remove first" + ls
                     +"(RL) Remove last" + ls
                     +"(R) Remove" + ls
                     +"(S) Search" + ls
                     +"(T) ToArray";

        while(true){
            
            System.out.println(menu);
            System.out.println("----");
            String op = in.nextLine();
            Integer element = null;
            switch(op) {
                
                case "IF":
                    element = Integer.parseInt(in.nextLine());
                    myDll.insertFirst(element);
                    break;
                
                case "IL":
                    element = Integer.parseInt(in.nextLine());
                    myDll.insertLast(element);
                    break;
                
                case "R":
                    element = Integer.parseInt(in.nextLine());
                    myDll.remove(element);
                    break;
                
                case "RF":
                    myDll.removeFirst();
                    break;
                
                case "RL":
                    myDll.removeLast();
                    break;
                
                case "S":
                    element = Integer.parseInt(in.nextLine());
                    System.out.println(myDll.search(element));
                    break;
                
                case "T":
                    System.out.println(Arrays.toString(myDll.toArray()));
                    break;

                default:
                    break;
            }

            System.out.println("----");

        }
    }
}