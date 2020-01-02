

void Game::prepareRoundFive() {

    ifstream fileRoundFive("/home/michal/CLionProjects/langGame/roundFive.txt");
    if (fileRoundFive.is_open()) {

        for (int i = 0; i < 40; ++i) {
            fileRoundFive >> myArrayRoundFive[i];
        }
    }
    fileRoundFive.close();
}




case 0:
//        while (points < 41 && minusPoints < 11) {
//            if (minusPoints == 10) {
//                break;
//            }
string sentence;
string rightAnswer;
string answerTwo;
string answerThree;
vector <string> zdania;
string tab[3];


for (
int i = 1;
i < 121;
i = i + 4
) {
sentence = fourthRoundSentences[i - 1];

rightAnswer = fourthRoundSentences[i];
answerTwo = fourthRoundSentences[i + 1];
answerThree = fourthRoundSentences[i + 2];

tab[0] =
rightAnswer;
tab[1] =
answerThree;
tab[2] =
answerTwo;

zdania.
push_back(sentence);
cout << "\n" <<
sentence;
cout << "\n" << answerThree << " " << rightAnswer << " " << answerTwo << " " <<
endl;

cout <<
rightAnswer;