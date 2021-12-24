import java.util.EmptyStackException;
import java.util.NoSuchElementException;

public class Program {
    public static void main(String[] args) {
        // write your code here
        STACK_TEST();
        QUEUE_TEST();
        LINKED_LIST_TEST();
    }

    public static void STACK_TEST() {
        Stack stack1 = new Stack(3);
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        stack1.push(4);
        stack1.push(5);
        stack1.push(6);
        stack1.push(7);
        stack1.push(8);
        assert stack1.size() == 8 : stack1.size();

        int popped1 = stack1.pop();
        assert popped1 == 8 : popped1;
        assert stack1.size() == 7 : stack1.size();

        int popped2 = stack1.pop();
        assert popped2 == 7 : popped2;
        assert stack1.size() == 6 : stack1.size();

        int popped3 = stack1.pop();
        assert popped3 == 6 : popped3;
        assert stack1.size() == 5 : stack1.size();

        int popped4 = stack1.pop();
        assert popped4 == 5 : popped4;
        assert stack1.size() == 4 : stack1.size();

        int popped5 = stack1.pop();
        assert popped5 == 4 : popped5;
        assert stack1.size() == 3 : stack1.size();

        int popped6 = stack1.pop();
        assert popped6 == 3 : popped6;
        assert stack1.size() == 2 : stack1.size();

        int popped7 = stack1.pop();
        assert popped7 == 2 : popped7;
        assert stack1.size() == 1 : stack1.size();

        int popped8 = stack1.pop();
        assert popped8 == 1 : popped8;
        assert stack1.size() == 0 : stack1.size();

        try {
            int popped9 = stack1.pop();
        } catch (EmptyStackException e) {
            assert e.getClass().getName().equals("java.util.EmptyStackException") : e.getClass().getName();
        }
    }

    public static void QUEUE_TEST() {
        Queue queue1 = new Queue(3);
        queue1.push(1);
        queue1.push(2);
        queue1.push(3);
        queue1.push(4);
        queue1.push(5);
        queue1.push(6);
        queue1.push(7);
        queue1.push(8);
        assert queue1.size() == 8 : queue1.size();

        int popped1 = queue1.pop();
        assert popped1 == 1 : popped1;
        assert queue1.size() == 7 : queue1.size();

        int popped2 = queue1.pop();
        assert popped2 == 2 : popped2;
        assert queue1.size() == 6 : queue1.size();

        int popped3 = queue1.pop();
        assert popped3 == 3 : popped3;
        assert queue1.size() == 5 : queue1.size();

        int popped4 = queue1.pop();
        assert popped4 == 4 : popped4;
        assert queue1.size() == 4 : queue1.size();

        int popped5 = queue1.pop();
        assert popped5 == 5 : popped5;
        assert queue1.size() == 3 : queue1.size();

        int popped6 = queue1.pop();
        assert popped6 == 6 : popped6;
        assert queue1.size() == 2 : queue1.size();

        int popped7 = queue1.pop();
        assert popped7 == 7 : popped7;
        assert queue1.size() == 1 : queue1.size();

        int popped8 = queue1.pop();
        assert popped8 == 8 : popped8;
        assert queue1.size() == 0 : queue1.size();

        try {
            int popped9 = queue1.pop();
        } catch (NoSuchElementException e) {
            assert e.getClass().getName().equals("java.util.NoSuchElementException") : e.getClass().getName();
        }
    }

    public static void LINKED_LIST_TEST() {
        // add test
        LinkedList linkedList = new LinkedList();
        linkedList.addFirst(1);
        linkedList.addFirst(2);
        linkedList.addLast(5);
        assert linkedList.get(0).equals(2) : linkedList.get(0);
        assert linkedList.get(1).equals(1) : linkedList.get(1);
        assert linkedList.get(2).equals(5) : linkedList.get(2);

        linkedList.add(1, 3);
        assert linkedList.get(1).equals(3) : linkedList.get(1);
        linkedList.add(2, 4);
        assert linkedList.get(2).equals(4) : linkedList.get(2);

        linkedList.addLast(6);
        assert linkedList.get(5).equals(6) : linkedList.get(5);

        assert linkedList.get(0).equals(2) : linkedList.get(0);
        assert linkedList.get(1).equals(3) : linkedList.get(1);
        assert linkedList.get(2).equals(4) : linkedList.get(2);
        assert linkedList.get(3).equals(1) : linkedList.get(3);
        assert linkedList.get(4).equals(5) : linkedList.get(4);
        assert linkedList.get(5).equals(6) : linkedList.get(5);

        assert linkedList.size() == 6;


        // remove test
        linkedList.remove(3);
        assert linkedList.get(3).equals(5) : linkedList.get(3);

        linkedList.remove(3);
        assert linkedList.get(3).equals(6) : linkedList.get(3);
        assert linkedList.size() == 4 : linkedList.size();

        linkedList.remove(3);
        assert linkedList.size() == 3 : linkedList.size();

        try {
            linkedList.get(3);
        } catch (NoSuchElementException e) {
            assert e.getClass().getName().equals("java.util.NoSuchElementException");
        }

        linkedList.remove(1);
        assert linkedList.get(1).equals(4) : linkedList.get(1);
        assert linkedList.size() == 2 : linkedList.size();
    }
}
