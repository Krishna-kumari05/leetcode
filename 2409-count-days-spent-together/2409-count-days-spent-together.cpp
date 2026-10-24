class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int a = 0, b = 0, c = 0, d = 0;

        string dates[] = {arriveAlice, leaveAlice, arriveBob, leaveBob};
        int result[4];

        for (int j = 0; j < 4; j++) {
            int month = stoi(dates[j].substr(0, 2));
            int day = stoi(dates[j].substr(3, 2));

            for (int i = 0; i < month - 1; i++) {
                day += days[i];
            }

            result[j] = day;
        }

        a = result[0];
        b = result[1];
        c = result[2];
        d = result[3];

        int start = max(a, c);
        int end = min(b, d);

        if (start > end)
            return 0;

        return end - start + 1;
    }
};