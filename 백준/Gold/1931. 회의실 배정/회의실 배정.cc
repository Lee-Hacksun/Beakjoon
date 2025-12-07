#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int value[10];

int main()
{
	int N;

	vector<pair<int, int>> meeting;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int start;
		int end;

		cin >> start >> end;
		meeting.push_back(make_pair(end, start));
	}

	sort(meeting.begin(), meeting.end());

	int time = meeting[0].first;
	int count = 1;
	for (int i = 1; i < N; i++)
	{
		if (time <= meeting[i].second)
		{
			count++;
			time = meeting[i].first;
		}
	}

	cout << count;
}