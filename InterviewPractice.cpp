// InterviewPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <sstream>
#include <fstream>
#include <numeric>
#include <functional>
#include <set>

using namespace std;

// Link list node 
class node {
public:
    int data;
    node* next;
};

// Merging two sorted lists.
node* MergeSortedList(node* lst1, node* lst2)
{
    node* result = NULL;

    // Base Cases
    if (lst1 == NULL)
        return (lst2);
    else if (lst2 == NULL)
        return (lst1);

    // recursively merging two lists
    if (lst1->data <= lst2->data) {
        result = lst1;
        result->next = MergeSortedList(lst1->next, lst2);
    }
    else {
        result = lst2;
        result->next = MergeSortedList(lst1, lst2->next);
    }
    return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void SplitList(node* source, node** front, node** back)
{
    node* ptr1;
    node* ptr2;
    ptr2 = source;
    ptr1 = source->next;

    // ptr1 is incrmented twice and ptr2 is icremented once.
    while (ptr1 != NULL) {
        ptr1 = ptr1->next;
        if (ptr1 != NULL) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }

    // ptr2 is at the midpoint.
    *front = source;
    *back = ptr2->next;
    ptr2->next = NULL;
}


// Merge Sort
void MergeSort(node** thead)
{
    node* head = *thead;
    node* ptr1;
    node* ptr2;

    // Base Case
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Splitting list
    SplitList(head, &ptr1, &ptr2);

    // Recursively sorting two lists.
    MergeSort(&ptr1);
    MergeSort(&ptr2);

    // Sorted List.
    *thead = MergeSortedList(ptr1, ptr2);
}

void my_swap(node* node_1, node* node_2)
{
    int temp = node_1->data;
    node_1->data = node_2->data;
    node_2->data = temp;
}
void bubble_sort2(node* head)
{
    int swapped;

    node* lPtr; // left pointer will always point to the start of the list
    node* rPrt = NULL; // right pointer will always point to the end of the list
    do
    {
        swapped = 0;
        lPtr = head;
        while (lPtr->next != rPrt)
        {
            if (lPtr->data > lPtr->next->data)
            {
                my_swap(lPtr, lPtr->next);
                swapped = 1;
            }
            lPtr = lPtr->next;
        }
        //as the largest element is at the end of the list, assign that to rPtr as there is no need to
        //check already sorted list
        rPrt = lPtr;

    } while (swapped);
}

void recursive_sort(node* head)
{
    node* lPtr = head; // left pointer will always point to the start of the list
    if (lPtr->next == NULL) return;
    while (lPtr->next)
    {
        if (head->data > lPtr->next->data) swap(head->data, lPtr->next->data);
        lPtr = lPtr->next;           
    }    
    recursive_sort(head->next);
}




// Printing List.
void printList(node* tnode)
{
    while (tnode != NULL) {
        cout << tnode->data << " ";
        tnode = tnode->next;
    }
}

// Push function for inserting nodes in the list.
void push(node** thead, int new_data)
{
    node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*thead);
    (*thead) = new_node;
}

void makeListCircular(node* head)
{
    node* lPtr = head; // left pointer will always point to the start of the list
    while (lPtr->next) lPtr = lPtr->next;
    lPtr->next = head;    
}

bool isListCircular(node* head)
{
    node* lPtr = head; // left pointer will always point to the start of the list
    while (lPtr->next)
    {
        if (lPtr->next == head) return true;
        lPtr = lPtr->next;
    }
    return false;
}

bool isListCircular2(node* nodeP)
{
    unordered_set<node*> nodeS = { nodeP };
    while (nodeP->next)
    {
        if (!(nodeS.insert(nodeP->next)).second) return true;
        nodeP = nodeP->next;
    }
    return false;
}

bool isListCircular3(node* list)
{
    node* slow_p = list, * fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            cout << "Found Loop";
            return 1;
        }
    }
    return 0;
}

int minFlipToMakeStringAlternate(string s)
{
    int ss = s.size();
    int evenS = 0, oddS = 0;
    for (int i = 0; i < ss; i = i + 2)
    {
        evenS += s[i] - '0';
        if (!((ss % 2 == 1) && i == (ss - 1)))
            oddS += s[i + 1] - '0';
    }
    int flips1 = evenS + (ss / 2 - oddS); // even element is 0, odd is 1, 010
    int flips2 = oddS + ((ss+1) / 2 - evenS);

    // cout << "even " << evenS << " Odd " << oddS << endl;
    return min(flips1, flips2);
}

void print(std::string::size_type n, std::string const& s)
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    }
    else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}

void allPossibleSubset(int arr[], int n)
{
    int  count = pow(2, n);
    // The outer for loop will run 2^n times to print all subset .
    // Here variable i will act as a binary counter
    for (int i = 0; i < count; i++)
    {
        // The inner for loop will run n times , As the maximum number of elements a set can have is n
        // This loop will generate a subset
        for (int j = 0; j < n; j++)
        {
            // This if condition will check if jth bit in binary representation of  i  is set or not
            // if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
            // otherwise exclude arr[j]
            if ((i & (1 << j)) > 0)
                cout << arr[j] << " " << j << " " << (1 << j) << " " << i;
        }
        cout << "\n";
    }
}

void allPossibleSubset2(int arr[], int n)
{
    static vector<vector<int>> iVV;
    int iVVs = iVV.size();
    for (int i = 0; i < iVVs; ++i)
    {
        vector<int> temp(iVV.at(i));
        temp.push_back(arr[n - 1]);
        iVV.push_back(temp);
    }
    iVV.push_back(vector<int>{arr[n - 1]});
    if (n > 1) allPossibleSubset2(arr, n - 1);
    else
    {
        for (vector<int> iV : iVV)
        {
            for (int i : iV)
                cout << i << " ";
            cout << endl;
        }
        return;
    }
}

void allPossibleSubset3(int arr[], int n)
{
    vector<vector<int>> iVV;
    for (int j = 0; j < n; ++j)
    {
        int iVVs = iVV.size();
        for (int i = 0; i < iVVs; ++i)
        {
            vector<int> temp(iVV.at(i));
            temp.push_back(arr[j]);
            iVV.push_back(temp);
        }
        iVV.push_back(vector<int>{arr[j]});
    }
 
        for (vector<int> iV : iVV)
        {
            for (int i : iV)
                cout << i << " ";
            cout << endl;
        }
        return;
}

    // C++ code for linked list merged sort 


 


string reverse(string s)
{
    string rs;
    stack<char> cs;
    for (char c : s) cs.push(c);
    while (!cs.empty())
    {
        rs += cs.top();
        cs.pop();
    }
    return rs;
}

// Complete the substrCount function below.
long substrCount(int length, string s) {
    int counter = 0;
    vector<int> iV = { 0, 0, 0 }; // store indices where chars changes, initialized 3 zeros
    bool pallin = false;                                   // check for ..AABAA.. pattern
    for (int i = 0; i < length; ++i) {
        if (s[i] == s[i + 1] && (i + 1) < length) continue; // keep loop until new char
        int top = iV.size() - 1;    // last entry in iV store last char index
        int num = i + 1 - iV.at(top);  // number of chars, e.g. AAA is 3 
        counter += num * (num + 1) / 2; // number of substrings = 6 when num = 3
        int count1 = iV.at(top - 1) - iV.at(top - 2); // for AAAABAAA, count1 = 4
        if (pallin && s[i] == s[iV.at(top - 2)]) counter += min(num, count1); // 3 
        pallin = num == 1 && i > 0;         // true for 1 char, false otherwise
        iV.push_back(i + 1);                  // remember last index
    }
    return counter;
}

int factorial(int n)
{

    return ((n == 1) ? 1 : n * factorial(n - 1));
}

string getCodedString2(string s)
{
    char prev = s[0];
    stringstream output;
    string subS;
    for (char c : s)
    {
        if (c != prev)
        {
            if (subS.length() < 3) output << subS;
            else
                output << prev << '#' << subS.length();
            prev = c;
            subS = "";
        }
        subS.push_back(c);
    }
    if (subS.length() < 3) 
        output << subS;
    else
        output << prev << "#" << subS.length();
        
    return output.str();
}

string getCodedString4(string s)
{
    string output;
    int slen = s.length(), left = 0;
    for (int i = 0; i < slen; ++i)
    {
        if (s[i] == s[i + 1] && (i + 1) < slen) continue;
        int num = i + 1 - left;
        output += (num < 3) ? string(num, s[i]) : string(1, s[i]) + "#" + to_string(num);
        left = i+1;           
    }
    return output;
}

struct charCount { char a; int b; };
string getCodedString3(string s)
{
   
    vector<charCount> charCountV;
    stringstream output;
    char prev = s[0];
    int count = 0;
    for (char c : s)
    {
        if (c != prev)
        {
            charCount cc{ prev, count };
            charCountV.push_back(cc);
            count = 1;
            prev = c;
        }
        else
            ++count;
    }
    charCount cc{ prev, count };
    charCountV.push_back(cc);

    for (auto e : charCountV)
    {
        if (e.b < 3)
            output << std::string(e.b, e.a);
        else
            output << e.a << "#" << e.b;
    }
    return output.str();
}

string getCodedString(string s)
{
    char prev = s[0], count = 0;
    stringstream output;
    for (char c : s)
    {
        if (c != prev)
        {
            if (count == 1)
            {
                output <<  prev;
            }
            else if (count == 2)
            {
                output << prev << prev;
            }
            else
            {
                output << prev << '#' << to_string(count);
             }
            prev = c;
            count = 1;
        }
        else {
            ++count;
            }
    }
    if (count == 1)
    {
        output << prev;
    }
    else if (count == 2)
    {
        output << prev << prev;
    }
    else
    {
        output << prev << '#' << to_string(count);
    }

    string ss;
    output >> ss;
    return ss;
}
/* int main() {
    cout << getCodedString("ddddjjwwwwwrjjjkk");
    return 0;
} */

void mostPopulousChar(string s)
{
    map<char, int> x;
    for (char c : s) ++x[c];
    std::map<char, int>::iterator best = 
    max_element(x.begin(), x.end(), [](const pair<char, int>& a, const pair<char, int>& b)->bool { return a.second < b.second; });
    std::cout << best->first << " , " << best->second << "\n";

    int charCount[128] = { 0 }; // ascii chars
    for (char c : s) ++charCount[c];
    int *maxP = max_element(charCount, charCount + 128);
    cout << (char)(maxP - charCount) << " " <<  *maxP << endl;
    // distance(A, max_element(A, A + N))
}

void find2smallest(int n, int arr[])
{
    int s1 = min(arr[0], arr[1]); // smallest
    int s2 = max(arr[0], arr[1]); //  2 smallest
    for (int i = 2; i < n; ++i)
    {
        if (arr[i] < s1)
        {
            s2 = s1;
            s1 = arr[i];
        }
        else if (arr[i] < s2)
            s2 = arr[i];
        else;
    }
    cout << "Smallest " << s1 << " " << s2 << endl;
    sort(arr, arr + n, greater<int>());
    cout << "largeest " << arr[0] << " " << arr[1] << endl;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int vS = expenditure.size();
    std::vector<int>::iterator it;
    int count = 0;
    vector<int> subV(expenditure.begin(), expenditure.begin() + d);
    std::sort(subV.begin(), subV.end());

    for (int i = 0; i < vS - d; ++i)
    {
        float medium = subV[d / 2];
        if (d % 2 == 0)
        {
            medium += subV[d / 2 - 1];
            medium /= 2;
        }
        if (expenditure[i + d] >= (2 * medium)) ++count;
               
        it = lower_bound(subV.begin(), subV.end(), expenditure[i]);
        subV.erase(it, it + 1);
        it = lower_bound(subV.begin(), subV.end(), expenditure[i + d]);
        subV.insert(it, expenditure[i + d]);
    } 
    return count;
}

bool isPower10(long l)
{
    long seed = 1;
    while (true)
    {
        if (l == seed || l == seed * 10) return true;
        if (l > seed && l < seed * 10) return false;
        seed *= 10;
    }
}

int findMin(vector<int> intV)
{
    int size = intV.size();
    int sum = std::accumulate(intV.begin(), intV.end(), 0);
    for (int i = 0; i < size - 1; ++i)
        if (intV[i] > intV[i + 1]) return intV[i + 1];
    return 0; //  sum / size - size / 2;
}
/*
void firstNonRepeatingChar(char* s)
{
    int* count = new int[256];
    for (int i = 0; i < strlen(s); i++)
        count[s[i]]++; //increment the count of each character by using ASCII of character as key  
    for (int i = 0; i < strlen(s); i++)
        if (count[s[i]] == 1) //if count is 1, then print and break
        {
            cout << s[i] << " is the first non-repeating character " << endl;
            break;
        }
}
*/
char find1stNonRepeatChar(string s)
{
    vector<char> cV;
    vector<bool> bV;
    int firstIdx = 0;
    for (char c : s)
    {
        vector<char>::iterator ctr = find(cV.begin(), cV.end(), c);
        if (ctr == cV.end())
        {
            cV.push_back(c);
            bV.push_back(false);
            if (find(bV.begin(), bV.end(), false) == bV.end()) firstIdx = cV.size() - 1;
        }
        else
        {    
            int idx = distance(cV.begin(), ctr);
            bV[idx] = true;
            if (idx == firstIdx)
            {
                for (int i = idx; i < cV.size(); ++i)
                {
                    if (bV[i] == false)
                    {
                        firstIdx = i;
                        break;
                    }
                }
            }
        }
    }
    return cV[firstIdx];
}

// A comparison function which is used by sort() in printLargest() 
int myCompare(string X, string Y)
{
    // first append Y at the end of X 
    string XY = X.append(Y);

    // then append X at the end of Y 
    string YX = Y.append(X);

    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1 : 0;
}

long long getLargest(vector<int> arr)
{
    // Sort the numbers using library sort function.
    // Use Lambda for customized comparator 
    sort(arr.begin(), arr.end(), [](int const& X, int const& Y) {
        return (to_string(X) + to_string(Y)) > (to_string(Y) + to_string(X));
    });
    stringstream ss;    
    for (int i : arr) ss << i;
    return stoll(ss.str()); 
}

long long combination(long l, long j)
{
    long long l1 = l;
    for (long i = 1; i < j; ++i)
    {
        l1 = l1 * (l - i) / (i + 1);
        // cout << i << " " << l1 << endl;
    }
    // cout << "factorial " << l1;    
    return l1;
}
long long countTriplets(vector<long> arr, long r) {
    long long count = 0;
    
    map<long, long> m1;
    map<long, long> m2, eMap;
    for (const auto& e : arr) {
        count += m2[e];
        // cout << m2[e] << endl;
        m2[e * r] += m1[e];
        ++m1[e * r];
    }
/*
    for (auto e : arr)
    {
        if (e % r == 0)
        {
            ++eMap[e];
            int base = e / (r * r);
            if (base > 1) count += eMap[base] * eMap[base * r] * eMap[base * r * r];
        }
    }
 */   
    map<long, long> expM; // exponent map
   /* int j = 1;
    for (int i = 0; i < 5; ++i)
    {        
        expM[j] = i;
        j *= r;
    } 
    long a1[5] = { 0 }, a2[5] = { 0 };
    for (const auto& e : arr) {
        count += a2[expM[e]];
        // cout << m2[e] << endl;
        a2[expM[e]+(r > 1)] += a1[expM[e]];
        ++a1[expM[e] + (r > 1)];
    } */
    return count;

}

long long countTriplets2(vector<long> arr, long r) {
    long long count = 0;
    map<long long, long> expM, eMap; // exponent map
    // int j = 1;
    for (long i = 0, j = 1; i < 20; ++i, j *= r) expM[j] = i;
    long a1[20] = { 0 }, a2[20] = { 0 };
    long middle1 = 0, middle2 = 0;
    for (auto e : arr)
    {
        if (r == 1) ++eMap[e];
        else if (e == 1 || e % r == 0)
        {
            ++eMap[e];
            // int base = 1;
            /* int exp = 0, rtemp = 1;
            while (e / rtemp > 0)
            {
                rtemp *= r;
                ++exp;
            } */
            // base = e / rtemp;
            
            if (e == r)
            {
                ++middle1;
                ++middle2;
            }
            if (expM[e] >= 2)
            {
                count += (long long)eMap[e / r / r] * (long long)eMap[e / r];
                count -= (middle1 - middle2);
            }
            if (e == 1) middle2 = 0;
        }
        else;
    }
    if (r == 1)
    {
        count = 0;
        for (auto e : eMap) count += combination(e.second, 3);
    }
    return count;
}



int main()
{
    int sum = 0;
    int divisor = 3;
    vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    for_each(numbers.begin(), numbers.end(), [divisor, &sum](int y)
    {
        if (y % divisor == 0)
        {
            cout << y << endl;
            sum += y;
        }
    });

    cout << sum << endl;
    /*
            std::string::size_type n;
            std::string const s = "This is a string";

            // search from beginning of string
            n = s.find("is");
            print(n, s);

            // search from position 5
            n = s.find("is", 5);
            print(n, s);

            // find a single character
            n = s.find('a');
            print(n, s);

            // find a single character
            n = s.find('q');
            print(n, s);
            */
            // Array questions
    int arr[] = { 1,1,2,2,3,2,3,4,5,6,7,8,9,0,9,8,7,6,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;
    int maxE = *(std::max_element(arr, arr + k));
    printf("%d ", maxE);
    for (int i = 1; i <= (n - k); ++i)
    {
        if (arr[i - 1] == maxE)
            maxE = *(std::max_element(arr + i, arr + i + k));
        else if (arr[i + k - 1] > maxE)
            maxE = arr[i + k - 1];
        else;
        printf("%d ", maxE);
    }
    printf("\n");

    // using deque

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        // base case for first element
        if (dq.empty()) {
            dq.push_back(i);
        }
        // remove elements outside the current window
        if (dq.front() <= (i - k)) {
            dq.pop_front();
        }
        // move max element to the front
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // print out only when the first window is completed

        if (i >= (k - 1)) {
            cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
    unordered_set<int> iSet(arr, arr + n);
    int sSize = iSet.size();
    int minS = n;
    int j = 0;
    
    for (int i = sSize; i < n; ++i)
    {
        // if (iSet1.find(arr[i]) == iSet1.end()) iSet1.insert(arr[i]);
        unordered_set<int> iSet1(arr+j, arr + i);
        if (iSet1.size() < sSize) continue;
        else
        {
            while (iSet1.size() == sSize)
            {
                if ((i - j) < minS) minS = i - j;
                ++j;
                iSet1.clear();
                for (int k = j; k < i; ++k) iSet1.insert(arr[k]);
            }
        }
    }

    cout << "min array size " << minS << endl;
    // Longest sub-array of 2 different elements, at least 2 elements
    int maxS = 0;
    k = 2;
    j = 0;
    for (int i = 2; i < n; ++i)
    {
        unordered_set<int> iSet2(arr + j, arr + i);
        if (iSet2.size() <= k) 
        {
            if ((i - j) > maxS) maxS = i - j;
            continue;
        }
        else
        {
            while (iSet2.size() > k)
            {
                ++j;
                iSet2.clear();
                for (int l = j; l < i; ++l) iSet2.insert(arr[j]);
            }
        }
    }
    cout << " max window with 2 different elements " << maxS << endl;

    string sA[] = { "B", "B", "Y", "Y", "B", "B", "W", "W", "B" };
    map<string, int> sMap;
    for (auto s : sA)
    {
        sMap[s] = sMap[s] + 1;
    }
    int count = 0;
    for (auto entry : sMap) count += entry.second / 2;
    cout << "number of socks " << count << endl;

    string sA2[] = { "ABC", "DEF", "XYZ" };
    string sLong("ABC DEF XYZ");
    stringstream sts(sLong);
    stack<string> ss;
    while (!sts.eof())
    {
        string stemp;
        sts >> stemp;

        ss.push(stemp);
        cout << stemp << endl;
    }
    
    // for (auto s : sA2) ss.push(s);
    string res;
    while (!ss.empty())
    {
        string str = ss.top();
        string rev = reverse(str);
        res += rev + " ";
        ss.pop();
    }
    cout << "Reverse word/string " << res << endl;

    cout << " 5 factorial = " << factorial(5) << endl;
    sort(arr, arr + n, greater<int>());
    cout << "Second large " << arr[1] << endl;
    list<int> iList(std::begin(arr), std::end(arr));

    cout << getCodedString4("ddddjjwwwwwrjjjkk") << endl;

    int inputCount = 55269;

     ifstream src("input.txt");
    if (!src)
    {
        perror("Error opening file ");
        system("pause");
        return -1;
    }
    string line;
    while (getline(src, line))
    {
        // use line
        cout << line.length() << "\n";
    }
    cout << "substring count " << substrCount(inputCount, line) << endl;

    // most popular char
    mostPopulousChar(line);

    ifstream src2("input3.txt");
    if (!src2)
    {
        perror("Error opening file ");
        system("pause");
        return -1;
    }
    int inp; 
    vector<int> inpV;
    int icount = 0;
    while (src2 >> inp)
    {
        inpV.push_back(inp);
        ++icount;
       // if (icount == 20000) break;
    }

    cout << "Notify " << activityNotifications(inpV, 9999) << endl;

    ifstream src3("input10.txt");
    if (!src3)
    {
        perror("Error opening file ");
        system("pause");
        return -1;
    }
    
    vector<long> longV;
    
    while (src3 >> inp)
    {
        longV.push_back(inp);
        
        // if (icount == 20000) break;
    }
    
    cout << "count triplets " << countTriplets(longV, 10) << endl;
    // cout << "count triplets " << countTriplets2(longV, 10) << endl;
   //  cout << "Input size " << inpV.size();
    int arr2[] = { 2,4,5,66,77,1,-99,4,7,64,34,677,9 };
    find2smallest(13, arr2);


    int arr3[4] = { 1, 2, 3, 4 };
   // allPossibleSubset(arr3, 4);
    allPossibleSubset3(arr3, 4);
    // Driver Program.

     // Empty list
   // node* res = NULL;
    node* MyList = NULL;

    // List: 10->4->15->1->2->12->54
    push(&MyList, 54);
    push(&MyList, 12);
    push(&MyList, 2);
    push(&MyList, 1);
    push(&MyList, 15);
    push(&MyList, 4);
    push(&MyList, 10);

    cout << "Unsorted Linked List: ";
    printList(MyList);
    cout << "\n";

    // MergeSort(&MyList);
   // bubble_sort2(MyList);
    recursive_sort(MyList);
    cout << "Sorted Linked List: ";
    printList(MyList);
    cout << endl;
    makeListCircular(MyList);

    cout << "Circular list " << isListCircular(MyList) << " " << isListCircular2(MyList) << " " << isListCircular3(MyList) << endl;

    cout << "3 power 10 " << isPower10(3) << endl;
    cout << "1 power 10 " << isPower10(1) << endl; 
    cout << "100 power 10 " << isPower10(100) << endl;
    cout << "300 power 10 " << isPower10(300) << endl;
    cout << "100000000001 power 10 " << isPower10(100000000001) << endl;

    cout << "min " << findMin({ 5,1,2,3,4 }) << endl;

    string s = "tutorialcuporialc";
    cout << find1stNonRepeatChar(s) << endl;

    vector<int> intA = { 1, 34, 3, 98, 9, 76, 45, 4 };
    cout << "Largest number " << getLargest(intA) << endl;

    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str) << endl; 

    cout << " 1 > 1 " << (1 > 1) << " 2 == 1 " << (2 == 1) << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
