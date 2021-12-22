import java.util.EmptyStackException;
import java.util.NoSuchElementException;

public class Program {
    public static void main(String[] args) {
        // write your code here
        STACK_TEST();
        QUEUE_TEST();
    }

    public static void STACK_TEST() {
        Stack stack1 = new Stack(3);
        stack1.push(0);
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        assert stack1.size() == 4 : stack1.size();

        int popped1 = stack1.pop();
        assert popped1 == 3 : popped1;
        assert stack1.size() == 3 : stack1.size();

        int popped2 = stack1.pop();
        assert popped2 == 2 : popped2;
        assert stack1.size() == 2 : stack1.size();

        int popped3 = stack1.pop();
        assert popped3 == 1 : popped3;
        assert stack1.size() == 1 : stack1.size();

        int popped4 = stack1.pop();
        assert popped4 == 0 : popped4;
        assert stack1.size() == 0 : stack1.size();

        try {
            int popped5 = stack1.pop();
        } catch (EmptyStackException e) {
            assert e.getClass().getName().equals("java.util.EmptyStackException") : e.getClass().getName();
        }
    }

    public static void QUEUE_TEST() {
        Queue queue1 = new Queue(3);
        queue1.push(0);
        queue1.push(1);
        queue1.push(2);
        queue1.push(3);
        assert queue1.size() == 4 : queue1.size();

        int popped1 = queue1.pop();
        assert popped1 == 0 : popped1;
        assert queue1.size() == 3 : queue1.size();

        int popped2 = queue1.pop();
        assert popped2 == 1 : popped2;
        assert queue1.size() == 2 : queue1.size();

        int popped3 = queue1.pop();
        assert popped3 == 2 : popped3;
        assert queue1.size() == 1 : queue1.size();

        int popped4 = queue1.pop();
        assert popped4 == 3 : popped4;
        assert queue1.size() == 0 : queue1.size();

        try {
            int popped5 = queue1.pop();
        } catch (NoSuchElementException e) {
            assert e.getClass().getName().equals("java.util.NoSuchElementException") : e.getClass().getName();
        }

    }
}
