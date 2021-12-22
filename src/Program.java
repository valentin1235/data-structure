
public class Program {
    public static void main(String[] args) {
        // write your code here
        STACK_TEST();

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
    }
}
