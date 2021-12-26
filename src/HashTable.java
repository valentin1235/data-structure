public class HashTable<K, V> {
    private final Node<K, V>[] nodes;
    private int size;
    private static class Node<K, V> {
        final K key;
        V value;
        Node<K, V> next;

        Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    public HashTable(int size) {
        @SuppressWarnings({"unchecked"})
        Node<K,V>[] nodes = (Node<K,V>[]) new Node[size];
        this.nodes = nodes;
    }

    public void push(K key, V data) {
        final int index = this.toIndex(key);

        final Node<K, V> node = this.nodes[index];
        if (node != null) {
            if (node.key.equals(key)) {
                node.value = data;
            } else {
                Node<K, V> currentNode = node.next;
                while (true) {
                    if (currentNode == null) {
                        node.next = new Node<>(key, data);
                        this.size++;
                        break;
                    } else if (currentNode.next == null) {
                        currentNode.next = new Node<>(key, data);
                        this.size++;
                        break;
                    } else {
                        currentNode = currentNode.next;
                    }

                }
            }
        } else {
            this.nodes[index] = new Node<>(key, data);
            this.size++;
        }
    }

    public V get(K key) {
        Node<K, V> node = this.nodes[this.toIndex(key)];

        if (node == null) {
            return null;
        }

        V value = null;
        if (node.key == key) {
            value = node.value;
        } else if (node.next != null) {
            Node<K, V> currentNode = node.next;
            while (true) {
                if (currentNode == null) {
                    break;
                } else if (currentNode.key.equals(key)) {
                    value = currentNode.value;
                    break;
                } else {
                    currentNode = currentNode.next;
                }
            }
        }

        return value;
    }

    public void remove(K key) {
        final int index = this.toIndex(key);
        Node<K, V> node = this.nodes[index];
        if (node != null) {
            if (node.next == null) {
                this.nodes[index] = null;
                this.size--;
            } else {
                while (true) {
                    if (node == null) {
                        break;
                    } else if (node.next != null && node.next.key.equals(key)) {
                        node.next = node.next.next;
                        this.size--;
                        break;
                    } else {
                        node = node.next;
                    }
                }
            }
        }
    }

    public int size() {
        return this.size;
    }

    private int toIndex(K key) {
        return key.hashCode() % this.nodes.length;
    }
}
