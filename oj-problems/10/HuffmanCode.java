import java.util.*;
import java.util.Map.Entry;

class Node {
    char ch;
    int freq;
    Node left = null, right = null;

    Node(char ch, int freq) {
        this.ch = ch;
        this.freq = freq;
    }

    public Node(char ch, int freq, Node left, Node right) {
        this.ch = ch;
        this.freq = freq;
        this.left = left;
        this.right = right;
    }
}

public class HuffmanCode {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();

        Map<Character, String> huffmanCode = buildHuffmanTree(text);

        // sort
        ArrayList<String> list = new ArrayList<>();
        LinkedHashMap<Character, String> sortedRes = new LinkedHashMap<>();
        for (Map.Entry<Character, String> entry : huffmanCode.entrySet()) {
            list.add(entry.getValue());
        }
        Collections.sort(list, new Comparator<String>() {
            public int compare(String str, String str1) {
                return Integer.valueOf(str) - Integer.valueOf(str1);
            }
        });
        for (String str : list) {
            for (Entry<Character, String> entry : huffmanCode.entrySet()) {
                if (entry.getValue().equals(str)) {
                    sortedRes.put(entry.getKey(), str);
                }
            }
        }

        // output
        for (Character key : sortedRes.keySet()) {
            System.out.println(key + ":" + sortedRes.get(key));
        }
    }

    static void encode(Node root, String str, Map<Character, String> huffmanCode) {
        if (root == null) {
            return;
        }

        if (root.left == null && root.right == null) {
            huffmanCode.put(root.ch, str);
        }

        encode(root.left, str + '0', huffmanCode);
        encode(root.right, str + '1', huffmanCode);
    }

    public static Map<Character, String> buildHuffmanTree(String text) {
        Map<Character, Integer> freq = new HashMap<>();
        for (char ch : text.toCharArray()) {
            freq.put(ch, freq.getOrDefault(ch, 0) + 1);
        }

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(l -> l.freq));

        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            pq.add(new Node(entry.getKey(), entry.getValue()));
        }

        while (pq.size() != 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            int sum = left.freq + right.freq;
            pq.add(new Node('\0', sum, left, right));
        }

        Node root = pq.peek();

        Map<Character, String> huffmanCode = new HashMap<>();
        encode(root, "", huffmanCode);

        return huffmanCode;
    }

}
