import java.util.NoSuchElementException;

public class LinkedList {
    private Node first;
    private Node last;
    private int size;
    private class Node {
        Object data;
        Node next;

        Node(Object data) {
            this.data = data;
        }
    }

    public void addLast(Object data) {
        final Node newNode = new Node(data);

        if (this.size == 0) {
            this.first = newNode;
            this.last = newNode;
        }

        this.last.next = newNode;
        this.last = newNode;

        this.size++;
    }

    public void addFirst(Object data) {
        final Node newNode = new Node(data);

        if (this.size == 0) {
            this.first = newNode;
            this.last = newNode;
        }

        newNode.next = this.first;
        this.first = newNode;

        this.size++;
    }

    public void add(int index, Object data) {
        Node newNode = new Node(data);

        if (index == 0) {
            this.addFirst(data);
        }

        Node prevNode = this.getNodeOrNull(index - 1);
        if (prevNode != null) {
            newNode.next = prevNode.next;
            prevNode.next = newNode;

            this.size++;
        }
    }

    public Object get(int index) {
        Node node = this.getNodeOrNull(index);
        if (node == null) {
            throw new NoSuchElementException();
        }

        return node.data;
    }

    public void removeLast() {
        this.remove(this.size - 1);
    }

    public int size() {
        return this.size;
    }

    public void remove(int index) {
        if (index == 0) {
            this.first = this.first.next;
        }

        Node prevNode = this.getNodeOrNull(index - 1);
        if (prevNode != null && prevNode.next != null) {
            Node target = prevNode.next;
            prevNode.next = target.next;
            target.next = null;

            this.size--;
        }
    }

    private Node getNodeOrNull(int index) {
        if (index > this.size - 1) {
            return null;
        }

        Node currentNode = this.first;

        for (int i = 1; i <= index; ++i) {
            currentNode = currentNode.next;
        }

        return currentNode;
    }
}
