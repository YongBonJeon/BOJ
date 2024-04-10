import java.util.*;

public class Main {
    static int Q, N, jIdx = 1;
    static Task[] judger;
    static PriorityQueue<Task> waitQ;
    static Map<String, Boolean> checkJudger = new HashMap<>();
    static Map<String, Boolean> checkQueue = new HashMap<>();
    static Map<String, History> checkHistory = new HashMap<>();

    static class Task {
        int prior;
        int time;
        String url;

        Task(int p, int t, String u) {
            this.prior = p;
            this.time = t;
            this.url = u;
        }
    }

    static class History {
        int start;
        int gap;

        History(int s, int g) {
            this.start = s;
            this.gap = g;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Q = sc.nextInt();

        waitQ = new PriorityQueue<>((o1, o2) -> {
            if(o1.prior != o2.prior)
                return o1.prior - o2.prior;
            else
                return o1.time - o2.time;
        });

        while(Q-- > 0){
            int cmd = sc.nextInt();
            int time, prior, num;
            String url;

            // 코드트리 채점기 준비
            if(cmd == 100) {
                N = sc.nextInt();

                // N개 채점기
                judger = new Task[N+1];

                // 초기 채점 요청 채점 대기 큐에 추가
                url = sc.next();
                waitQ.add(new Task(1, 0, url));
            }
            // 채점 요청
            else if(cmd == 200) {
                time = sc.nextInt();
                prior = sc.nextInt();
                url = sc.next();

                // t초에 우선순위가 p인 url 채점 대기 큐에 추가
                if(!checkQueue.getOrDefault(url, false)) {
                    //System.out.println(url + " 채점 대기 큐에 추가 ");
                    waitQ.add(new Task(prior, time, url));
                    checkQueue.put(url, true);
                }
            }
            // 채점 시도
            else if(cmd == 300) {
                time = sc.nextInt();

                Queue<Task> q = new ArrayDeque<>();
                // t초에 채점 대기 큐에서 즉시 채점이 가능한 경우
                // 우선순위가 가장 높은 채점 task 채점
                while(!waitQ.isEmpty()) {
                    boolean ok = true;
                    Task cur = waitQ.poll();

                    // 도메인이 이미 채점중이라면 불가
                    if(checkJudger.getOrDefault(getDomain(cur.url), false)) {
                        //System.out.println(cur.url + "채점 중이라 불가 ");
                        ok = false;
                    }
                    // 가장 최근에 채점된 시간 비교 해서 불가
                    History h = checkHistory.get(getDomain(cur.url));
                    if(h != null){
                        if(time < h.start + h.gap*3) {
                            //System.out.println(cur.url + "시간 만족 X이라 불가 " + time + " " + (h.start + h.gap*3));
                            ok = false;
                        }
                    }

                    // 채점 불가
                    if(!ok) {
                        q.add(cur);
                    }
                    // 채점 가능 쉬고 있는 채점기 중 가장 번호가 작은 채점기
                    else {
                        cur.time = time;
                        judger[jIdx] = cur;
                        //System.out.println(jIdx + " 채점기 " + cur.url);
                        checkJudger.put(getDomain(cur.url), true);
                        checkQueue.put(cur.url, false);

                        while(jIdx < N && judger[jIdx] != null) {
                            jIdx++;
                        }
                        break;
                    }
                }
                while(!q.isEmpty())
                    waitQ.add(q.poll());
            }
            // 채점 종료
            else if(cmd == 400) {
                time = sc.nextInt();
                num = sc.nextInt();

                // t초에 num번 채점기가 진행하던 채점 종료
                Task cur = judger[num];
                if(cur != null) {
                    checkJudger.put(getDomain(cur.url), false);
                    checkHistory.put(getDomain(cur.url), new History(cur.time, time - cur.time));
                    jIdx = Math.min(jIdx, num);
                    //System.out.println(num + " 번 채점기 종료 " + cur.url);
                }
            }
            // 채점 대기 큐 조회
            else if(cmd == 500) {
                time = sc.nextInt();

                // t초에 채점 대기 큐에 있는 채점 tasks 수 출력
                System.out.println(waitQ.size());
            }
        }
    }

    private static String getDomain(String url) {
        return url.split("/")[0];
    }
}