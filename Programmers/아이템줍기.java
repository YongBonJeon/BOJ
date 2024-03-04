import java.util.*;
import java.awt.*;

class Solution {

    int[][] map;
    int[][] dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int[][] visited;

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;

        map = new int[102][102];

        for(int i = 0 ; i < rectangle.length; i++) {
            int x1 = rectangle[i][0]*2;
            int y1 = rectangle[i][1]*2;
            int x2 = rectangle[i][2]*2;
            int y2 = rectangle[i][3]*2;

            for(int y = y1+1 ; y < y2 ; y++) {
                for(int x = x1+1 ; x < x2 ; x++) {
                    map[y][x] = 2;
                }
            }

            for(int x = x1 ; x <= x2 ; x++)
                if(map[y1][x] != 2)
                    map[y1][x] = 1;
            for(int x = x1 ; x <= x2 ; x++)
                if(map[y2][x] != 2)
                    map[y2][x] = 1;
            for(int y = y1 ; y <= y2 ; y++)
                if(map[y][x1] != 2)
                    map[y][x1] = 1;
            for(int y = y1 ; y <= y2 ; y++)
                if(map[y][x2] != 2)
                    map[y][x2] = 1;
        }


        return bfs(characterY*2, characterX*2, itemY*2, itemX*2)/2;
    }

    private int bfs(int y, int x, int targety, int targetx) {
        visited = new int[102][102];

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x,y));
        visited[y][x] = 1;

        while(!q.isEmpty()) {
            Point cur = q.poll();

            if(cur.y == targety && cur.x == targetx)
                return visited[cur.y][cur.x];

            for(int i = 0 ; i < 4 ; i++ ){
                int ny = cur.y + dir[i][0];
                int nx = cur.x + dir[i][1];

                if(nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
                if(visited[ny][nx] == 0 && map[ny][nx] == 1) {
                    q.add(new Point(nx, ny));
                    visited[ny][nx] = visited[cur.y][cur.x] + 1;
                }
            }
        }
        return -1;

    }
}