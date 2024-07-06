class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        long long int n = enemyEnergies.size();
        // vector<bool>check(n,false);
        long long int end = n-1;
        long long int points = 0;
        if(currentEnergy>=enemyEnergies[0])
        {
            currentEnergy=currentEnergy-enemyEnergies[0];
            points++;
        }
        long long int sum = currentEnergy;
        for(int i = 1;i<n;i++)
        {
            sum+=enemyEnergies[i];
        }
        if(points>0)
        {
            sum = sum/enemyEnergies[0];
            points += sum;
        }
        return points;
    }
};