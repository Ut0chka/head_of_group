#include <iostream>
#include "main.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "");
    // ���� ���������� ����������
    int numCandidates;
    cout << "������� ���������� ����������: ";
    cin >> numCandidates;

    // ���� ��� ����������
    vector<Candidate> candidates;
    for (int i = 0; i < numCandidates; i++) {
        string name;
        cout << "������� ��� ��������� #" << i + 1 << ": ";
        cin >> name;
        candidates.push_back(Candidate(name));
    }

    // ���������� �����������
    listCandidates(candidates); 
    vote(candidates);
    sortCandidates(candidates);
    resultsVote(candidates, out);

    return 0;
}