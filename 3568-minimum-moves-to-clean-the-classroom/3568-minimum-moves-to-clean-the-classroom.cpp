class Solution {
public:

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        // litterId[i][j] = which litter is present at (i,j)
        // -1 means this cell is not litter
        vector<vector<int>> litterId(
            m, vector<int>(n, -1)
        );

        int startX = 0;
        int startY = 0;

        int litterCount = 0;

        // Find starting position and assign IDs to litter
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {

                    startX = i;
                    startY = j;
                }

                else if (classroom[i][j] == 'L') {

                    litterId[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0) {
            return 0;
        }

        // All litter collected
        int targetMask = (1 << litterCount) - 1;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        queue<tuple<int,int,int,int>> q;

        // row, col, energy, mask
        q.push({
            startX,
            startY,
            energy,
            0
        });

        visited[startX][startY][energy][0] = true;

        int moves = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [x, y, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == targetMask) {
                    return moves;
                }

                // If energy is 0, we cannot move
                if (currEnergy == 0) {
                    continue;
                }

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Outside grid
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nx][ny] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy
                    int newEnergy = currEnergy - 1;

                    // If we reach reset area
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // If we reach litter
                    if (classroom[nx][ny] == 'L') {

                        int id = litterId[nx][ny];

                        newMask = newMask | (1 << id);
                    }

                    // New state
                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};