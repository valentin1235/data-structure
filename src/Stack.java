import java.util.EmptyStackException;

public class Stack {
    private int[] array;
    private final int originalSize;

    /**
     * this variable is the last index of the data which is valid upon value pushed.
     */
    private int top = -1;

    public Stack(int size) {
        this.array = new int[size];
        this.originalSize = size;
    }

    public void push(int val) {
        if (this.size() == this.originalSize) {
            this.array = this.copyArray(this.array, this.originalSize + this.originalSize);
        }
        ++this.top;
        array[this.top] = val;
    }

    public int pop() {
        if (this.top < 0) {
            throw new EmptyStackException();
        }

        int popped = this.array[this.top];
        --this.top;

        this.array = this.copyArray(this.array, this.originalSize);

        return popped;
    }

    public int size() {
        return this.top + 1;
    }

    private int[] copyArray(int[] array, int newSize) {
        int[] newArray = new int[newSize];
        for (int i = 0; i < this.size(); ++i) {
            newArray[i] = array[i];
        }

        return newArray;
    }
}
