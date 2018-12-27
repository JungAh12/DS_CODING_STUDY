class ThePalindrome {
public: int find(string s)
{
	int i = 0;
	for (i = 0; i < s.size();) {
		int a = s.at(i);  //첫번째 문자
		int b = s.at(s.size() - 1 - i);   //끝문자
		if (a != b && b != ' ' && (i< s.size() - 1 - i))  //둘이 다르면(추가된 글자는 비교대상과 항상 같고, i와 size는 cross될 수 없음)
		{
			i = 0;
			s.push_back(' ');
			continue;
		}
		i++;
	}
	return i;
}
};
