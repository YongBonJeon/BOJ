import java.util.*;

public class Main {
    static int N, Q;

    static class Node {
        int parent, child1 = -1, child2 = -1;
        int power;
        boolean alarm = true;

        Node(){
        }
    }

    static Node[] tree;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        Q = sc.nextInt();

        tree = new Node[N+1];
        for(int i = 0 ; i <= N ; i++)
            tree[i] = new Node();

        while(Q-- > 0) {
            int cmd = sc.nextInt();

            // 초기 설정
            if(cmd == 100) {
                for(int i = 1 ; i <= N ; i++) {
                    int parent = sc.nextInt();
                    tree[i].parent = parent;

                    if(tree[parent].child1 == -1)
                        tree[parent].child1 = i;
                    else
                        tree[parent].child2 = i;
                }
                for(int i = 1 ; i <= N ; i++) {
                    tree[i].power = sc.nextInt();
                }

                //print_tree();
            }
            // 알림망 설정 ON/OFF
            else if(cmd == 200) {
                int num = sc.nextInt();
                tree[num].alarm = !tree[num].alarm;
            }
            // 권한 세기 변경
            else if(cmd == 300) {
                int num = sc.nextInt();
                tree[num].power = sc.nextInt();
            }
            // 부모 채팅방 교환
            else if(cmd == 400) {
                int c1, c2;
                c1 = sc.nextInt();
                c2 = sc.nextInt();

                int child1_parent = tree[c1].parent;
                int child2_parent = tree[c2].parent;

                tree[c2].parent = child1_parent;
                tree[c1].parent = child2_parent;

                if(tree[child1_parent].child1 == c1)
                    tree[child1_parent].child1 = c2;
                else
                    tree[child1_parent].child2 = c2;

                if(tree[child2_parent].child1 == c2)
                    tree[child2_parent].child1 = c1;
                else
                    tree[child2_parent].child2 = c1;
            }
            // 알림을 받을 수 있는 채팅방 수 조회
            else if(cmd == 500) {
                int num = sc.nextInt();
                if(num == 0) System.out.println(-1);
                else System.out.println(dfs(num, 0));
            }
        }
    }

    private static int dfs(int num, int depth) {
        int answer = 0;

        if(depth != 0 && tree[num].power >= depth) {
            answer++;
        }

        if(tree[num].child1 != -1 &&
                tree[tree[num].child1].alarm) {
            answer += dfs(tree[num].child1, depth+1);
        }

        if(tree[num].child2 != -1 &&
                tree[tree[num].child2].alarm) {
            answer += dfs(tree[num].child2, depth+1);
        }

        return answer;
    }

    private static void print_tree() {
        for(int i = 1 ; i <= N ; i++) {
            System.out.println(i +" 번 노드");
            System.out.println("부모 " + tree[i].parent);
            System.out.println("자식1 " + tree[i].child1);
            System.out.println("자식2 " + tree[i].child2);
        }
    }
}