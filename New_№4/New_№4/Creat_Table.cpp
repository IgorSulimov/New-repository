#include "Creat_Table.hpp"

int OOO = 0;
void Parser::buildPrecedenceTable(vector<Start_End> start_end, vector<F> FIRST)
{
    const set <string>& terms = grammar.getTerminals();

    const set<string>& nonTerms = grammar.getNonTerminals();

    int fl_$ = 1;

    set<string> allSymbols = terms;
    allSymbols.insert(nonTerms.begin(), nonTerms.end());
    allSymbols.insert("$");


    for (const string& a : allSymbols) {
        for (const string& b : allSymbols) {
            precedenceTable[{a, b}] = '.';
        }
    }

    for (const GrammarRule& rule : grammar.getRules())
    {
        const vector<string>& right = rule.right;
        const size_t n = right.size();
        string left = rule.left;
        // ���������� $ ------------
        if (fl_$)
        {
            int i = 0;
            for (i; left != start_end[i].nonTerminals; i++)
            {
            }
            for (int k = 0; k < start_end[i].Start.size(); k++)
            {
                precedenceTable[{"$", start_end[i].Start[k] }] = '<';
            }
            for (int d = 0; d < start_end[i].End.size(); d++)
            {
                precedenceTable[{start_end[i].End[d], "$" }] = '>';
            }
            fl_$ = 0;
        }
        for (int i = 0; i < n; i++)
        {
            const string& curr = right[i];
            bool currIsTerm = terms.count(curr);
            // = +++++++++
            if (i + 1 < n)
            {
                const string& next = right[i + 1];
                bool nextIsTerm = terms.count(next);
                precedenceTable[{curr, next}] = '=';
            }
        }
    }
    for (const GrammarRule& rule : grammar.getRules()) {
        const vector<string>& right = rule.right;
        string left = rule.left;
        const size_t n = right.size();
        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0)
            {
                const string& a = right[i - 1];
                const string& x = right[i];
                //// < ++++++++++++
                if (terms.count(a) && nonTerms.count(x))
                {
                    int i = 0;
                    while (x != start_end[i].nonTerminals)
                    {
                        i++;
                    }
                    for (int k = 0; k < start_end[i].Start.size(); k++)
                    {
                        if (precedenceTable[{a, start_end[i].Start[k]}] != ('.') && precedenceTable[{a, start_end[i].Start[k]}] != ('<'))
                        {
                            cout << OOO << "������ � ������� �������: " << a << "," << start_end[i].Start[k] << "||" << precedenceTable[{a, start_end[i].Start[k]}] << ",<" << endl;
                            OOO++;
                        }
                        else
                        {
                            precedenceTable[{a, start_end[i].Start[k]}] = '<';
                        }
                    }
                }
                if (nonTerms.count(a) && nonTerms.count(x))
                {
                    int i = 0;
                    while (x != start_end[i].nonTerminals)
                    {
                        i++;
                    }
                    for (int k = 0; k < start_end[i].Start.size(); k++)
                    {
                        if (precedenceTable[{a, start_end[i].Start[k]}] != ('.') && precedenceTable[{a, start_end[i].Start[k]}] != ('<'))
                        {
                            cout << OOO << "������ � ������� �������: " << a << "," << start_end[i].Start[k] << "||" << precedenceTable[{a, start_end[i].Start[k]}] << ",<" << endl;
                            OOO++;
                        }
                        else
                        {
                            precedenceTable[{a, start_end[i].Start[k]}] = '<';
                        }
                    }
                }


                // >
                if (nonTerms.count(a) && terms.count(x))
                {
                    int i = 0;
                    while (a != start_end[i].nonTerminals)
                    {
                        i++;
                    }
                    for (int k = 0; k < start_end[i].End.size(); k++)
                    {
                        if (precedenceTable[{start_end[i].End[k], x}] != ('.') && precedenceTable[{start_end[i].End[k], x}] != ('>'))
                        {
                            cout << OOO << "������ � ������� �������: " << start_end[i].End[k] << "," << x << "||" << precedenceTable[{start_end[i].End[k], x}] << ",>" << endl;
                            OOO++;
                        }
                        else
                        {
                            precedenceTable[{start_end[i].End[k], x}] = '>';
                        }
                    }
                }
                if (nonTerms.count(a) && nonTerms.count(x))
                {
                    int i = 0;
                    int p = 0;
                    while (a != start_end[i].nonTerminals)
                    {
                        i++;
                    }
                    while (x != FIRST[p].NonTerm)
                    {
                        p++;
                    }
                    for (int k = 0; k < start_end[i].End.size(); k++)
                    {
                        for (int l = 0; l < FIRST[p].Terms.size(); l++)
                        {
                            if (precedenceTable[{start_end[i].End[k], FIRST[p].Terms[l]}] != ('.') && precedenceTable[{start_end[i].End[k], FIRST[p].Terms[l]}] != ('>'))
                            {
                                cout << OOO << "������ � ������� �������: " << start_end[i].End[k] << "," << FIRST[p].Terms[l] << "||" << precedenceTable[{start_end[i].End[k], FIRST[p].Terms[l]}] << ",>" << endl;
                                OOO++;
                            }
                            else
                            {
                                precedenceTable[{start_end[i].End[k], FIRST[p].Terms[l]}] = '>';
                            }
                        }
                    }
                }
            }
        }
    }
}
// ������� ��� ������ ������ ����� ��������
void Parser::findDirectLeftRecursion(const Grammar& grammar)
{
    cout << "\n�������� �� ������ ����� ��������:\n";
    bool found = false;

    for (const GrammarRule& rule : grammar.getRules()) {
        if (!rule.right.empty() && rule.left == rule.right[0]) {
            cout << "������� ������ ����� ��������: "
                << rule.left << " -> " << rule.right[0] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "������ ����� �������� �� ����������.\n";
    }
}

// ������� ��� ������ ��������� ����� ��������
void Parser::findIndirectLeftRecursion(Grammar grammar) {
    cout << "\n�������� �� ��������� ����� ��������:\n";
    vector<string> nonTerms = grammar.GET_NON();
    map<string, set<string>> firstSymbols;
    bool found = false;

    // �������������
    for (const string& nt : nonTerms) {
        firstSymbols[nt] = {};
    }

    // ������� ������ ������� ��� ������� �����������
    for (const GrammarRule& rule : grammar.getRules()) {
        if (!rule.right.empty()) {
            firstSymbols[rule.left].insert(rule.right[0]);
        }
    }

    // ��������� �� ��������� ��������
    for (const string& A : nonTerms) {
        stack<string> stack;
        set<string> visited;

        stack.push(A);
        visited.insert(A);

        while (!stack.empty()) {
            string current = stack.top();
            stack.pop();

            for (const string& B : firstSymbols[current]) {
                if (grammar.getNonTerminals().count(B)) {
                    if (B == A) {
                        cout << "������� ��������� ����� ��������: "
                            << A << " -> ... -> " << B << endl;
                        found = true;
                    }
                    if (visited.count(B) == 0) {
                        visited.insert(B);
                        stack.push(B);
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "��������� ����� �������� �� ����������.\n";
    }
}

// ������� ��� ������ e-������
void Parser::findEpsilonRules(const Grammar& grammar) {
    cout << "\n����� e-������:\n";
    bool found = false;

    for (const GrammarRule& rule : grammar.getRules()) {
        if (rule.right.empty() || (rule.right.size() == 1 && rule.right[0] == "e")) {
            cout << "������� e-�������: " << rule.left << " -> e" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "e-������ �� ����������.\n";
    }
}
//������������ �����������
void Parser::findUnreachableNonTerminals(Grammar grammar)
{
    const vector<GrammarRule>& rules = grammar.getRules();
    const set<string>& nonTerms = grammar.getNonTerminals();
    const set<string>& terms = grammar.getTerminals();

    set<string> reachable;
    stack<string> toProcess;

    // �������� � ���������� ������� (������� ����������� � ��������)
    string startSymbol = rules[0].left;
    reachable.insert(startSymbol);
    toProcess.push(startSymbol);

    // ������� ��� ���������� �����������
    while (!toProcess.empty()) {
        string current = toProcess.top();
        toProcess.pop();

        for (const GrammarRule& rule : rules) {
            if (rule.left == current) {
                for (const string& symbol : rule.right) {
                    if (nonTerms.count(symbol) && !reachable.count(symbol)) {
                        reachable.insert(symbol);
                        toProcess.push(symbol);
                    }
                }
            }
        }
    }

    // ������� ������������ �����������
    vector<string> unreachable;
    for (const string& nt : nonTerms) {
        if (!reachable.count(nt)) {
            unreachable.push_back(nt);
        }
    }

    // ������� ���������
    if (unreachable.empty()) {
        cout << "������������ ������������ ���." << endl;
    }
    else {
        cout << "������������ �����������: ";
        for (const string& nt : unreachable) {
            cout << nt << " ";
        }
        cout << endl;
    }
}
int Check_rep(vector<string> vec, string str)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == str)
        {
            return 0;
        }
    }
    return 1;
}
void Parser::printPrecedenceTable()
{
    vector<string> allSymbols;
    vector<string> allSymbols2 = grammar.GET_TR();
    allSymbols = (grammar.GET_NON());
    for (int i = 0; i < allSymbols2.size(); i++)
    {
        allSymbols.push_back(allSymbols2[i]);
    }
    allSymbols.push_back("$");
    const int colWidth = 12;

    cout << "\n�������:\n";
    cout << string(colWidth, ' ');
    for (const string& colSymbol : allSymbols) {
        cout << setw(colWidth) << colSymbol;
    }
    cout << endl;


    for (const string& rowSymbol : allSymbols) {
        cout << setw(colWidth) << rowSymbol;

        for (const string& colSymbol : allSymbols) {
            pair<string, string> key = { rowSymbol, colSymbol };
            char relation = ' ';

            if (precedenceTable.count(key)) {
                relation = precedenceTable[key];
            }

            cout << setw(colWidth) << relation;
        }
        cout << endl;
    }
}
void Grammar::addRule(const string& left, const vector<string>& right)
{
    rules.emplace_back(left, right);
    nonTerminals.insert(left);
    if (Check_rep(ALL_SYM, left))
        ALL_SYM.push_back(left);
    if (Check_rep(nonTermss, left))
        nonTermss.push_back(left);
    for (const auto& sym : right) {
        if (sym[0] != '<' || sym[sym.size() - 1] != '>')
        {
            terminals.insert(sym);
            if (Check_rep(ALL_SYM, sym))
                ALL_SYM.push_back(sym);
            if (Check_rep(termss, sym))
                termss.push_back(sym);
        }
    }
}
Grammar Grammar::readGrammarFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    Grammar grammar;
    string line;


    while (getline(file, line)) {
        size_t arrowPos = line.find("->");
        if (arrowPos == string::npos) {
            continue;
        }

        string left = line.substr(0, arrowPos);

        left.erase(remove_if(left.begin(), left.end(), ::isspace), left.end());

        string rightPart = line.substr(arrowPos + 2);
        vector<string> right;

        size_t start = 0;
        size_t end = rightPart.find(' ');
        while (end != string::npos) {
            string symbol = rightPart.substr(start, end - start);
            if (!symbol.empty()) {
                right.push_back(symbol);
            }
            start = end + 1;
            end = rightPart.find(' ', start);
        }

        string lastSymbol = rightPart.substr(start);
        if (!lastSymbol.empty()) {
            right.push_back(lastSymbol);
        }

        grammar.addRule(left, right);
    }
    return grammar;
}
//������� ��������� ��� � ��� ���� �� ����������
vector<Start_End> Set_Start_End(Grammar grammar)
{
    const set<string>& terms = grammar.getTerminals();
    const set<string>& nonTerms = grammar.getNonTerminals();
    vector<Start_End> start_end;
    // ����, ������� ����������� ��� ��� ������� ��� ������ � ������ �����������, ����� ���������
    for (const GrammarRule& rule : grammar.getRules())
    {
        const vector<string>& right = rule.right;
        string left = rule.left;
        int i = 0;
        int fl = 0;
        // �������� �� ��, ���� �� ���������� ��� � ������� start_end  
        for (i; i < start_end.size(); i++)
        {
            if (left == start_end[i].nonTerminals)
            {
                if (Check_rep(start_end[i].Start, right[0]))
                    start_end[i].Start.push_back(right[0]);
                if (Check_rep(start_end[i].End, right[right.size() - 1]))
                    start_end[i].End.push_back(right[right.size() - 1]);
                fl = 1;
            }
        }
        if (fl == 0)
        {
            start_end.resize(start_end.size() + 1);
            start_end[i].nonTerminals = rule.left;
            start_end[i].Start.push_back(right[0]);
            start_end[i].End.push_back(right[right.size() - 1]);
        }
    }
    //����, ������� ��������� ��� ��� � ������� �������������
    for (int i = 0; i < start_end.size(); i++)
    {
        for (int k = 0; k < start_end[i].Start.size(); k++)
        {
            if (nonTerms.count(start_end[i].Start[k]))
            {
                int p = 0;
                for (p; start_end[p].nonTerminals != start_end[i].Start[k]; p++);
                for (int l = 0; l < start_end[p].Start.size(); l++)
                {
                    if (Check_rep(start_end[i].Start, start_end[p].Start[l]))
                    {
                        start_end[i].Start.push_back(start_end[p].Start[l]);
                    }
                }
            }
        }

    }
    for (int i = 0; i < start_end.size(); i++)
    {
        for (int k = 0; k < start_end[i].End.size(); k++)
        {
            if (nonTerms.count(start_end[i].End[k]))
            {
                int p = 0;
                for (p; start_end[p].nonTerminals != start_end[i].End[k]; p++);
                for (int l = 0; l < start_end[p].End.size(); l++)
                {
                    if (Check_rep(start_end[i].End, start_end[p].End[l]))
                    {
                        start_end[i].End.push_back(start_end[p].End[l]);
                    }
                }
            }
        }

    }
    return start_end;
}
vector<F> Find_FIRST(vector<F> FIRST, vector<Start_End> SE, Grammar grammar)
{
    const set<string>& terms = grammar.getTerminals();

    for (int i = 0; i < SE.size(); i++)
    {
        FIRST.resize(FIRST.size() + 1);
        FIRST[i].NonTerm = SE[i].nonTerminals;
        for (int p = 0; p < SE[i].Start.size(); p++)
        {
            if (terms.count(SE[i].Start[p]))
            {
                FIRST[i].Terms.push_back(SE[i].Start[p]);
            }
        }
    }
    return FIRST;
}
void Print_Term(Grammar grammar)
{
    const set<string>& terms = grammar.getTerminals();
    cout << "\n���������:" << endl;
    for (auto it = terms.begin(); it != terms.end(); ++it) cout << *it << " ";
    cout << endl;
}
void Print_NonTerm(Grammar grammar)
{
    const set<string>& Nterms = grammar.getNonTerminals();
    cout << "\n�����������" << endl;
    for (auto it = Nterms.begin(); it != Nterms.end(); ++it) cout << *it << "\n";
    cout << endl;
}
void Print_FIRST(vector<F> FIRST)
{
    cout << '\n' << "FIRST" << endl;
    for (int i = 0; i < FIRST.size(); i++)
    {
        cout << FIRST[i].NonTerm << ":";
        for (int p = 0; p < FIRST[i].Terms.size(); p++)
        {
            cout << FIRST[i].Terms[p] << "|";
        }
        cout << endl;
    }
}
void Print_SE(vector<Start_End> SE, Grammar grammar)
{
    cout << endl;
    cout << "��� � ���" << endl;
    int i = grammar.getNonTerminals().size();
    for (int p = 0; p < i; p++)
    {
        cout << SE[p].nonTerminals;
        cout << setw(5) << "{";
        for (int i = 0; i < SE[p].Start.size(); i++)
            cout << SE[p].Start[i] << "|";
        cout << "}" << setw(5) << "{";
        for (int i = 0; i < SE[p].End.size(); i++)
            cout << SE[p].End[i] << "|";
        cout << "}" << endl;
    }
}