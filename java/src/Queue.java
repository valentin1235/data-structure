import java.util.NoSuchElementException;

public final class Queue {
    private int[] array;
    private final int originalSize;
    private int front;

    /**
     * this variable is the last index of the data which is valid upon value pushed.
     */
    private int back = -1;

    public Queue(int size) {
        this.array = new int[size];
        this.originalSize = size;
    }

    public void push(int val) {
        if (this.size() == array.length) {
            this.array = this.extendQueue(this.array, array.length + this.originalSize);
        }

        if (this.array.length == 0) {
            ++this.front;
        }

        ++this.back;
        this.array[this.back] = val;
    }

    public int pop() {
        if (this.front > this.back) {
            throw new NoSuchElementException();
        }
        int popped = this.array[this.front];
        ++this.front;

        return popped;
    }

    public int size() {
        return this.back - this.front + 1;
    }

    private int[] extendQueue(int[] array, int newSize) {
        int[] newArray = new int[newSize];
        int newArrayIndex = 0;
        for (int i = this.front; i < this.back + 1; ++i) {
            newArray[newArrayIndex] = array[i];
            ++newArrayIndex;
        }

        this.front = 0;
        this.back = this.size() - 1;

        return newArray;
    }
}
