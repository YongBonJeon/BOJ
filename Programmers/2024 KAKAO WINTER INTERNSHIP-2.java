import java.util.*;
class Solution {
    /*
        도넛 모양 : n , n
        막대 모양 : n, n-1
        8자 모양 : 2n+1, 2n+2
    */
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];

        int max = 0;
        for(int[] edge : edges) {
            max = Math.max(max, edge[0]);
            max = Math.max(max, edge[1]);
        }

        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0 ; i <= max ; i++)
            graph.add(new ArrayList<Integer>());

        int[][] check = new int[max+1][2];
        for(int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);

            check[edge[0]][0] += 1;
            check[edge[1]][1] += 1;
        }
        int[] visited = new int[max+1];

        int center = 0;
        for(int i = 1 ; i <= max ; i++) {
            if(check[i][1] == 0 && check[i][0] >= 2) {
                answer[0] = i;
                center = i;
            }
        }

        for(Integer i : graph.get(center))
            bfs(graph, i, visited, answer);
        return answer;
    }

    public void bfs(List<List<Integer>> graph, int start, int[] visited, int[] answer) {
        int num_vertex = 0;
        int num_edge = 0;

        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);

        while(!q.isEmpty()) {
            int cur = q.poll();

            visited[cur] = 1;

            num_vertex += 1;
            num_edge += graph.get(cur).size();
            for(Integer next : graph.get(cur)){
                if(visited[next] == 0)
                    q.add(next);
            }
        }
        /*
        도넛 모양 : n , n
        막대 모양 : n, n-1
        8자 모양 : 2n+1, 2n+2
        */
        // 모양 찾기
        if(num_vertex == visited.length-1){
            answer[0] = start;
            return ;
        }
        else if(num_edge == num_vertex) {
            answer[1] += 1;
        }  else if(num_vertex - num_edge == -1) {
            answer[3] += 1;
        } else
            answer[2] += 1;
    }
}