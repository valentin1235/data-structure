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
        @SuppressWarnings({"rawtypes", "unchecked"})
        Node<K,V>[] nodes = (Node<K,V>[]) new Node[size];
        this.nodes = nodes;
    }

    public void push(K key, V data) {
        final int hashed = this.toIndex(key);

        final Node<K, V> node = nodes[hashed];
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
            this.nodes[hashed] = new Node<>(key, data);
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
            Node<K, V> nextNode = node.next;
            while (true) {
                 if (nextNode.key.equals(key)) {
                    value = nextNode.value;
                    break;
                } else {
                    nextNode = nextNode.next;
                }
            }
        }

        return value;
    }

    public int size() {
        return this.size;
    }

    private int toIndex(K key) {
        return key.hashCode() % this.nodes.length;
    }
}
