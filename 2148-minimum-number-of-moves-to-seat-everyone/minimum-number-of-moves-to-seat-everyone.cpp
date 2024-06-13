class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int stu = 0;
        int sea = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i = 0;i<seats.size();i++)
        {
            stu+=abs(students[i] - seats[i]);
        }
        // return abs(stu-sea);
        return stu;
    }
};