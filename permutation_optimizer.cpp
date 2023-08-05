int generatePermutations(vector<vector<int>>& cost, int n)
{
    vector<int> bestConfiguration(n, -1);
    int bestCost = INT_MAX;

    vector<int> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = i;
    }
    int configurationId = 1;

    do
    {
        int tempCost = 0;
        for (int i = 0; i < n; i++)
        {
            tempCost += cost[i][jobs[i]];
        }
        cout << "Configuration Number: " << configurationId << "\n";
        cout << "\t";
        for (int i = 0; i < n; i++)
        {
            cout << jobs[i] + 1 << " \n"[i + 1 == n];
        }
        cout << "\tCost: " << tempCost << "\n";

        if (tempCost < bestCost)
        {
            bestCost = tempCost;
            bestConfiguration = jobs;
        }
        configurationId += 1;
    } while (next_permutation(begin(jobs), end(jobs)));


    cout << "\nBest Configuration: \n";
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << bestConfiguration[i] + 1 << " \n"[i + 1 == n];
    }
    cout << "\tMinimum Cost: " << bestCost << "\n";

    return bestCost;
}
