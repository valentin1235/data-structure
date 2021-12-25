public class HashTable {
    private final LinkedList[] lists;
    private final int size;

    public HashTable(int size) {
        this.lists = new LinkedList[size];
        this.size = size;
    }

    public void add(Object data) {
        final int key = data.hashCode() % this.size;

        LinkedList list = lists[key];
        if (list == null) {
            lists[key] = new LinkedList();
        }

        lists[key].addLast(data);
    }

    public LinkedList get(int key) {
        return lists[key];
    }

    public void remove(int key) {
        LinkedList list = lists[key];
        if (list != null) {
            list.removeLast();
            if (list.size() == 0) {
                lists[key] = null;
            }
        }
    }
}
